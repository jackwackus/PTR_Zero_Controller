int relay1 = 7;
int relay2 = 9;

int relay1_state = 0;
int relay2_state = 0;

long dur1 = 0;

unsigned long start_time = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  
}

//Loop every 100 miliseconds

void loop() 
{
  if (Serial.available())
  {
   
    //Read serial command. Serial command is an integer (in ASCII) followed by a newline
    
    //Parse ASCII integers out of buffer.
    long component1 = Serial.parseInt();
    //Read anything else
    while (Serial.available()){Serial.read();}
    
    if (component1 == 111)
    {
      if (relay1_state == 0)
      {
        //Send "0" while solenoids are inactive
        Serial.println(0);
        }
      else
      {
        //Send "1" while relays are activated
        Serial.println(1);
        }
      }
    else
    {
      //Set relay on duration
      dur1 = component1;
      //Turn on relay1
      digitalWrite(relay1, HIGH);
      relay1_state = 1;
      //Turn on relay2
      digitalWrite(relay2, HIGH);
      relay2_state = 1;
      
      //Initialize clock for relays
      start_time = millis();

      //Relays are now activated, so send "1"
      Serial.println(1);
      }
    }
      
  //When dur1 is exceeded, turn relays off (this should occur whether or not there is serial data in the buffer)
  if ((relay1_state == 1) && ((millis() - start_time) > dur1*1000))
  {
    //Turn off relay1
    digitalWrite(relay1, LOW);
    //Reset relay1_state to 0
    relay1_state = 0;
    //Turn off relay2
    digitalWrite(relay2, LOW);
    //Reset relay2_state to 0
    relay2_state = 0;
    //Reset dur1 to zero
    dur1 = 0;
    }

  delay(100);
  
  }
