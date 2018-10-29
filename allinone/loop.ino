//************************************* Main Loop - Runs Forever ***************************************************************//
//Moved Heavy Work To subroutines so you can call them from main loop without cluttering the main loop
void loop()
{
 
GetEC();          //Calls Code to Go into GetEC() Loop [Below Main Loop] dont call this more that 1/5 hhz [once every five seconds] or you will polarise the water
PrintReadings();  // Cals Print routine [below main loop]
delay(5000);

GetPH();
delay(5000);
 
}
//************************************** End Of Main Loop **********************************************************************//
