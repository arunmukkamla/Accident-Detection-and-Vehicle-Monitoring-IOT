# Vehicle Accident Detection and Monitoring using Arduino UNO and ESP8266
&nbsp;

> ## Introduction

Yearly the road accident rate increases, and drivers are to blame as well as the road or weather conditions. Bad Vehicle drivers can't be helped, but the vehicle can be made smart enough to alert the ambulance about the location
We can also monitor the status of the vehicle and one can view the changes in the sensor data accordingly on the ThingSpeak Cloud in the Field section.

&nbsp;
> ## Components Required
* Arduino Uno
* Wi-Fi module(ESP8266)
* ThingSpeak Cloud
* Vibration Sensor
* Temperature Sensor(LM35)
* Jumper Wires (Male-to-Male and Male-to-Female)
* Breadboard or PCB
* Few Red LED's and Green LED's

&nbsp;
> ## Working of the System
* The Internet of Things (IoT) is a network of electronic and physical devices, vehicles, sensors which enables them to collect and exchange data.
* Our prototype consists of a Vibration sensor, temperature sensor and any additional sensor (like accelerometer) attached to a vehicle. Vehicle consists of a microcontroller (Arduino) and a Wi-Fi module(ESP8266).
* These sensors output data is collected and sent to the cloud i.e., an open source cloud for data storage and analysis namely –THINGSPEAK. At ThingSpeak these sensors data are analysed and a graph is plotted and vehicle performance analysis is done monthly and weekly depending on the requirement. By this when the vehicle needs service can be estimated and a tweet can be sent through twitter(only if the details of one's twitter account are shared in the thingspeak's channel settings).
 
This project can be extended with the help of GSM and GPS modules to give the precise location of the vehicle in order to detect any accident.
&nbsp;
> ## AT Commands for Wi-Fi Module
* AT commands are instructions used to control a modem. AT is the abbreviation of ATtention. Every command line starts with "AT" or "at". That's why modem commands are called AT commands. There are Various AT commands which are used to control the modem.
* You can study more about AT commands for Wi-Fi from this link:<br />
https://nurdspace.nl/ESP8266#AT_Commands 

&nbsp;
> ## Connection of Arduino Uno to ESP8266
![alt text](https://labbh.files.wordpress.com/2016/05/firmware.png?w=1108)
> ## Pinout of ESP8266
![alt text](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcTtBJ7LjUMHzgehvLo43ppoZvt1vRH7hb222Q&usqp=CAU)

We can add upto 18 different digital sensors to a single arduino controller at once(with the help of an I2C module), and we can add upto 6 analog sensors. One can add any valid sensor available to him/her to this project to make it a unique project, because the functionality of the ESP8266 and arduino remains same irrespective of their problem statement.

&nbsp;
> ## Small tutorial to set up a ThingSpeak Account and to upload the sensor data
![alt text](https://github.com/akhilkumar99/Vehicle-Accident-detection/blob/master/sign%20in%20into%20thingspeak.JPG)

* Sign in into ThingSpeak account through MathWorks account, if you don't have a matlab account then create one for free.
* You can click on this link to redirect to ThingSpeak.com: https://thingspeak.com/login
![alt text](https://github.com/akhilkumar99/Vehicle-Accident-detection/blob/master/create%20a%20new%20channel.JPG)

* After signing into your ThingSpeak account you will have a similar view as shown in the above image, I have created 4 channels, those are not pre existent. One has to create a new channel for uploading the sensor data, You can create a channel by clicking on the new channel.
![alt text](https://github.com/akhilkumar99/Vehicle-Accident-detection/blob/master/api%20keys.JPG)

* After creating a channel it looks mostly like this as shown above, now click on the API Keys to generate your API keys that must be used in the source code.

![alt text](https://github.com/akhilkumar99/Vehicle-Accident-detection/blob/master/API%20Read%20and%20Write%20Keys.JPG)

* Copy the Write API key to the code. WRITE API Key is used to upload the sensor data to the thingspeak channel (Never share your WRITE API keys to others to avoid any misuse).
* After entering the WRITE API key, and after succesful connection of the ESP8266 module to the Arduino Uno, Switch on the circuit and give some stimuli to the sensor.
* This stimulus is noted in the field channel of your ThingSpeak Channel. Continuos change of the data can be tracked and the ThingSpeak will automatically plot the data variations as shown below.
![alt text](https://github.com/akhilkumar99/Vehicle-Accident-detection/blob/master/ldr%20data%20thingspeak.JPG)

* you can see i have changed the channel, because there was no data uploaded to the temp_val channel. You can create as many channels you want, but the data upload limit is fixed by the ThingSpeak. You have to buy for additional data from ThingSpeak. 
* This raw data can also be modified into various plots with the help of MATLAB Analysis(for that one must know MATLAB programming).
