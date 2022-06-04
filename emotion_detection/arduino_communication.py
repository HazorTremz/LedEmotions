import serial
import time

class ArduinoCom:

    def __init__(self):
        self.ser = serial.Serial("COM4",baudrate=9600,timeout=0.01)

    def get_data(self):
        arduino_data = str(self.ser.readline()).split("'")[1]
        return arduino_data

    def send_data(self,import_data):
        self.ser.write(f"{import_data}".encode())








