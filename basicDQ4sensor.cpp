const int LEDpin = A1;
const int MQ2pin = A0;

void setup(){
	Serial.begin(9600);
}

void loop(){
	float sensorValue, MQ2pin;
	sensorValue = analogRead(MQ2pin); 

	if(sensorValue >= 470){
		digitalWrite(LEDpin, HIGH);
		Serial.print("Humo detectado. El sensor da un valor mayor a 470. Valor del sensor: ");		
		Serial.println(sensorValue);
		
	}else{
		digitalWrite(LEDpin, LOW);
		Serial.print("Valor del sensor: ");
		Serial.println(sensorValue);
	}

	delay(1000);
}