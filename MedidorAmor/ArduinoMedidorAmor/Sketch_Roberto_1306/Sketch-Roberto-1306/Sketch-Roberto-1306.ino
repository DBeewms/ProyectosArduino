const int sensorPin = A0;
const float baselineTemp = 36;
int led1 = 2, led2 = 3, led3 = 4;
 float temperature=0;

void leertemperatura() {
  int sensorVal = analogRead(sensorPin);
  //Serial.print("sensor Value: ");
  //Serial.print(sensorVal);

  float voltage = (sensorVal / 1024.0) * 5.0;
  //Serial.print(", Volts: ");
  //Serial.print(voltage);

  temperature = (voltage - 0.5) * 100;
  //Serial.print(", degrees C: ");
  Serial.print(temperature);
  Serial.println("-");
}

void setup() {
  //Inicializar Sensor de Temperarura
  Serial.begin(9600);
  //Inicializar y apagar Leds
  pinMode(led1, OUTPUT);
  digitalWrite(led1, LOW);
  pinMode(led2, OUTPUT);
  digitalWrite(led2, LOW);
  pinMode(led3, OUTPUT);
  digitalWrite(led3, LOW);
}

void loop() {
  int tiempoEspera = 3;
  
  // Leer Temperatura
  leertemperatura();

  // Almacenar la temperatura actual
  //float temperature = (analogRead(sensorPin) / 1024.0) * 5.0;
  //temperature = (temperature - 0.5) * 100;

  // Animación Calculando
  if (temperature > baselineTemp + 2) {
    tiempoEspera = 3;

    do {
      if (tiempoEspera < 1000) {
        digitalWrite(led3, LOW);
        digitalWrite(led1, HIGH);
        delay(tiempoEspera);
        tiempoEspera += random(30, 101);
      }

      if (tiempoEspera < 1000) {
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        delay(tiempoEspera);
        tiempoEspera += random(30, 101);
      }

      if (tiempoEspera < 1000) {
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        delay(tiempoEspera);
        tiempoEspera += random(30, 101);
      }
    } while (tiempoEspera < 1000);

    // Leer Temperatura de Nuevo Para Mostrar Resultado Final
    leertemperatura();
    
    // Almacenar la temperatura actual
    //float temperature = (analogRead(sensorPin) / 1024.0) * 5.0;
    //temperature = (temperature - 0.5) * 100;

    // Muestra de Resultado
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    if (temperature < baselineTemp + 2) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    } else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    } else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
    } else if (temperature >= baselineTemp + 6) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
    }

    delay(3000);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
}
