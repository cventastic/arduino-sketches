// EC

#include <OneWire.h>
#include <DallasTemperature.h>
 
int R1= 1000;
int Ra=25; //Resistance of powering Pins
int ECPin= A15;
int ECGround=A14;
int ECPower =A13;
float PPMconversion=0.64;
float TemperatureCoef = 0.019; //this changes depending on what chemical we are measuring
float K=1.76;

#define ONE_WIRE_BUS A8          // Data wire For Temp Probe is plugged into pin 10 on the Arduino
const int TempProbePossitive =8;  //Temp Probe power connected to pin 9
const int TempProbeNegative=9;    //Temp Probe Negative connected to pin 8 

OneWire oneWire(ONE_WIRE_BUS);// Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature sensors(&oneWire);// Pass our oneWire reference to Dallas Temperature.
 
float Temperature=10;
float EC=0;
float EC25 =0;
int ppm =0;
float raw= 0;
float Vin= 5;
float Vdrop= 0;
float Rc= 0;
float buffer=0;
// END EC 

// PH Probe Vars
#define SensorPin A2            //pH meter Analog output to Arduino Analog Input 0
#define Offset 0.00            //deviation compensate
#define LED 13
#define samplingInterval 20
#define printInterval 800
#define ArrayLenth  40    //times of collection
int pHArray[ArrayLenth];   //Store the average value of the sensor feedback
int pHArrayIndex=0;    
// END PH Probe Vars

 
 

 
