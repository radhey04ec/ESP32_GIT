
/*   Program LED Blink using Timer / Interrupt
 *   Baord : ESP32 V1.0 REV1 WIFI BLUETOOTH LITE (Lolin-32)
 *   Built in LED is on GPIO-22 of DEV Board
 *   Jaydeep Shah - 8 April 22
 *   
 *   Internal Timer-0  used
 *   Prescaller = 80 -- so clk frequency is 1 MHz
 *   ARR = 1M, so Timmer event will be genrated  on 1 second interval
 */

 
#define LED_BUILTIN 22    //Built in LED on DEV board
volatile bool state = 0;  //Global variable for the state of LED


//create timer pointer that stores timer structure when we will create & configure timer parameters using library function.
hw_timer_t * timer = NULL;



//ISR
//Function called  when timer interrrrupt geenrated  -- ISR no any Argument return /or pass

void IRAM_ATTR onTimer()                      //in ESP32 ISR function only called if it located in IRAM
{
state = !state;  //Change the state
}



//setup function
void setup()
{

  cli(); //No any external/internal interrupt allowed
  
  //Begin Serial port
  Serial.begin(115200);
  Serial.println("\n Programm started !!!");  //For know just serial port is working !!!

  
  //We are going to use TIMER-0, Prescaller = 80,0000,000/80 -- gives 1 micro second resolution,Third parameter indicates up counting
  timer = timerBegin(0,80,true);  //Timer created and return NULL if configuration failed
  if(timer == NULL)
  {
    Serial.println("\n TIMER Initialization failed !!!");
  }

  //Attach method which will be called during timer interrupt
  timerAttachInterrupt(timer, &onTimer, true);  //Third parameter indicate Auto reload on
  timerAlarmWrite(timer, 1000000, true);       //Second parameter is ARR (64 bti value), We want 1 second interrupt so set 1000000 micro tick,Third parameter is auto reload on
  timerAlarmEnable(timer);                    //Enable Timer event 

  
  sei();  //Turn interrupt on 


//LED pin declaration & Initialization
pinMode(LED_BUILTIN,OUTPUT);
digitalWrite(LED_BUILTIN,LOW);  //Initially LOW
  
}



//loop forever
void loop()
{

  digitalWrite(LED_BUILTIN,state); //LED state as per variable
}
