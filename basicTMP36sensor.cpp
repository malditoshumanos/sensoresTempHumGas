// C++ code to read values from a TMP36 sensor using an arduino

const int analogIn = A0;
int sensorOutput = 0;
// Definiendo variables
int rawValue = 0;
double voltage = 0;
double tempC = 0;
double tempF = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop()
{
  rawValue = analogRead(analogIn);
  voltage = (rawValue / 1023.0) * 5000; // Leer pin A0 para obtener valor del sensor en milivolteos 
  tempC = (voltage-498) * 0.1; // Obtener temperatura en grados centígrados
  tempF = (tempC * 1.8) + 32; // Pasar temperatura a grados farenheir
  Serial.println("RawValue: ");
  Serial.println(rawValue);
  Serial.println("mV: ");
  Serial.println(voltage, 0);
  Serial.println("Temp. in C: ");
  Serial.println(tempC, 1);
  Serial.println("Temp. in F: ");
  Serial.println(tempF, 1);
  Serial.println("\n\n");

  delay(2000);
}