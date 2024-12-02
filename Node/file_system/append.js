// Importing the Node.js file system (fs) module to handle file operations
const fs = require("fs");

// Function to append content to a file
function append() {
    console.log(`Please provide the file to append into:`);

    // Listen for user input to get the file name
    process.stdin.once("data", (fileName) => {
        const Path = fileName.toString().trim(); // Convert input to string and trim whitespace

        console.log(`Please provide the data to append into ${Path}:`);

        // Listen for user input to get the content to append
        process.stdin.once("data", (data) => {
            const content = data.toString().trim(); // Convert input to string and trim whitespace

            // Use fs.appendFile to add content to the specified file
            fs.appendFile(Path, content, "utf8", (err) => {
                if (err) {
                    console.log(`Error caused by: ${err}`); // Log error if appending fails
                } else {
                    console.log("Content successfully appended!"); // Confirm success
                }
                process.exit(); // Exit the process
            });
        });
    });
}

// Export the append function for use in other modules
module.exports.append = append;
