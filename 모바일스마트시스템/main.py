import time
import RPi.GPIO as GPIO
import io
import cv2
import paho.mqtt.client as mqtt


try:
    broker_ip = "localhost"
    
	client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
	client.connect(broker_ip, 1883) # 1883 포트로 mosquitto에 접속
	client.loop_start() # 메시지 루프를 실행하는 스레드 생성

	# 카메라 객체를 생성하고 촬영한 사진 크기를 640x480으로 설정
	camera = cv2.VideoCapture(0, cv2.CAP_V4L)
	camera.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
	camera.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

	# 프레임을 임시 저장할 버퍼 개수를 1로 설정
	buffer_size = 1
	camera.set(cv2.CAP_PROP_BUFFERSIZE, buffer_size)

	# pin에 연결된 LED에 value(0/1) 값을 출력하여 LED를 켜거나 끄는 함수
	def led_on_off(pin, value):
		GPIO.output(pin, value)
  
	def measureDistance(trig, echo):
		time.sleep(0.2) # 초음파 센서의 준비 시간을 위해 필연적인 200밀리초 지연
		GPIO.output(trig, 1) # trig 핀에 1(High) 출력
		GPIO.output(trig, 0) # trig 핀 신호 High->Low. 초음사 발사 지시
		
		while(GPIO.input(echo) == 0): # echo 핀 값이 0->1로 바뀔 때까지 루프
			pass

		# echo 핀 값이 1이면 초음파가 발사되었음
		pulse_start = time.time() # 초음파 발사 시간 기록
		while(GPIO.input(echo) == 1): # echo 핀 값이 1->0으로 바뀔 때까지 루프
			pass

		# echo 핀 값이 0이 되면 초음파 수신하였음
		pulse_end = time.time() # 초음파가 되돌아 온 시간 기록
		pulse_duration = pulse_end - pulse_start # 경과 시간 계산
		return pulse_duration*340*100/2 # 거리 계산하여 리턴(단위 cm)3
	trig = 20 # GPIO20 
	echo = 16 # GPIO16
	GPIO.setmode(GPIO.BCM)
	GPIO.setwarnings(False)
	GPIO.setup(trig, GPIO.OUT)
	GPIO.setup(echo, GPIO.IN)

	GPIO.setmode(GPIO.BCM) # BCM 모드로 작동
	GPIO.setwarnings(False) # 경고글이 출력되지 않게 설정

	ledred = 6 # GPIO6 핀
	GPIO.setup(ledred, GPIO.OUT) # GPIO6 핀을 출력으로 지정
	ledblue = 5 # GPIO5 핀
	GPIO.setup(ledblue, GPIO.OUT) # GPIO5 핀을 출력으로 지정
	print("LED를 지켜보세요.")
	
	while True :
		distance = measureDistance(trig, echo)
		time.sleep(0.5) # 0.5초 간격으로 거리 측정(0.3으로 하면 정확)
		print("물체와의 거리는 %fcm 입니다.." % distance)
		if distance < 10 : # 물체와의 거리가 10cm 이내이면
			led_on_off(ledred, 1) # 모든 LED 켜기
			led_on_off(ledblue, 1)
				# 버퍼에 저장된 모든 프레임을 버리고 새 프레임 읽기
		for i in range(buffer_size+1): 
			ret, frame = camera.read()
			im_bytes = cv2.imencode('.jpg', frame)[1].tobytes() # 바이트 배열로 저장
			client.publish("jpeg", im_bytes, qos = 0) # 이미지 전송
		elif distance < 20 : # 물체와의 거리가 10~20cm 이내이면
			led_on_off(ledred, 1) # 빨간 LED 키기
			led_on_off(ledblue, 0)
		else :
			led_on_off(ledred, 0) # 모든 LED 끄기
			led_on_off(ledblue, 0)
except KeyboardInterrupt:
	print("Ctrl+C 종료")
finally:
	print("cleanup")
	GPIO.cleanup()
