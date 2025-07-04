import serial
import pymysql
import re

# 시리얼 포트 설정 (COM4 등 실제 포트로 수정)
ser = serial.Serial('COM4', 9600)

# MySQL 연결
conn = pymysql.connect(
    host='localhost',
    user='root',
    password='2580',
    database='distanceDB'
)
cursor = conn.cursor()

try:
    while True:
        line = ser.readline().decode().strip()
        print("Received:", line)

        # ex) DIST:12.3,WARN:0 형식
        match = re.match(r'DIST:(\d+\.?\d*),WARN:(\d)', line)
        if match:
            distance = float(match.group(1))
            warn = int(match.group(2))

            # DB 저장
            query = "INSERT INTO distance_log (distance_cm, warning_status) VALUES (%s, %s)"
            cursor.execute(query, (distance, warn))
            conn.commit()
            print("Saved to DB:", distance, "cm | 경고:", warn)

except KeyboardInterrupt:
    print("종료됨")
    ser.close()
    conn.close()
