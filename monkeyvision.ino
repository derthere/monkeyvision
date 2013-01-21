int light1 = 6;
int light2 = 5;
int button1 = 2;
int button2 = 3;

int luminance = 0;
int frequency = 0;
int freq= 5;

void setup(){
  Serial.begin(9600);
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  
}

void loop()
{
  int buttonStatebright = digitalRead(button1);
  int buttonStatespeed = digitalRead(button2);
//  Serial.print("\nbright ");
 //Serial.print(buttonStatebright);
  Serial.print("\tspeed ");
 Serial.print( buttonStatespeed);
  
    if (buttonStatebright == LOW && luminance < 251){
  luminance += 10; //make it brighter 
  delay(200); //wait for release
    }
  if (buttonStatebright == LOW && luminance == 250){
  luminance = 0;
  delay(200);
    }
  
  
// Serial.println(luminance);
 
  if (buttonStatespeed == LOW && freq < 46){
     freq += 5;  
   delay(200); 
  }
   if (buttonStatespeed == LOW && freq == 45){
     freq = 5;
     delay(200);
   }
  frequency = (1/freq) *1000;  // make it faster
  Serial.print("\tspeed ");
  Serial.println(freq);
 
 
  
//  else  //if it is as fast as can be restart
//  {frequency == 0;}
  
  
  
  analogWrite (light1, luminance);
  analogWrite (light2, luminance);
  delay(freq);
  analogWrite (light1, 0);
  analogWrite (light2, 0);
  
  delay(200);
  
}
