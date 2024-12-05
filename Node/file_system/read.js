
// Importing the Node.js file system (fs) module to handle file operations
const fs = require("fs");

function read(){
	return new Promise ((resolve, reject) =>{
		console.log(`Please provide the file path to read:`);
		// Listening for the next input to get the file path
		process.stdin.once('data', (filePath) => {
		// Convert the file path input to a string and trim whitespace
			const Path = filePath.toString().trim();

			fs.readFile(Path, 'utf8', (err, data) => {
				if (err) {
					console.log(`Error caused by: ${err}`);
					reject(err); // Reject the promise with the error
				} else {
					console.log(data);
					resolve();
				}
			});
		});
	});
}

module.exports.read = read;
