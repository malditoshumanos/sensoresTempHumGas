// Código para controlar un arduino. 

#include <LiquidCrystal.h> // Para controlar la pantalla LCD

const int LEDpinTemp = 2;
const int TMP36pin = A2;
const int LEDpinGas = A1;
const int MQ2pin = A0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
	Serial.begin(9600);
	pinMode(TMP36pin, INPUT);
	pinMode(MQ2pin, INPUT);
	pinMode(LEDpinGas, OUTPUT);
	pinMode(LEDpinTemp, OUTPUT);
}

void loop(){
	// Controlar sensor de gas 
	float sensorValue, MQ2pin;
	sensorValue = analogRead(MQ2pin); 
	Serial.print("\nLectura sensor de gases: ");
	Serial.print(sensorValue);

	if(sensorValue >= 470){
		digitalWrite(LEDpinGas, HIGH);
		Serial.print(" - Humo detectado. El sensor da un valor mayor a 470. LED encendido.");				
	}else{
		digitalWrite(LEDpinGas, LOW);		
	}

	//Controlar sensor de temperatura
	int rawValue = 0;
	float voltaje = 0;
	float tempC = 0;

	rawValue = analogRead(TMP36pin);
	voltaje = (rawValue/1023.0) * 5000; // Obtener voltaje en milivolteos del sensor TMP36
	tempC = (voltaje-498) * 0.1; // Obtener temperatura en grados centígrados

	Serial.print("\nLectura sensor de temperatura en grados celsius: ");
	Serial.print(tempC, 1);

	if(tempC < 20 || tempC > 45){
		digitalWrite(LEDpinTemp, HIGH);
		Serial.print(" - Temperatura extrema detectada. LED encendido.");
	} else {
		digitalWrite(LEDpinTemp, LOW);
	}


	delay(1000);
}