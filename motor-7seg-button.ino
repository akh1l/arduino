//Incrementing the motor speed using a push button.. and displaying the speed on a 7 segment display

int number[][10] ={
	{0,0,1,1,1,1,1,1,0}, //0   
	{0,0,0,1,1,0,0,0,0}, //1
	{0,0,1,1,0,1,1,0,1}, //2
	{0,0,1,1,1,1,0,0,1}, //3
	{0,0,0,1,1,0,0,1,1}, //4
	{0,0,1,0,1,1,0,1,1}, //5
	{0,0,1,0,1,1,1,1,1}, //6
	{0,0,1,1,1,0,0,0,0}, //7
	{0,0,1,1,1,1,1,1,1}, //8
	{0,0,1,1,1,1,0,1,1}  //9
};

int j = 0;//number on the 7 segment display
int motorpin = 9; //will be an output
int buttonpin = 10; // will be an input
float count = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(motorpin, OUTPUT);
	pinMode(buttonpin, INPUT);
}

void show(int j)
{
	for(int i = 2; i < 9; i++)// to print one digit
	{
		digitalWrite(i, number[j][i]);
	}
}

void loop()
{
	if(count == 0) // to display 0 at the beginning
	{
		show(0);
	}
	int bstate = digitalRead(buttonpin); //takes button state as input
	if(bstate == 1) //if button is pressed
	{
		count = count + 28.33;  // analog o/p on arduino has a range of 256(0 - 255)... 255/9 = 28.33 (9 speed level)
		j++;
		if(count > 255 || j > 9)  // to reset it
		{
			count = 0;
			j = 0; 
		}
		analogWrite(motorpin, count);//
		show(j);  // display it on 7 segment display
		delay(500);//wont take the input for the next half second
		// assuming that we are done pressing the button in less then half a second,
	} 
}
