//exporting file system module
const fs = require("fs");


console.log(`welcome to File system reading\n`);
console.log(`Do you want to: \n
	1) Read a File\n
	2) Write into a File\n
	3) append a File\n
	4) Delete a File\n
	Pick a number:\n`);
process.stdin.on('data', (data) => {
	const command = data.toString().trim();
  if (command === "1") {
	  console.log(`Please provide the file path to read:`);

        // Read the next input for file path
        //process.stdin.once('data', (filePath) => {

	  process.stdin.once('data', (filePath) => {
		  const Path = filePath.toString().trim();
		  const read = fs.readFile(Path, 'utf8', (err, data) =>{
			  if (err) {
				  console.log(`error caused by: ${err}`);
			  } else
				  console.log(data);
			  process.exit();
		  });
	  });
  } else if (command === "2") {
	  console.log(`Please provide the file to write into:`);
	  process.stdin.once('data', (fileName) => {
		  const Path = fileName.toString().trim();
		  console.log(`Please provide the data to write into ${Path}:`);
		  process.stdin.once('data', (data) => {
			  const content = data.toString().trim();
			  const write = fs.writeFile(Path, content, 'utf8', (err, data) => {
				  if (err) {
					  console.log(`error caused by: ${err}`);
				  } else
					  console.log('Content successfully written!');
				  process.exit();
			  });
		  });
	  });
  }else if (command === "3") {
	    console.log(`Please provide the file to write into:`);
	  process.stdin.once('data', (fileName) => {
		  const Path = fileName.toString().trim();
		  console.log(`Please provide the data to write into ${Path}:`);
		  process.stdin.once('data', (data) => {
			  const content = data.toString().trim();
			  const append = fs.appendFile(Path, content, 'utf8', (err, data) => {
				  if (err) {
					  console.log(`error caused by: ${err}`);
				  } else
					  console.log('Content successfully appended!');
				  process.exit();
			  });
		  });
	  });
  } else if (command === "4") {
	  console.log(`Please provide the file to delete:`);
	  process.stdin.once('data', (fileName) => {
		  const Path = fileName.toString().trim();
		  const write = fs.unlink(Path, (err) => {
			  if (err) {
				  console.log(`error caused by: ${err}`);
			  } else
				  console.log('File successfully deleted!');
			  process.exit();
		  });
	  });
  } else {
	  console.log(`Incorrect command. Please pick 1, 2, or 3.`);
    }
	});

console.log(` file reading ongoing `);

