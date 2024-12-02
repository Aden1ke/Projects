// Importing the Node.js file system (fs) module to handle file operations
const fs = require("fs");


function write() {
	console.log(`Please provide the file to write into:`);

	// Listening for the next input to get the file name
	process.stdin.once('data', (fileName) => {
		// Convert the file name input to a string and trim whitespace
		const Path = fileName.toString().trim();

		// Ask the user to provide the content to write into the file
		console.log(`Please provide the data to write into ${Path}:`);

		// Listening for the next input to get the file content
		process.stdin.once('data', (data) => {
			// Convert the file content input to a string and trim whitespace
			const content = data.toString().trim();

			// Writing the provided content into the specified file
			const write = fs.writeFile(Path, content, 'utf8', (err) => {
				if (err) {
					// Log an error message if the write operation fails
					console.log(`Error caused by: ${err}`);
				} else {
					// Log a success message if the write operation succeeds
					console.log('Content successfully written!');
				}
				// Exit the process after completing the operation
				process.exit();
			});
		});
	});
}
module.exports.write = write;
