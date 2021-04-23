# Pin-Art-Without-Touch
# Materials
* Arduino Uno
* ESP32-Wrover-Dev
* Gravity: PAJ7620U2 3D Gesture Sensor
* Mini Push-Pull Solenoid - 5V
* L293D IC Chip with a 4-Channel Motor Drive
* 2 DC Motors
* 1 TIP120 Power Darlington Transistor
* 1 1N4001 Diode
* 1 Pushbutton Switch
* 2 Breadboards
* Bunch of Wires
* 2 10KOhm Resistors & 1 220 Ohm Resistor
* 12V Lithium Ion Battery Pack
* 5V Rechargeable Battery
* 2 USB Cables
* Pin Art Toy
* Wooden Frame
* 8 Nylon Bearing Pulley Wheels
* 8 Screws
* Stretchy Cord
* Beading Wire
* Electrical Tape
* Cardboard
* Vineyard Vines Tie Box (sent to me by Columbia)
* 2 Chopsticks
* 1 Plastic Straw
* Hot Glue

# What does it do?
The Pin Art Without Touch system allows a user to draw on a pin art toy without actually touching it:

* The ESP32 controls two motors connected to the two corners of the homemade Etch-A-Sketch pulley system/frame
* The left motor controls the left and right movements of the "cursor" within the frame while the right motor controls the up and down movements of the "cursor" in the frame
* The ESP32 decides when to turn on each motor and in what direction based on what sensor values it is taking in from the 3D gesture sensor attached to the top of the frame
* Glued to the "cursor" is a small push-pull solenoid which is used to push the pin art toy's pins that are directly in front of it
* The pushing of the solenoid is controlled by an Arduino Uno reading input values from a pushbutton located in front of the pin art toy

# Project Overview
The project consisted of two scripts:

* The Arduino script Gesture_Controlled_Motors.ino ran on the ESP32. The script would continuously read the input sensor values coming from the 3D gesture controlled sensor. A sensor value of 1 meant that the ESP32 should drive the left motor to move the cursor right. A sensor value of 2 meant that the ESP32 should drive the left motor to move the cursor left. A sensor value of 4 meant that the ESP32 should drive the right motor to move the cursor up. And a sensor value of 8 meant that the ESP32 should drive the right motor to move the cursor down.
* The Arduino script Push_Pull_Solenoid_Pushbutton_Control.ino ran on the Arduino Uno. The script would continuously read the input value coming from the pushbutton. If/when the button was pressed the Arduino Uno would drive the solenoid high putting the solenoid in its "push" state. Then after waiting 1 second the Arduino Uno would drive the solenoid back to its low "pull" state.

# Hardware Configuration
* I used this [site](https://core-electronics.com.au/tutorials/solenoid-control-with-arduino.html) to setup the push-pull solenoid configuration
* I used this [site](https://wiki.dfrobot.com/Gravity%3A%20PAJ7620U2%20Gesture%20Sensor%20SKU%3A%20SEN0315) to setup the Gravity: PAJ7620U2 3D Gesture Sensor
* I used this [site](https://lastminuteengineers.com/l293d-dc-motor-arduino-tutorial/) to setup the L293D IC Chip to drive/control two dc motors

# Etch-A-Sketch Pulley System & Frame
In order for this project to work, I had to build a homemade Etch-A-Sketch pulley system and frame. I was able to build one by following this [video](https://www.youtube.com/watch?v=hq3Et9gOISI&t=143s). 
# Technical Issues
The hardest thing for me was building a working and reliable Etch-A-Sketch pulley system and frame that would be able to move a "cursor" with a somewhat heavy push-pull solenoid attached to it. Additionally, when looking up how to wire and power the push-pull solenoid I came across this suggestion on the Adafruit solenoid's product page: "You will need a fairly good power supply to drive a solenoid, as a lot of current will rush into the solenoid to charge up the electro-magnet, about 1 Amp, so be careful of trying to power/activate from a computer's USB." Because of this I decided to use a separate system(Arduino Uno) and power supply to drive the solenoid.

# Video
A video of my work can be found [here](https://www.youtube.com/watch?v=l5vPhq5pjL4&t=18s).
