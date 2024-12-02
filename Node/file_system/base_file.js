//exporting file system module
const fs = require("fs");
const { read } = require("./read");
const { write } = require("./write");
const { append } = require("./append");
const { deleteFile } = require("./delete");


console.log(`welcome to File system reading\n`);
console.log(`Do you want to: \n
	1) Read a File\n
	2) Write into a File\n
	3) append a File\n
	4) Delete a File\n
	Pick a number:\n`);

process.stdin.on("data", (data) => {
    const command = data.toString().trim(); // Trim whitespace from the command

    if (command === "1") {
	    read();
    } else if (command === "3") {
	    write();
    } else if (command === "3") {
	    append();
    } else if (command === "4") {
	    deleteFile();
    } else {
	    console.log(`Incorrect command. Please pick 1, 2, 3, or 4.`); // Error message for invalid input
    }
});

console.log(` file reading ongoing `);

