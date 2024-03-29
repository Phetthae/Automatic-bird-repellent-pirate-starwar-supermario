/*
This is a mini project I did while studying. By this project is Simulation of automatic bird repellent 
To divide the bird repellent phase into 3 main phases. Divided into 20-120cm 120-220cm 220-320cm, 
each distance will have a different bird repellent sound. The music is pirate of the caribbean, Star War and Super Mario. 
For creativity, you can customize it for use.

You can use simulator by this linked : https://www.tinkercad.com/things/16X0UBoPXEd-automatic-bird-repellent
*/
#include <LiquidCrystal.h> 

const int buzzer = 11; //Buzzer Pin 11
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); //LCD Pin 1,2,3,4,5,6,7
const int trigPin = 9; //Ultra Sonic pin9
const int echoPin = 10; //Ultra Sonic pin10
long duration; //Untra Sonic duration
int distanceCm; //For show Distance
int Bird = 0; //For count Bird

/*--------Define Variant NOTE--------*/
const float songSpeed = 1.0;
    //  NOTE  Buzzer Tone
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
#define NOTE_A5 880
#define NOTE_B5 988
/*-----------------------------------*/

/*---Pirates Of The Caribbean Song---*/
int notes[] = {			//Note for Pirates Song
    
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,
};
int durations[] = {		//duration for Pirates Song
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,
};
/*-----------------------------------*/

/*------------Star War Song----------*/
int notes1[] = {		//Note for Star War Song
	NOTE_A4, 0, NOTE_A4, 0, NOTE_A4, 0,
  	NOTE_F4, 0, NOTE_C5, 0, NOTE_A4, 0,
  	NOTE_F4, 0, NOTE_C5, 0, NOTE_A4, 0,
  	
};

int durations1[] = {	//duration for Star War Song
    500, 50, 500, 50 , 500, 50, 
    350, 50, 150, 50 , 500, 50, 
    350, 50, 150, 50 , 650, 50, 
};
/*-----------------------------------*/

/*----------Super Mario Song---------*/
int notes2[] = {		//Note for Super Mario Song
  NOTE_E5, NOTE_E5, 0, NOTE_E5,
  0, NOTE_C5, NOTE_E5, 0,
  NOTE_G5, 0, 0,  0,
  NOTE_G4, 0, 0, 0,
  	
};

int durations2[] = {	//durations for Super Mario song
  160, 160, 160, 160,
  160, 160, 160, 160,
  160, 160, 160, 160,
  160, 160, 160, 160,
};
/*-----------------------------------*/

/*-------------Function Pirates Song-------------*/
void PiratesSong(){
 const int totalNotes = sizeof(notes) / sizeof(int);
  
  for (int i = 0; i < totalNotes; i++)
  {
    const int currentNote = notes[i];			//play notes
    float wait = durations[i] / songSpeed;		//import song speed form duration
    if (currentNote != 0)
    {
      tone(buzzer, notes[i], wait); 
    }
    else
    {
      noTone(buzzer);
    }
    delay(wait);
  }
}
/*-----------------------------------*/

/*-------------Function Star war Song-------------*/
void StarWarSong(){
    const int totalNotes1 = sizeof(notes1) / sizeof(int);
  
  for (int i1 = 0; i1 < totalNotes1; i1++)
  {
    const int currentNote1 = notes1[i1];		//Play notes1
    float wait1 = durations1[i1] / songSpeed;	//import song speed form duration1
    if (currentNote1 != 0)
    {
      tone(buzzer, notes1[i1], wait1); 
    }
    else
    {
      noTone(buzzer);
    }
    delay(wait1);
  }
}
/*-----------------------------------*/

/*-------------Function Super Mario Song-------------*/
void SuperMarioSong(){
    const int totalNotes2 = sizeof(notes2) / sizeof(int);
  
  for (int i2 = 0; i2 < totalNotes2; i2++)
  {
    const int currentNote2 = notes2[i2];		//play notes2
    float wait2 = durations2[i2] / songSpeed;	//import song speed from duration2
    if (currentNote2 != 0)
    {
      tone(buzzer, notes2[i2], wait2); 
    }
    else
    {
      noTone(buzzer);
    }
    delay(wait2);
  }
}
/*-----------------------------------*/


void setup() {    
lcd.begin(16,2);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

}

void loop() { 
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;   			  //calculate turn inch into centimeter

/*--------IF detected range 20-120cm---------*/
  if(distanceCm >= 20 && distanceCm <= 120){  //detected range 20-120cm
    digitalWrite(buzzer, HIGH);				  //start buzzer
    lcd.setCursor(0,0); 
    lcd.print("Distance: ");				  //print Distance: on lcd
    lcd.print(distanceCm); 					  //print inporting collected distanceCm on lcd
    lcd.print(" cm         ");				  //print cm on lcd
    delay(10);
    lcd.setCursor(0,1);
    lcd.print("Detected         ");			  //print Detected on lcd
    PiratesSong();							  //import function PiratesSong for warning the bird
    Bird++;									  //Count the Bird

  }
/*------------------------------------------*/
  
/*--------IF detected range 120-220cm---------*/
  else if(distanceCm > 120 && distanceCm <= 220)//detected range 120-220cm
    {
    digitalWrite(buzzer, HIGH);					//start buzzer
    lcd.setCursor(0,0); 
    lcd.print("Distance: "); 					//print Distance: on lcd
    lcd.print(distanceCm); 						//print inporting collected distanceCm on lcd
    lcd.print(" cm           ");				//print cm on lcd
    delay(10);
    lcd.setCursor(0,1);
    lcd.print("Detected          ");			//print Detected on lcd
    StarWarSong();								//import function StarWarSong for warning the bird
    Bird++;										//Count the Bird
  
  }
/*------------------------------------------*/
  
/*--------IF detected range 220-320cm---------*/
  else if(distanceCm > 220 && distanceCm <= 320)//detected range 220-320cm
    {
    digitalWrite(buzzer, HIGH);					//start buzzer
    lcd.setCursor(0,0); 
    lcd.print("Distance: "); 					//print Distance: on lcd
    lcd.print(distanceCm); 						//importing distanceCm form collecting and print on lcd
    lcd.print(" cm         ");					//print cm on lcd
    delay(10);
    lcd.setCursor(0,1);
    lcd.print("Detected         ");				//print Detected on lcd
    SuperMarioSong();							//import function SuperMarioSong for warning the bird
    Bird++;										//Count the Bird
  }
/*------------------------------------------*/
  
/*--------IF Un detected---------*/

  else{
    lcd.setCursor(0,0); 
    lcd.print("Not Detected       "); 			//print Not Detected on lcd
    digitalWrite(buzzer, LOW);					//shut the buzzer
    delay(10);
    lcd.setCursor(0,1);
    lcd.print("Bird Count ");					//print Bird Cound on lcd
    lcd.print(Bird); 							//importing Bird form collecting and print on lcd
    lcd.print(" EA      ");						//print EA on lcd
  }

}
/*------------------------------------------*/
/*--------------------END-------------------*/