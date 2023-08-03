# Line Follower Robot Arduino Code

This repository contains Arduino code for a line follower robot. There are two versions of the code available:

1. **Line_follower.ino**: This code includes a distance sensor (ultrasonic sensor) to avoid obstacles while following the line.

2. **Line_follower_digital.ino**: This code does not include the distance sensor and focuses solely on line-following functionality.

## Line_follower.ino

### Description
This Arduino code is designed to control a line follower robot with obstacle avoidance capabilities. The robot uses three line sensors to detect the line and an ultrasonic sensor to detect obstacles in front. When the robot encounters an obstacle, it stops and waits until the obstacle is cleared.

### Hardware Requirements
- Arduino Board
- 2-Wheel Robot Chassis with Motors
- Motor Driver Module (L298N or similar)
- 3x Line Sensors
- Ultrasonic Sensor (HC-SR04 or similar)

### Connection Setup
- Line Sensors:
  - SensorLeft -> Pin 2
  - SensorCenter -> Pin 3
  - SensorRight -> Pin 4
- Motors:
  - Right Motor 1 -> Pin 12
  - Right Motor 2 -> Pin 13
  - Left Motor 1 -> Pin 10
  - Left Motor 2 -> Pin 11
- Ultrasonic Sensor:
  - Trig Pin -> Pin 7
  - Echo Pin -> Pin 6
- Servo (for obstacle avoidance):
  - Servo Signal Pin -> Pin 9

### How It Works
The robot follows a line based on the readings from the line sensors. When it detects an obstacle within 20 cm using the ultrasonic sensor, it stops to avoid the obstacle. Once the obstacle is removed, the robot resumes line-following.

## Line_follower_digital.ino

### Description
This Arduino code is a simplified version of the line follower robot code without obstacle avoidance. The robot uses three line sensors to follow the line.

### Hardware Requirements
- Arduino Board
- 2-Wheel Robot Chassis with Motors
- Motor Driver Module (L298N or similar)
- 3x Line Sensors

### Connection Setup
- Line Sensors:
  - SensorLeft -> Pin 2
  - SensorCenter -> Pin 3
  - SensorRight -> Pin 4
- Motors:
  - Right Motor 1 -> Pin 12
  - Right Motor 2 -> Pin 13
  - Left Motor 1 -> Pin 10
  - Left Motor 2 -> Pin 11

### How It Works
The robot follows a line based on the readings from the line sensors. It adjusts the motor speeds to keep the line in the center between the two outer sensors.

Feel free to use, modify, and improve the code to fit your specific robot setup and requirements.

**Note:** Please ensure that you have the required libraries installed before uploading the code to your Arduino board. If any issues arise, check the connections and adjust the pins in the code accordingly. Happy robotics!
