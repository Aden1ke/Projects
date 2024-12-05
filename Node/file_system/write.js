// Importing the Node.js file system (fs) module to handle file operations
const fs = require("fs");


function write() {
	return new Promise((resolve, reject) =>{
		console.log(`Please provide the file to write into:`);
		// Listening for the next input to get the file name
		process.stdin.once('data', (fileName) => {
		// Convert the file name input to a string and trim whitespace
			const Path = fileName.toString().trim();

			console.log(`Please provide the data to write into ${Path}:`);

			// Listening for the next input to get the file content
			process.stdin.once('data', (data) => {
				// Convert the file content input to a string and trim whitespace
				const content = data.toString().trim();
				fs.writeFile(Path, content, 'utf8', (err) => {
					if (err) {
						console.log(`Error: Unable to write to file "${path}".\n${err.message}`);
						reject(err);
					} else {
						console.log('Content successfully written!');
						resolve();
					}
				});
			});
		});
	});
}
module.exports.write = write;
