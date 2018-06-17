import time
import requests
import serial

# Check serial port
s = serial.Serial('COM7', 9600)

url = ""
HEADER = {'Content-Type': 'application/json'}

while True:
    data = s.readline().decode('ascii').strip()

    # {"cas":"2018-04-01 5:34", "mv":"1234"}
    payload = {'cas': time.strftime("%Y-%m-%d %H:%M:%S"),
                'mv': data
                }

    print(payload)  

    # send payload, payload is converted to JSON
    r = requests.post(url, json = payload, headers=HEADER)

    # proper return code is 202 (Accepted), https://en.wikipedia.org/wiki/List_of_HTTP_status_codes#2xx_Success
    print(r.status_code)

