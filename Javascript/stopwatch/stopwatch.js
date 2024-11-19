function Stopwatch () {
	let endTime, startTime, duration = 0;
	let running = false;
	this.start = function () {
		if (running) {
			console.log(" stopwatch is already running");
			return
		}
		running = true;
		startTime = new Date();
	}
	this.stop = function () {
		if (!running) {
			console.log(" stopwatch is not running");
			return
		}
		running = true;
		endTime = new Date();
		duration += (endTime - startTime) / 1000;
	}
	this.reset = function () {
		endTime, startTime, duration = 0;
		running = false;
	}
	this.duration = function () {
		console.log(` ${duration}`);
	}
}


const stopwatch = new Stopwatch();

stopwatch.start();
setTimeout(() => {
    stopwatch.stop();
    stopwatch.duration();
}, 3000);
