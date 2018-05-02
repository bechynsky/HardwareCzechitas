import serial
import time

s = serial.Serial('COM9', 9600)

with open("temperature.csv", "w") as f:
    # decimal separator is . it can be issue in some regional settings
    # \n creates new line
    f.write("time;temperature\n")

    while True:
        t = s.readline().strip()
        print(t.decode('utf-8'))
        f.write("{0};{1}\n".format(time.strftime("%Y-%m-%d %H:%M:%S"), t.decode('utf-8')))

    
