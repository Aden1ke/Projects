//exporting file system module
const fs = require("fs");
const { read } = require("./read");
const { write } = require("./write");
const { append } = require("./append");
const { deleteFile } = require("./delete");


function showMenu() {
    console.log(`Welcome to File System Manager\n`);
    console.log(`Do you want to: \n
        1) Read a File\n
        2) Write into a File\n
        3) Append to a File\n
        4) Delete a File\n
        Pick a number:\n`);
}

//showMenu();

//handle commandments in async form
async function handleCommands(command) {
	try {
		if (command === "1") {
			await read();
		} else if (command === "2") {
			await write();
		} else if (command === "3") {
			await append();
		} else if (command === "4") {
			await deleteFile();
		} else {
			console.log(`Incorrect command. Please pick 1, 2, 3, or 4.`)
		}
	} catch(error) {
		console.log(`${error} : Incorrect command. Please pick 1, 2, 3, or 4.`)};
}

//make it a repeated process
process.stdin.on("data", (data) => {
	const command = data.toString().trim();
	// Trim whitespace from the command
	handleCommands(command);
	});

//console.log(` file reading ongoing `);

