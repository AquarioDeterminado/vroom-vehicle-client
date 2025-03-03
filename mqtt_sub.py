import sys

import paho.mqtt.client as paho
import warnings
warnings.filterwarnings("ignore", category=DeprecationWarning)


def message_handling(client, userdata, msg):
    print(f"{msg.topic}: {msg.payload.decode()}")


client = paho.Client()
client.on_message = message_handling

if client.connect("localhost", 1883, 60) != 0:
    print("Couldn't connect to the mqtt broker")
    sys.exit(1)

# basic information sent from the client (not supposed to be here just for debugging proposes)
client.subscribe("vehicle/batteryPercentage")
client.subscribe("vehicle/speed")
client.subscribe("vehicle/inclination")
client.subscribe("vehicle/temperature")
client.subscribe("test_topic")

# information channel of received information
client.subscribe("ui/moves")


try:
    print("Press CTRL+C to exit...")
    client.loop_forever()
except Exception:
    print("Caught an Exception, something went wrong...")
finally:
    print("Disconnecting from the MQTT broker")
    client.disconnect()

