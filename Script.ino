#define TRIGGER_PIN 7
#define ECHO_PIN 6    

long duracao;
float distancia;
float volumeLitros;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  duracao = pulseIn(ECHO_PIN, HIGH);

  distancia = duracao * 0.034 / 2;

  if (distancia <= 80) {
    volumeLitros = 4;
  } else if (distancia <= 160) {
    volumeLitros = 3;
  } else if (distancia <= 240) {
    volumeLitros = 2;
  } else if (distancia <= 320) {
    volumeLitros = 1;
  } else {
    volumeLitros = 0;
  }

  Serial.print("Volume: ");
  Serial.print(volumeLitros);
  Serial.println(" L");

  delay(1000);
}