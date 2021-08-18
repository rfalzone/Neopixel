
#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUMPIXELS 30
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int n;  //The time variable
int colorArray [NUMPIXELS][3];  //Stores the HSV values of each LED
float shiftr;  //Used to toggle between some colors

void setup()  {
int n=0;
int colorArray [NUMPIXELS][3];
shiftr=10000;


  strip.begin();
  strip.show();

}
void loop() {
  timerfunc();   
}


static void  timerfunc(){  //The main function.  Uses a variable to keep time and haave multiple LED effects going all at once
int  freq1=50;  //LED Effect 1 frequency
int  freq2=35;  //LED Effect 2 frequency
int  freq3=10;  //LED Effect 3 frequency
  

  delay(1);
  n++;
 
  if(n%freq1==0){
  foo(n, freq1);
  
  }
  if(n%freq2==0){
    bar();
  }
  if(n%freq3==0){
    whizz();
  }
  if (n%(freq1*freq2*freq3)==0){
  n=0;
  }
}

static void foo(int n, int freq1){
    int i = n/freq1%(NUMPIXELS);  //Uses the time variable n to activate LEDs in sequence, creating a 'wave' effect. 
      
   
    
     
    int h = shiftr;
    int s = 180;
    int v = 45;
    colorArray[i][0]=h;   //Saves the LED state
    colorArray[i][1]=s;
    colorArray[i][2]=v;
  strip.setPixelColor(i,strip.ColorHSV(h , s,v));
  strip.show();
    
if(i==29){      
shiftr=50000-shiftr;    //Toggles the hue between 40000 and 10000     
}
      
     
     
      
    
  
}
static void bar(){  //This funciton just makes a random LED a random Hue, Saturation, and Value every so often
    int i = rand() % NUMPIXELS ;    
    int h = rand() % 65535;
    int s = rand() % 100 + 156;  //Picks a random variable between 155 and 255, didn't want anything too desaturated, it just looks white.
    int v = rand() % 50 +25;  //Picks a random brightness between 25 and 75, didn't want anyhting that looked either off or blinding.
    colorArray[i][0]=h;  //Saves the LED state
    colorArray[i][1]=s;
    colorArray[i][2]=v;
  strip.setPixelColor(i,strip.ColorHSV(h,s,v));
  strip.show();
    
   
  
}
static void whizz(){  //This slowly dims every LED
 for(uint16_t i=0; i<strip.numPixels(); i++) {                                  
            int h=colorArray[i][0];  //Grabs the current LED state
            int s=colorArray[i][1];
            int v=colorArray[i][2];
            v=v-1;  //Makes the Value, the brightness variable, lower
            if(v<0){
              v=0;
            };
            colorArray[i][2]=v;  //Stores the new variable
            strip.setPixelColor(i,strip.ColorHSV(h,s,v));
            strip.show();
           }

  
}


