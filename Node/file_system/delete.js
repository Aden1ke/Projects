// Importing the Node.js file system (fs) module to handle file operations
const fs = require("fs");

// Function to delete a file
function deleteFile() {
    console.log(`Please provide the file to delete:`);

    // Listen for user input to get the file name
    process.stdin.once("data", (fileName) => {
        const Path = fileName.toString().trim(); // Convert input to string and trim whitespace

        // Use fs.unlink to delete the specified file
        fs.unlink(Path, (err) => {
            if (err) {
                console.log(`Error caused by: ${err}`); // Log error if deletion fails
            } else {
                console.log("File successfully deleted!"); // Confirm success
            }
            process.exit(); // Exit the process
        });
    });
}

// Export the deleteFile function for use in other modules
module.exports.deleteFile = deleteFile;
