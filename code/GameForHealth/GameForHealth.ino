// testshapes demo for Adafruit RGBmatrixPanel library.
// Demonstrates the drawing abilities of the RGBmatrixPanel library.
// For 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK 8  // MUST be on PORTB!
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);


const int Player_1_button = 10;
const int Player_1_seat = 11;
//const int Player_2_button = 0;
const int Player_2_seat = 12;
//const int Player_3_button = 1;
const int Player_3_seat = 13;
//const int Player_4_button = 12;
const int Player_4_seat = 0;


// variables will change:

int MultiplayerMode = 0; 

int SinglePlayer_Counter = 0; 
int SinglePlayer_Break_Counter = 0; 
int Player_1_Counter = 0; 
int Player_2_Counter = 0; 
int Player_3_Counter = 0; 
int Player_4_Counter = 0; 

int SinglePlayer_Collor_R;
int SinglePlayer_Collor_G;
int SinglePlayer_Collor_B;

int Player_1_Collor_R;
int Player_1_Collor_G;
int Player_1_Collor_B;

int Player_2_Collor_R;
int Player_2_Collor_G; 
int Player_2_Collor_B; 

int Player_3_Collor_R;
int Player_3_Collor_G; 
int Player_3_Collor_B;

int Player_4_Collor_R;
int Player_4_Collor_G; 
int Player_4_Collor_B;

int Player_1_buttonState = 0; 
int Player_1_button_seat_State = 0;
int Player_1_Last_buttonState = 0;

int Player_2_button_seat_State = 0;
int Player_3_button_seat_State = 0;
int Player_4_button_seat_State = 0;


void setup() {
   pinMode(Player_1_button, INPUT); 
   pinMode(Player_1_seat, INPUT); 
   pinMode(Player_2_seat, INPUT); 
   pinMode(Player_3_seat, INPUT); 
   pinMode(Player_4_seat, INPUT); 
   //pinMode(ledPin, OUTPUT);      
   matrix.begin();
 
  // initialize serial communication:
  Serial.begin(9600);

}

void loop() {
  // read the button 
  Player_1_buttonState = digitalRead(Player_1_button); 
  Player_1_button_seat_State = digitalRead(Player_1_seat); 
  
  if (Player_1_button_seat_State == HIGH){
    //digitalWrite(ledPin, HIGH);  
    
    // compare the buttonState to its previous state
    if (Player_1_buttonState != Player_1_Last_buttonState){ 
    
      // check if the pushbutton is pressed. if it is, the buttonState is HIGH:
      if (Player_1_buttonState == HIGH) {    
         // if the current state is HIGH then the button wend from off to on:  
          MultiplayerMode++;
          Serial.println("on");
          Serial.println("buttonstate");
        }
    
       else {
        // if the current state is LOW then the button wend from on to off:
          Serial.println("off");   
        }
     }   
     
    // save the current state as the last state, for next time through the loop
    Player_1_Last_buttonState = Player_1_buttonState;
    
      
    if (MultiplayerMode % 2 == 0) {
          
      //reset the multiplayer variables   
      Player_1_Counter = 0; 
      Player_1_Collor_R = 0; 
      Player_1_Collor_G = 0; 
      Player_1_Collor_B = 0; 
      
      Player_2_Counter = 0;
      Player_2_Collor_R = 0; 
      Player_2_Collor_G = 0; 
      Player_2_Collor_B = 0;
      
      Player_3_Counter = 0; 
      Player_3_Collor_R = 0; 
      Player_3_Collor_G = 0; 
      Player_3_Collor_B = 0;
      
      Player_4_Counter = 0;
      Player_4_Collor_R = 0; 
      Player_4_Collor_G = 0; 
      Player_4_Collor_B = 0;
      
          // BL Player 1 
      matrix.drawRect(0, 0, 32, 16, matrix.Color333(7, 7, 0));
          // the fill
      matrix.fillRect(1, 1, 30, 14, matrix.Color333(SinglePlayer_Collor_R, SinglePlayer_Collor_G, SinglePlayer_Collor_B)); 
      
       if (SinglePlayer_Counter < 800){
          // draw some text!
          matrix.setCursor(12, 4);   // start at top left, with one pixel of spacing
          matrix.setTextSize(1);    // size 1 == 8 pixels high
          
          // H
          matrix.drawLine(8, 10, 4, 10, matrix.Color333(7, 0, 0));
          matrix.drawLine(6, 10, 6, 12, matrix.Color333(7, 0, 0));
          matrix.drawLine(8, 12, 4, 12, matrix.Color333(7, 0, 0));
         
          // I 
          matrix.drawLine(8, 8, 6, 8, matrix.Color333(7, 0, 0));
          matrix.drawPixel(4, 8, matrix.Color333(7, 0, 0)); 
          
          // !! 
          matrix.drawLine(6, 5, 4, 5, matrix.Color333(7, 0, 0));
          matrix.drawPixel(8, 5, matrix.Color333(7, 0, 0)); 
  
          matrix.drawLine(6, 3, 4, 3, matrix.Color333(7, 0, 0));
          matrix.drawPixel(8, 3, matrix.Color333(7, 0, 0)); 
         
          // print a happy smiley
          matrix.setTextColor(matrix.Color333(7,7,0));
          matrix.print(':');
          matrix.print(')');
       }
       
        if (SinglePlayer_Counter < 2000){
             SinglePlayer_Collor_R = 0;
             SinglePlayer_Collor_G = 1; 
             SinglePlayer_Collor_B = 0;
        }
        
        if (SinglePlayer_Counter == 2000){
             SinglePlayer_Collor_R = 2;
             SinglePlayer_Collor_G = 2; 
             SinglePlayer_Collor_B = 0; 
        }
   
        if (SinglePlayer_Counter == 4000){
             SinglePlayer_Collor_R = 7;
             SinglePlayer_Collor_G = 2; 
             SinglePlayer_Collor_B = 0;          
        }
        
         if (SinglePlayer_Counter == 6000){
             SinglePlayer_Collor_R = 7;
             SinglePlayer_Collor_G = 0; 
             SinglePlayer_Collor_B = 0;
        }
       
        if (SinglePlayer_Counter > 6500){
          matrix.setCursor(12, 4);   // start at top left, with one pixel of spacing
          matrix.setTextSize(1);    // size 1 == 8 pixels high
          
          // print some text
          matrix.setTextColor(matrix.Color333(7,7,0));
          matrix.print(':');
          matrix.print('(');
          
       }
       
       if (SinglePlayer_Counter == 7000){ 
         SinglePlayer_Counter = 0; 
       }
       
       SinglePlayer_Counter ++;
       
  
    } else {
      
      // if we did't had a break, reset the singleplayer variables 
      if(SinglePlayer_Break_Counter == 0){ 
        SinglePlayer_Counter= 0;
        SinglePlayer_Collor_R = 0;
        SinglePlayer_Collor_G = 0; 
        SinglePlayer_Collor_B = 0; 
        
      } else { 
        // reset the SinglePlayer_Break_Counter
        SinglePlayer_Break_Counter = 0;  } 
      
    ///////////////////////  Innitial Screen  ///////////////////////  
      // BottomLeft Player 1 
      matrix.drawRect(0, 8, 16, 8, matrix.Color333(7, 7, 0));
        // the fill
        matrix.fillRect(1, 9, 14, 6, matrix.Color333(Player_1_Collor_R, Player_1_Collor_G, Player_1_Collor_B));
    
       
        if (Player_1_Counter < 2000){
             Player_1_Collor_R = 0;
             Player_1_Collor_G = 1; 
             Player_1_Collor_B = 0;
        }
        
        if (Player_1_Counter == 2000){
             Player_1_Collor_R = 2;
             Player_1_Collor_G = 2; 
             Player_1_Collor_B = 0; 
        }
   
        if (Player_1_Counter == 4000){
             Player_1_Collor_R = 7;
             Player_1_Collor_G = 2; 
             Player_1_Collor_B = 0;          
        }
        
         if (Player_1_Counter == 6000){
             Player_1_Collor_R = 7;
             Player_1_Collor_G = 0; 
             Player_1_Collor_B = 0;
        }
        
        if (Player_1_Counter == 7000){ 
         Player_1_Counter = 0; 
       }
       
      Player_2_button_seat_State = digitalRead(Player_2_seat);  
      Player_3_button_seat_State = digitalRead(Player_3_seat);
      Player_4_button_seat_State = digitalRead(Player_4_seat);
            
      // TopLeft Player 2 
      matrix.drawRect(0, 0, 16, 8, matrix.Color333(7, 7, 0));
        // the fill
        matrix.fillRect(1, 1, 14, 6, matrix.Color333(Player_2_Collor_R, Player_2_Collor_G, Player_2_Collor_B));
      
      if (Player_2_button_seat_State == HIGH){ 
                 
          if (Player_2_Counter < 2000){
               Player_2_Collor_R = 0;
               Player_2_Collor_G = 1; 
               Player_2_Collor_B = 0;
          }
          
          if (Player_2_Counter == 2000){
               Player_2_Collor_R = 2;
               Player_2_Collor_G = 2; 
               Player_2_Collor_B= 0; 
          }
     
          if (Player_2_Counter == 4000){
               Player_2_Collor_R = 7;
               Player_2_Collor_G = 2; 
               Player_2_Collor_B = 0;          
          }
          
           if (Player_2_Counter == 6000){
               Player_2_Collor_R = 7;
               Player_2_Collor_G = 0; 
               Player_2_Collor_B = 0;
          }
          
          if (Player_2_Counter == 7000){ 
             Player_2_Counter = 0; 
           }
          
      } // if 
       if (Player_2_button_seat_State == LOW){
             Player_2_Collor_R = 0;
             Player_2_Collor_G = 1; 
             Player_2_Collor_B = 0;
             Player_2_Counter = 0;
       }
      
      // BottomRight Player 3
      matrix.drawRect(16, 8, 16, 8, matrix.Color333(7, 7, 0));
          // the fill
          matrix.fillRect(17, 9, 14, 6, matrix.Color333(Player_3_Collor_R, Player_3_Collor_G, Player_3_Collor_B));
    
      if (Player_3_button_seat_State == HIGH){ 
        
         if (Player_3_Counter < 2000){
               Player_3_Collor_R = 0;
               Player_3_Collor_G = 1; 
               Player_3_Collor_B = 0;
          }
          
          if (Player_3_Counter == 2000){
               Player_3_Collor_R = 2;
               Player_3_Collor_G = 2; 
               Player_3_Collor_B= 0; 
          }
     
          if (Player_3_Counter == 4000){
               Player_3_Collor_R = 7;
               Player_3_Collor_G = 2; 
               Player_3_Collor_B = 0;          
          }
          
           if (Player_3_Counter == 6000){
               Player_3_Collor_R = 7;
               Player_3_Collor_G = 0; 
               Player_3_Collor_B = 0;
          }
           if (Player_3_Counter == 7000){ 
             Player_3_Counter = 0; 
           }
          
      }// if 
      if (Player_3_button_seat_State == LOW){
             Player_3_Collor_R = 0;
             Player_3_Collor_G = 1; 
             Player_3_Collor_B = 0;
             Player_3_Counter = 0;
       }
    
      // TopRight Player 4
       matrix.drawRect(16, 0, 16, 8, matrix.Color333(7, 7, 0));
          // the fill
          matrix.fillRect(17, 1, 14, 6, matrix.Color333(Player_4_Collor_R, Player_4_Collor_G, Player_4_Collor_B));
    
      if (Player_4_button_seat_State == HIGH){ 
            
         if (Player_4_Counter < 2000){
               Player_4_Collor_R = 0;
               Player_4_Collor_G = 1; 
               Player_4_Collor_B = 0;
          }
          
          if (Player_4_Counter == 2000){
               Player_4_Collor_R = 2;
               Player_4_Collor_G = 2; 
               Player_4_Collor_B= 0; 
          }
     
          if (Player_4_Counter == 4000){
               Player_4_Collor_R = 7;
               Player_4_Collor_G = 2; 
               Player_4_Collor_B = 0;          
          }
          
           if (Player_4_Counter == 6000){
               Player_4_Collor_R = 7;
               Player_4_Collor_G = 0; 
               Player_4_Collor_B = 0;
          }
          
           if (Player_4_Counter == 7000){ 
             Player_4_Counter = 0; 
           }
           
      } // if 
       if (Player_4_button_seat_State == LOW){
               Player_4_Collor_R = 0;
               Player_4_Collor_G = 1; 
               Player_4_Collor_B = 0;
               Player_4_Counter = 0;
         }
   
      ////////////////////////////////////////////////////////////////
  
      Player_1_Counter ++; 
      Player_2_Counter ++; 
      Player_3_Counter ++; 
      Player_4_Counter ++;  
     
    }
   
   } // if Player_1_button_seat_State == HIGH
  else {
     //digitalWrite(ledPin, LOW);
      // BL Player 1 
      matrix.drawRect(0, 0, 32, 16, matrix.Color333(7, 7, 0));
          // the fill
     // matrix.fillRect(1, 1, 30, 14, matrix.Color333(SinglePlayer_Collor_R, SinglePlayer_Collor_G, SinglePlayer_Collor_B)); 
      
     // matrix.fillRect(1, 1, 30, 14, matrix.Color333(2, 2, 0));     // GEEL    
     // matrix.fillRect(1, 1, 30, 14, matrix.Color333(7, 2, 0));     // ORANJE 
     // matrix.fillRect(1, 1, 30, 14, matrix.Color333(7, 0, 0));     // ROOD
      
     // if (SinglePlayer_Counter > 1){
        
        if (SinglePlayer_Break_Counter == 2000){
             SinglePlayer_Collor_R = 7;
             SinglePlayer_Collor_G = 2; 
             SinglePlayer_Collor_B = 0;         
        }
        
        if (SinglePlayer_Break_Counter == 4000){
             SinglePlayer_Collor_R = 2;
             SinglePlayer_Collor_G = 2; 
             SinglePlayer_Collor_B = 0;         
        }
        
         if (SinglePlayer_Break_Counter == 6000){
             SinglePlayer_Collor_R = 0;
             SinglePlayer_Collor_G = 2; 
             SinglePlayer_Collor_B = 0;
        }
        
          matrix.drawRect(0, 0, 32, 16, matrix.Color333(7, 7, 0));
          // the fill
          matrix.fillRect(1, 1, 30, 14, matrix.Color333(SinglePlayer_Collor_R, SinglePlayer_Collor_G, SinglePlayer_Collor_B)); 
        
           
      SinglePlayer_Break_Counter ++;
  
  }
}
