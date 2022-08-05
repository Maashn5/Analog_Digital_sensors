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
