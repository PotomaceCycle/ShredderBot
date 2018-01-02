int amperageThreshold; //At what amperage we want our shredder to back that ass up

void setup() {
	// put your setup code here, to run once:
	//initialize some starting variables that wont change (yet)

	amperageThreshold = 75;

}

void loop() {

}

int getAmperageLoad() {
	int amperageLoad;
	//get input from sensor pins, return it in int

	return amperageLoad;
}

void forward() {
	//move it forward
}

void backward() {
	//move it backwards
}

void senseOverload() {
	//decides when an overload has occured, reverses motor for certain seconds.
	if (getAmperageLoad() >= amperageThreshold) {

	}

}

