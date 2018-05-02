import requests

r = requests.get('http://www.arduino.cc/asciilogo.txt')

print(r.text)