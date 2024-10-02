#define TRIG_PIN 3          // 초음파 센서 Trig 핀 2
#define ECHO_PIN 2          // 초음파 센서 Echo 핀 3
#define SOUND_SPEED 0.034   // 소리의 속도 (cm/µs)
#define DELAY_TIME 10     // 딜레이 시간 (밀리초)

long duration;
float distance;

void setup() {
  // 시리얼 통신 설정
  Serial.begin(9600);

  // 초음파 센서 핀 설정
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // 초음파 센서로 거리 측정
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * SOUND_SPEED) / 2;  // 거리 계산 (cm)

  // 시리얼 모니터에 출력
  Serial.print("거리: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(DELAY_TIME);
}
