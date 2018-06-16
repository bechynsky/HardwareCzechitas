import serial

# Check serial port
s = serial.Serial('COM7', 9600)

while True:
    print(s.readline().strip())

