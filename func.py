from ast import IsNot
import requests
import time
import json
import matplotlib.pyplot as plt

plt.switch_backend('agg')


def pVc(power, current):
    plt.plot(power, current)
    plt.xlabel('power')
    plt.ylabel('current')
    plt.title('Power Vs Current')
    # plt.show()
    plt.savefig('static/powerVscurrent.jpg')


def pVrpm(power, rpm):
    plt.plot(power, rpm)
    plt.xlabel('power')
    plt.ylabel('RPM')
    plt.title('Power Vs RPM')
    # plt.show()
    plt.savefig('static/powerVsRPM.jpg')


def cVrpm(current, rpm):
    plt.plot(current, rpm)
    plt.xlabel('current')
    plt.ylabel('RPM')
    plt.title('Current Vs RPM')
    # plt.show()
    plt.savefig('static/CurrentVsRPM.jpg')


def vVrpm(rpm):
    v = []
    for x in rpm:
        v.append((12/1500)*x)
    plt.plot(v, rpm)
    plt.xlabel('Voltage')
    plt.ylabel('RPM')
    plt.title('Voltage Vs RPM')
    # plt.show()
    plt.savefig('static/VoltageVsRPM.jpg')


url = 'https://api.thingspeak.com/channels/1595621/fields/1.json'
api = 'YA8TU83YKBCFRG5G'
header = '?results=2'
new_url = url+api+header


response = requests.get(
    'https://api.thingspeak.com/channels/1595621/feeds.json?results=40').json()
data = response['feeds']
# print(data)
power = []
current = []
rpm = []
i = 0
for x in data:
    if x['field2'] is not None:
    
       power.append(float(x['field2']))
    else:
       power.append(0)
    if x['field1'] is not None:
    
       current.append(float(x['field1']))
    else:
           current.append(0)
    if x['field3'] is not None:


       rpm.append(float(x['field3']))
    else:
           rpm.append(0)
# print(power)
# print(current)
# print(rps)

pVc(power, current)
pVrpm(power, rpm)
cVrpm(current, rpm)
vVrpm(rpm)
