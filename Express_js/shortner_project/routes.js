const express = require('express');
const shortid = require("shortid");
//const zookeeper = require('node-zookeeper-client');

const app = express();
// Middleware to parse JSON request bodies
app.use(express.json());


//obj storing the original url with the shortcode in an obj
const urlDatabase = {};


//Root handler
app.get('/', (req, res) => {
	res.send('Welcome to the URL Shortner')
});

//routes to store url
app.post('/:shortCode', (req, res) => {
	const { originalurl } = req.body;
	if(!originalurl) {
		return ( res.status(400).send("Original URL not found"));
	}
	
	// if originalurl is correct generatete a code
	const shortCode = shortid.generate();

	//store the originalurl in urldabase object using the short code as key
	urlDatabase[shortCode] = originalurl;

	//Store the original URL with its short code
	res.json({shortcode, shorturl: `http://localhost:8000/${shortCode}`});
});


// Route to redirect to the original URL
app.get('/:shortCode', (req, res) => {
	const { shortCode } = req.params;
	const originalurl = urlDatabase[shortCode];
	if (originalurl) {
		res.redirect(originalUrl);
	} else {
		res.status(404).send('URL not found');
	}
});


const PORT = 8000;
app.listen(PORT, ()=> {
	console.log(`Server is running on http://localhost:${PORT}`);
});
