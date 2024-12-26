const express = require('express');
//const zookeeper = require('node-zookeeper-client');

const app = express();
//connect to zookeeper
//const client = zookeeper.createClient('localhost:8000');
//client.connect();


// Fetch a range of IDs
//function fetchRange(rangeSize, callback) {
//	client.getData('')
//}


//routes to get url
app.post('/:shorten', (req, res) => {
	const { originalurl } = req.body;
	const shortCode = shortid.generate();
	const newUrlCode = {
		const oldUrl = originalUrl;
		const newUrl = shortCode:
	};
});


app.get(('/:shorten', (req, res) => {
	const { shortCode } = req.params;
	const url = newUrlCode.find({ shortCode });
	if (url) {
		res.redirect(url.originalUrl);
	} else {
		res.status(404).send('URL not found');
	}
});

app.listen(8000, ()=> {
	console.log(`Server is running on http://localhost:${PORT}`);
});
