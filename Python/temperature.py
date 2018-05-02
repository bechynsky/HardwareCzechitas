import serial
import time

s = serial.Serial('COM9', 9600)

while True:
    print(s.readline().strip())

