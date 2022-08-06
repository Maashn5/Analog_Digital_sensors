# Analog_Digital_sensors
## Analog sensor
Analog signal represent continuous value of certain interval over time
<br/> ![alt text](https://media.monolithicpower.com/wysiwyg/1_33.png)
<br/> Most physical variable are analog quantity, such as sound , voltage , temperature , pressure... etc 
<br/> Physical variables converted to electrical signal by trnsducer

### temperature sensor
<br/> - TMP36 is a temperature sensor has 3 pinsout 
<br/> - power pin:connected to 5V pin in arduino 
<br/> - volt out:connected to the analog input pins in the arduino 
<br/> - Ground pin:connected to GND pin in arduino 
<br/> Here is the circuit
![alt text](https://github.com/Maashn5/Analog_Digital_sensors/blob/main/temp_sensor/temp%20sensor.png)
<br/> Here is the code 
<br/> 
```c++
double voltage; // the measuring voltage
double temp;// the temprature

void setup()
{
  Serial.begin(9600);// to write the value of the temprature
}

void loop()
{
  voltage=analogRead(A1);//reading the voltage
  temp= map(voltage,20,358,-40,125);
  // rescale the voltage to give correct temprature value
  Serial.print("the temprature is : ");
  Serial.print(temp);//writing the temprature value
  Serial.print("\n");
  delay(100);
}
```
[The simulation link for the circuit](https://www.tinkercad.com/things/jS53LmocLvb?sharecode=vfRGOmExMJKqRqMVgxfUARb6XkhjaYCzv2hwj09wE8c)
## Digital sensor 
Digital signal represent discrete value of certain interval over time
<br/> ![alt text]([https://media.monolithicpower.com/wysiwyg/1_33.png](https://www.researchgate.net/profile/Ade-Handayani/publication/331955858/figure/fig4/AS:739246918885383@1553261608781/Representation-digital-signal-in-eletricity-gain.jpg))
<br/> some physical variable represent in digital signal, such as Phase of an electromagnetic field , Acoustic pressure , The magnetization of a magnetic storage media ... etc 
<br/> Analog signal is converted to digital by ADC
### Keypad sensor
<br/> Keypad is a char input digital sensr has 8 pinsout 
<br/> 4 rows , 4 columns
<br/> by the keypad we can enter numbers ,letters & symbols
<br/> in this circuit , controlling the servo angle by the input of the key pad 
<br/> Here is the circuit
![alt text](https://github.com/Maashn5/Analog_Digital_sensors/blob/main/Keypad_servo/keypad%20with%20servo.png)
<br/> Here is the code 
<br/> 
```c++
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
}
```
[The simulation link for the circuit](https://www.tinkercad.com/things/8N8248V3Llg?sharecode=pyAjzavHZ5CAz8d6ok4l83a5lgwBcwAqSPxbQ6StPu4)
