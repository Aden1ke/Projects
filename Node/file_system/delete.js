// Importing the Node.js file system (fs) module to handle file operations
const fs = require("fs");

// Function to delete a file
function deleteFile() {
	return new Promise((resolve, reject) => {
		console.log(`Please provide the file to delete:`);
		// Listen for user input to get the file name
    		process.stdin.once("data", (fileName) => {
			const Path = fileName.toString().trim(); // Convert input to string and trim whitespace
			// Use fs.unlink to delete the specified file
        		fs.unlink(Path, (err) => {
				if (err) {
					console.log(`Error: Unable to delete file "${path}".\n${err.message}`);
					reject(err)
				} else {
					console.log("File successfully deleted!");
					resolve()
				}
			});
		});
	});
}

// Export the deleteFile function for use in other modules
module.exports.deleteFile = deleteFile;
