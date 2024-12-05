// Importing the Node.js file system (fs) module to handle file operations
const fs = require("fs");

// Function to append content to a file
function append() {
	return new Promise((resolve, reject) => {
		console.log(`Please provide the file to append into:`);
		// Listen for user input to get the file name
    		process.stdin.once("data", (fileName) => {
			const Path = fileName.toString().trim();
			console.log(`Please provide the data to append into ${Path}:`);
			// Listen for user input to get the content to append
        		process.stdin.once("data", (data) => {
				const content = data.toString().trim();
				// Use fs.appendFile to add content to the specified file
				fs.appendFile(Path, content, "utf8", (err) => {
					if (err) {
						console.log(`Error: Unable to append to file "${path}".\n${err.message}`);
						reject(err)
					} else {
						console.log("Content successfully appended!");
						resolve();
					}
				});
			});
		});
	});
}

// Export the append function for use in other modules
module.exports.append = append;
