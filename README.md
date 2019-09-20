# CSE 316 Project - January 2018
# Smart Traffic Signal Control System
## A Brief Description
In this Project we have designed a smart traffic signal control system which automatically detects traffic jam and decides which lane should be opened.

If there is no traffic jam in any lane, the system sequentially keeps open one lane one after another. But if there is traffic jam in one or more lanes, the system serves the lane in which traffic jam occured first.

## Required Equipments
* ATmega32 microcontroller
* Sonar or Ultrasonic Sensor(HC SR04)
* LED

## How it works?
In this project ATmega32 microcontroller is used for interfacing to various hardware peripherals. The system has to determine whether there is traffic jam in any road. For doing so, we need to install a sonar above each lane of the road at a certain distance apart from the traffic signal. As the position of the sonar above any lane is fixed, if a vehicle comes below the sonar, the distance measured by sonar will be less than the distance between the sonar and the road. That is, the sonar can detect vehicle using this logic.

If the vehicle stands still for a certain period for instance two minutes, we will consider this situation as traffic jam. The sonar informs this incident to the microcontroller connected to it. There is one microcontroller for each lane and also a main controller which is basically another microcontroller that collects information from the microcontrollers connected to it. The main controller then decides which road should be opened. It sends signals to its descendent microcontrollers to turn on the green signal or the red signal. The time duration for which a green signal or red signal will be turned on is also decided by the main controller

When a descendent microcontroller sends the main controller that there is traffic jam in the road corresponding to sender, the main controller then finsishes serving the current road and then serves the jam packed road.

## Block Diagram
![Context Diagram Example](https://user-images.githubusercontent.com/33763183/65350495-ac977680-dc07-11e9-8795-7cb2970a84d3.jpeg)

## Algorithm
The algorithm has two context:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1. Microcontroller responsible for each road. <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2. Main controller microcontroller.
<br><br/>
### Algorithm for microcontroller responsible for each road: <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1. Start.<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2. If the signal sent by the main controller is to turn on green signal, turn on green signal <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3. Otherwise, turn on red signal<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4. Use sonar to detect if there is any vehicle below the sonar<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;5. If there is any vehicle, start timer<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;6. If the timer is greater than certain time duration lets say two minutes, inform main controller that there is traffic jam in your lane<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;7. Otherwise, keep the timer on.<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;8.Else, clear the timer<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;9. Goto (2)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;10. End.<br/>
<br><br/>
### Algorithm for the main controller:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1. Start.<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2. Check whether there is traffic jam in any road.<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3. If any road is jam packed, inform the microcontroller corresponding to that road to turn on green signal for a certain predefined period of time.<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4. Otherwise, one by one inform a microcontroller to turn on green signal for certain period while others to turn on red signal.<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;5. Goto (2).<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;6. End.<br/>
      
## Detailed Pin Diagram

## Problems Faced
1. The ATmega32 has 3 timers. We have used timer1 for the sonar while timer0 for determining the time duration a vehicle remains stand still. That's why we have to use one microcontroller for each lane of any road. This leads to increased number of microcontrollers
2. The systems performs badly if two or more lanes become jam packed. In that case, the system serves only the jam packed roads while the other roads remains unserved.

## Group Members Information
- Md. Hasin Abrar (1605082)

- Khandakar Asif Ahmed (1605085)

- Abdur Rahman Fahad (1605069)

## Course Teachers
1. Tareq Mahmud<br/>
Lecturer, CSE, BUET

2. Md. Masum Mushfiq<br/>
Lecturer, CSE, BUET
