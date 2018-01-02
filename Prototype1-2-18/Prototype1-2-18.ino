#include <LiquidCrystal.h>

int amperageThreshold; //At what amperage we want our shredder to back that ass up
int reverseTime; //how long to reverse after a jam
float overloadSensorFrequency; //decides how often to update the amperage draw. lower = more accurate & more ram usage, higher = lower accuracy & better ram usage. will need to be tweaked later 
float displayRefreshRate;
int currentSensorPin;

LiquidCrystal lcd(12,11,5,4,3,2);


void setup() {
	// put your setup code here, to run once:
	//initialize some starting variables that wont change (yet)
	amperageThreshold = 75; //in amps.
	reverseTime = 5; //in seconds.
	overloadSensorFrequency = .5; //in seconds
  currentSensorPin = 0;
  displayRefreshRate = .1;
  //initialize LCD
  lcd.begin(16, 2);

 Serial.begin(9600); //for testing
}

void loop() {
getAmperageLoad(); //for testing
delay(500);
}

void lcdControl()
{
  lcd.print(loadPercentage());
  delay(displayRefreshRate * 1000);
}

int getAmperageLoad() {
	int amperageLoad;
	//get input from sensor pins, return it in int
  amperageLoad = analogRead(currentSensorPin); //gets info from pin A0, but what is the input look like? //TODO
	Serial.println(amperageLoad); //for testing
	return amperageLoad;
}

void forward() {
	//move it forward
}

void backward() {
	//move it backwards
}

void stop() {
	//pause everything.
}
float loadPercentage()
{
  float load = getAmperageLoad() / amperageThreshold;
  return load;
}
void senseOverload() {
	//decides when an overload has occured, reverses motor for certain seconds.
	if (getAmperageLoad() >= amperageThreshold) { //if we go over our predefined limit
		backward();                                 //back it up
		delay(reverseTime * 1000);                  //run backwards for 5 seconds
	}
	delay(overloadSensorFrequency * 1000);

}

