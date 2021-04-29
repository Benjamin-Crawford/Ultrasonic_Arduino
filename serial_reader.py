import serial
import time
import csv

ser = serial.Serial(
port = "\\.\COM5",
baudrate = 9600,
bytesize = serial.EIGHTBITS, 
parity = serial.PARITY_NONE,
stopbits = serial.STOPBITS_ONE, 
timeout = 1,
xonxoff = False,
rtscts = True,
dsrdtr = True,
writeTimeout = 2
)
ser.flushInput()

while True:
    try:
        ser_bytes = ser.readline()
        decoded_bytes = ser_bytes[0:len(ser_bytes)-2].decode("utf-8")
        readings = decoded_bytes.split(" ")[1:-1]
        i = 0
        for reading in readings:
            print("Sensor {}: {} cm".format(i,reading))
            i+=1
            

        with open("C:\\Users\\ben99\\Desktop\\ECE191_Test_Data\\HC_SR04_122_cm_error_test_data.csv","a") as f:
            writer = csv.writer(f,delimiter=",")
            writer.writerow([time.time(),decoded_bytes])
    except Exception as e:
        print(e)
        break