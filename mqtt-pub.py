import sys
import paho.mqtt.client as paho
import warnings
warnings.filterwarnings("ignore", category=DeprecationWarning)

client = paho.Client()

while True:
    if client.connect("localhost", 1883, 60) != 0:
        print("Couldn't connect to the mqtt broker")
        sys.exit(1)

    # Start the loop in the background
    client.loop_start()  # This keeps the connection open and allows messages to be processed

    print("\nSelect an option to publish:")
    print("1. Battery percentage")
    print("2. Speed")
    print("3. Inclination")
    print("4. Exit")

    choice = input("Enter your choice (1-5): ")

    if choice == "1":
        battery_percentage = input("Enter battery percentage: ")
        client.publish("vehicle/batteryPercentage", battery_percentage, 1)
    elif choice == "2":
        speed = input("Enter speed: ")
        client.publish("vehicle/speed", speed, 1)
    elif choice == "3":
        inclination = input("Enter inclination: ")
        client.publish("vehicle/inclination", inclination, 1)
    elif choice == "4":
        client.publish("test_topic", "Disconnecting from the MQTT broker", 1)
        print("Disconnecting from the MQTT broker")
        client.disconnect()
        client.loop_stop()  # Stop the loop after disconnect
        break
    else:
        print("Invalid choice, please select a number between 1 and 5.")
