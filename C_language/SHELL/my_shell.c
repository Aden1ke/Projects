#include "main.h"

int main(void) {
	char *line = NULL; // Pointer to hold the input line
	size_t len = 0;    // Variable to hold the size of the line
	ssize_t read;      // Variable to store the return value of getline
	char *token;
	char *argv[100];
	const char delim[] = " ";
	int i;

	while (1) { // Loop indefinitely
		// // Print the prompt
		printf("$ ");
		fflush(stdout); // Ensure the prompt is displayed immediately

		// Read a line of input from the user
		read = getline(&line, &len, stdin);

		// Check for end-of-file (EOF) or read error
		if (read == -1) {
			if (feof(stdin)) {
				break; // Break loop on EOF
				} else {
					perror("getline");
					free(line);
					return EXIT_FAILURE; // Exit on error
				}
		}
		// Remove the newline character from the input line
		line[strcspn(line, "\n")] = 0;
		token = strtok(line, delim);
		for (i = 0; i < 99 && token != NULL; i++) {
			argv[i] = token;
			//printf(" argv[%d] = %s", i, token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		if (fork() == 0) {
			// Print the command back to the user
			if (execve(argv[0], argv, NULL) == -1) {
				perror("./shell"); // Print an error message if execve fails
				exit(EXIT_FAILURE); // Exit the shell if execve fails
			}
			//printf("%s", line); // Print the line read (already includes the newline)
		}
		else {
			wait(NULL);
		}
			    }
	// Free allocated memory
	free(line);
	return EXIT_SUCCESS;
}

