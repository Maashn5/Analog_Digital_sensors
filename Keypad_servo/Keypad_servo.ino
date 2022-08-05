#include <Servo.h>

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'.','0','#'}
};
byte rowPins[ROWS] = {13, 12, 11, 10}; //the pinouts that connected to the keypad's rows
byte colPins[COLS] = {9, 8, 7}; //the pinouts that connected to the keypad's columns

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //declare the keypad

Servo myServo;//define the servo

char digit;//the each digit of the number
String number="";//the angle of the servo but in string  
int numberOfComma=0;
float angle;


void setup(){
  myServo.attach(5);
  Serial.begin(9600);
  myServo.write(0);
  
}

void loop(){
 
   digit = keypad.getKey();//reading the keypad input
     if (digit!='#' && digit!='.' && digit!= NULL){//when the user press number
     number=number+digit;
       
     Serial.print(number);
     Serial.print("-");  
   } else if (digit=='.' ){//when the user press comma
     if (numberOfComma==0){//if he press it for the first time in this number
     number=number+digit;
     numberOfComma=1;
     Serial.print(number);
     Serial.print("-");  
     } else {//if there was a comma already in the number
     Serial.print("You can't enter 2 commas");
     }
   }else if(digit=='#'){//to turn the servo by the angle equals the number
    angle=number.toFloat();//convert the number from string type to float type
    myServo.write(angle);//turning the servo by the angle
    Serial.print(angle); 
    Serial.print("-");
    Serial.print("\n");   
    number="";
    numberOfComma=0; 
       
     
     }  

  
}
