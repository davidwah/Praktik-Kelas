import paho.mqtt.client as paho
import os
import json
import time
from datetime import datetime

broker = "localhost" #bisa disesuaikan dengan Server Broker
port = 1883

def on_publish(client, userdata, result):
    print("data published to broker \n")
    pass
client1= paho.Client("control1")
client1.on_publish = on_publish
client1.connect(broker,port, keepalive=60)

while True:
    payload="{"
    payload+="\"humidity\":60,";
    payload+="\"temperature\":22";
    payload+="}"
    ret = client1.publish("yuhu", payload)  # "yuhu" = topic, bisa diganti dengan topic yang lainnya
    print("Kirim Data!!!")
    print(payload);
    time.sleep(2)

    payload="{"
    payload+="\"humidity\":40,";
    payload+="\"temperature\":32";
    payload+="}"
    ret = client1.publish("yuhu", payload)  # "yuhu" = topic, bisa diganti dengan topic yang lainnya
    print("Kirim Data!!!")
    print(payload);
    time.sleep(1)
