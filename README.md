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
### Keypad sensor
