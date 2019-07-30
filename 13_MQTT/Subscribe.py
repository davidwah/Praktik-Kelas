import paho.mqtt.client as paho
import time
import sys
import datetime
import time

broker = "localhost" #bisa disesuaikan dengan Server Broker. Free Server Broker Public "broker.hivemq.com"
topic = "yuhu"  # "yuhu" = topic, bisa diganti dengan topic yang lainnya

def on_message(client, userdata, message):
    print("recived data is: ")
    print(str(message.payload.decode("utf-8")))
    print("")

client = paho.Client("user")
client.on_message=on_message

print("Connecting to broker host", broker)
client.connect(broker)
print("subscribing begins here")
client.subscribe(topic)

while 1:
    client.loop_start()