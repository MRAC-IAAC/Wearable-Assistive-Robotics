## Wearable Assistive Robotics



Aim of this project was to develop a wearable assistive robotics for transferring human motion from one person to another. We focused on developing a wearable exoskeleton arm using EMG and IMU sensors.
![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/poster.jpg "Poster")


### Concept
The idea of the project is to design 2 arms, one for sensing and another for actuation. Sensing arm(master) for analyzing the movements of the person wearing it and it transfers the movements wirelessly to the actuating arm(host). The Actuating arm receives & detects the signals and actuates the mechanical devices responsible to the relevant joint movement/s.
![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/Concept.jpg "Poster")
Concept

### What is EMG ?
Electromyography is an electrodiagnostic medicine technique for evaluating and recording the electrical activity produced by skeletal muscles. EMG is performed using an instrument called an electromyograph which produces a record called an electromyogram.The same electrical activity can be used to actuate mechanical devices such as servo motor, pneumatic actuators, stepper motors, etc.

### First Prototype
For the first prototype, we used:

EMG sensor

25k/cm servo motor

3d printed(PETG) wearable arm model

![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/1st_prototype_diagram.jpg "Poster")


Below image for refence. As demonstrated below, the EMG sensor detects the arm movement (in this case the elbow muscle flexion) and actuates the servo motor.
![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/1sr_prototype_git.gif "Poster")


First prototype was more of a experiment to understand "How the EMG work" and to understand the data received from it.

The data received from EMG sensor contained noise due to quality of EMG sensor(Hobby EMG sensor for Arduino). The movement of servo were not very precise due to noise.

So we decided to use IMU(MPU 9250) with EMG in order to get better quality signals and have a better control on movement.


### Second Prototype
Further to the first prototype, we made the following update/changes in the second prototype:

EMG setup made stable - servo responded better, using stable wiring.

Sensors - W.r.t problems faced during first prototype, we tested other sensors with EMG to get better response from servo. and finally narrowed down to IMU(MPU 9250) which is a 9 axis. and has gyroscope, accelerometer and compass.

Prototype - Prototype design upgraded. Complete arm model 3d printed.

Servo replaced by Pneumatic air Muscles. It is a combination of latex tube, with braided cable casing. which works amazing a heavy load lifting and has a high amount of contraction/expansion(similar to human muscle)

MQTT setup for the wireless signal transfer between the 2 arm.

![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/2nd_prototype.gif "Poster")

### What is MQTT
MQTT protocol is based on publish and subscriber paradigm. A client that published the messages, called “Publisher” to the other client, called “Subscriber” who receive the message.

MQTT is asynchronous where HTTP is synchronous so it does not block the client while it waits for the message.

It does not require that client(subscriber) and the publisher are connected at the same time.
![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/MQTT.png "Poster")

### Setup
The base concept remain the same, but we upgraded some of the components and made the whole system bit more mature.

Admin sleeve upgraded with EMG+IMU(MPU) connected to Arduino, connected to Raspberry Pi 4. MQTT server was setup on a PC which takes commands from admin and transfers it to the host sleeve. The host sleeve consists of Raspberry Pi4 which received commands from the MQTT broker(PC) and sends it to Arduino. And as a results Arduino actuates the Pneumatic muscles.

Addition to the above, we also upgraded the Host arm with a IMU to keep a track of the movement of the host arm. Main purpose of the IMU is to keep track of both the arms location, so that both are aligned with each others motion.

![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/2nd_prototype_setup.JPG "Poster")

![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/2nd_prototype_Schematic.JPG "Poster")



### EMG Data Analysis with Python
As mentioned above, the data received from EMG contains noise, so we explored methods to filter the data and understand the information received from the data.

During this process,

The data transmitted to the PC and saved in a CSV file

Data plotted/visualized in Python

Data remapped with filtering the values of 20 and below

Negative muscle flexion removed as a normal procedure of EMG data analysis. EMG takes positive and negative muscle flexion, only one of the reading is sufficient to actuate device or to visualize. EMG data provides a lot of information such as movements of muscles, muscle fatigue. As normal muscle show changes in EMG reading when it is exposed to a long duration of movement. These characteristics were observed during the EMG data recording and analysis. These can play an important role in development of this project.

![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/EMG_data_filtering.JPG "Poster")

### Third Prototype (Final Prototype)
We observed a need to develop this project further, as a result we made changes in the second model. The major modifications were:

3d model upgraded and made more practical and confirmable.

The prototype extended till the hand (Second model covered only the arm).

We added 1 additional pneumatic muscle for wrist joint (Second model has one pneumatic for elbow only).

3 IMU each on both the models. (Total 6 IMU).

The sensing arm was made using normal cotton full arm gloves, over which all the IMU, wiring, etc. were mounted.

Admin arm was installed with a pneumatic solenoid which was further connected with  a regulator. IMU movement controlled the regulator which can alter the amount of air passing through the solenoid. EMG sensor controls the solenoid valve. this whole system give more stability to the setup and control of air flow is better w.r.t arm movement.

Arduino and Raspberry Pi 4 were replaced with ESP8266. This helped us to create a more compact setup

MQTT server transferred to Raspberry Pi 4 which had its own MQTT WiFi broker in order to avoid changing networks(SSID) every time.

![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/3d_prototype_muscle_demo.JPG "Poster")

![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/3d_prototype_setup.JPG "Poster")


### IMU Data Analysis
Similar to EMG data, IMU data also had noise and to get appropriate readings the data requires cleaning. We explored one of the efficient methods for IMU data cleaning in realtime. The method is "Madwick Filter".

The Madgwick filter formulates the attitude estimation problem in quaternion space. The general idea of the Madgwick filter is to estimate W I q t + 1 by fusing/combining attitude estimates by integrating gyro measurements W I q ω and direction obtained by the accelerometer measurements.

![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/IMU_data_filtering.JPG "Poster")


### 3d Prototype Schematic
![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/3d_prototype_schematic.JPG "Poster")

### Additional experiments
During the whole project, we performed multiple of experiments to explore the potentials of this project which includes tests with air muscles, EMG response testing with gaming, actual prototype testing while wearing.


![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/additional_experiments.gif "Poster")

![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/orestis_test-cropped.gif "Poster")




### Final Prototype Images
![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/Final_prototype.jpg "Poster")

![alt text](https://github.com/MRAC-IAAC/Wearable-Assistive-Robotics/blob/main/Images/Final_prototype2.jpg "Poster")

Wearable assistive Robotics // H.2  is a project of IAAC, Institute for Advanced Architecture of Catalonia
developed at Master in Robotics and Advanced Construction Hardware II Seminar in 2020/2021 by:

Students: Charng Shin Chen, Shahar Abelson, Orestis Pavlidis, Arpan Mathe

Faculty: Óscar González
Faculty Assistant: Antoine Jaunard
