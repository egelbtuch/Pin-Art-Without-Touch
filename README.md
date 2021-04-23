# Pin-Art-Without-Touch
# Materials
* Arduino Uno
* ESP32-Wrover-Dev
* Gravity: PAJ7620U2 3D Gesture Sensor for Arduino
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
The project consisted of three scripts:

* The Arduino script Conveyer_Belt.ino that ran on the ESP32 which waited for the class web-server/API to return a string valued "true". I used this [link](https://randomnerdtutorials.com/esp32-http-get-post-arduino/) to setup the WIFI on the ESP32 and to setup the ESP32 for communication with the class web-server/API. Once the ESP32 reads "true" from the web-server/API the motors will start moving left and right in a loop until the ESP32 is shutoff or reset. If reset the ESP32 will again look for a "true" string on the web-server/API.
* The Arduino script Light_Sensor_and_LEDs.ino that ran on one of the Arduino Unos. The script was used to control the 4-digit 7-segment display(scoreboard) and took in two inputs. One input was from a SPDT switch and the other input was from a photoresistor located in the basket of the hoop. If the state of the switch changed the scoreboard would reset to zeros. The script would also check the analog input coming from the photoresistor and check if it was below a predefined threshold value, which would result in the scoreboard being updated to plus one of the current value(this signified a scored basket). I setup the 4-digit 7-segment display with the help of this [link](https://www.instructables.com/4-Digit-7-Segment-Timer-With-Reset-Button/).
* The Arduino script Servo-Potentiometer.ino that ran on the other Arduino Uno. It would continuously read the input analog signal from the potentiometer and would translate that value to an angle for the servo to move to.

# Technical Issues
The hardest thing for me was building a "conveyer belt" system that would not fall apart and break every second and one that can hold/balance the weight of the mini hoop! Another issue I had was trying to figure out a way to sense a ball going through the hoop. I ended up using a photoresistor and a piece of cardboard that would cover the photoresistor when a ball went through but this way of sensing was very inconsistent. Finally, I tried using the ESP32 to communicate serially with the Arduino Uno(over their respective serial pins) so the ESP32 could tell the Arduino Uno(does not have WIFI onboard and thus could not read from web-server/API) when the web-server/API read "true". However, this was not working at all so I decided not to do it.

# Video
A video of my work can be found [here](https://www.youtube.com/watch?v=fLeUoNfXLaA).
