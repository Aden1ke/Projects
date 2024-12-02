
// Importing the Node.js file system (fs) module to handle file operations
const fs = require("fs");

function read(){
	console.log(`Please provide the file path to read:`);

	// Listening for the next input to get the file path
	process.stdin.once('data', (filePath) => {
		// Convert the file path input to a string and trim whitespace
		const Path = filePath.toString().trim();

		fs.access(Path, fs.constants.F_OK, (err) => {
			if (err) {
				// File does not exist
				console.log(`Error: File "${Path}" does not exist.`);
				return process.exit();
			}

			// Reading the file at the specified path
			const read = fs.readFile(Path, 'utf8', (err, data) => {
				if (err) {
					// Log an error message if the file read fails
					console.log(`Error caused by: ${err}`);
				} else {
					// Log the file contents if the read is successful
					console.log(data);
				}
				// Exit the process after completing the operation
				process.exit();
				});
		});
	});
}

module.exports.read = read;
