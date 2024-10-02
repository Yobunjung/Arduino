#TRIG_PIN 3 // 초음파 센서 트리거 핀 2 정의
#에코 정의PIN 2 // 초음파 센서 Echo 핀 3
#SOUND_SPEED 0.034 // 소리의 속도 정의(cm/µ)
#지연 정의TIME 10 // 딜레이 시간 (밀리초)

긴 지속 시간;
부유 거리;

() {설정 무효화
 // 시리얼 통신 설정
 직렬.시작(9600);

 // 초음파 센서 핀 설정
 pinMode(TRIG_PIN, 출력);
 pinMode(ECHO_PIN, INPUT);
}

보이드 루프 () {
 // 초음파 센서로 거리 측정
 디지털 쓰기(TRIG_PIN, LOW);
 지연마이크로초(2);
 디지털 쓰기(TRIG_PIN, HIGH);
 지연마이크로초(10);
 디지털 쓰기(TRIG_PIN, LOW);

 듀레이션 = pulseIn(ECHO_PIN, HIGH);
 거리 = (duration * SOUND_SPEED) / 2; // 거리 계산 (cm)

 // 시리얼 모니터에 출력
 Serial.print("거리": ";
 Serial.print(거리);
 Serial.println("cm");

 지연(DELLAY_TIME);
}
