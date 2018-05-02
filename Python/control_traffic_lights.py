import serial
import time

with serial.Serial('COM9', 9600) as s:
    while(1):
        s.write(b'0')
        s.flush()
        time.sleep(3)
        s.write(b'1')
        s.flush()
        time.sleep(1)
        s.write(b'2')
        s.flush()
        time.sleep(3)
        s.write(b'3')
        s.flush()
        time.sleep(1)
