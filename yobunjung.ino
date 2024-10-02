#define JOY_X_PIN A1        // X축 아날로그 입력 핀 A1
#define JOY_Y_PIN A0        // Y축 아날로그 입력 핀 A0
#define JOY_BUTTON_PIN 1    // Z축 버튼 디지털 입력 핀 1
#define TRIG_PIN 3          // 초음파 센서 Trig 핀 3
#define ECHO_PIN 2          // 초음파 센서 Echo 핀 2
#define SOUND_SPEED 0.034   // 소리의 속도 (cm/µs)
#define DELAY_TIME 1000     // 딜레이 시간 (밀리초)

int xValue = 0;
int yValue = 0;
int buttonState = 0;
long duration;
float distance;

void setup() {
  // 시리얼 통신 설정
  Serial.begin(9600);

  // 조이스틱 버튼 핀 설정
  pinMode(JOY_BUTTON_PIN, INPUT_PULLUP);  // 풀업 저항 사용

  // 초음파 센서 핀 설정
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // 조이스틱 값 읽기
  xValue = analogRead(JOY_X_PIN);
  yValue = analogRead(JOY_Y_PIN);
  buttonState = digitalRead(JOY_BUTTON_PIN);

  // 초음파 센서로 거리 측정
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * SOUND_SPEED) / 2;  // 거리 계산 (cm)

  // 시리얼 모니터에 조이스틱 값 출력
  Serial.print("X축: ");
  Serial.print(xValue);
  Serial.print("\t Y축: ");
  Serial.print(yValue);
  Serial.print("\t 버튼: ");
  if (buttonState == LOW) {
    Serial.print("눌림");
  } else {
    Serial.print("안 눌림");
  }

  // 쓰레기 감지 여부에 따른 출력
  if (distance <= 30) {
    Serial.print("\t 쓰레기가 들어왔습니다.");
  } else {
    Serial.print("\t 거리: ");
    Serial.print(distance);
    Serial.print(" cm");
  }

  Serial.println();  // 줄 바꿈
  delay(DELAY_TIME);
}
