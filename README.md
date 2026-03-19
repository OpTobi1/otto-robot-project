# Walking Toy Robot (רובוט צעצוע מהלך) 🤖

This repository contains the source code and documentation for our high school final project in Electronics and Computers (2020). 
The project is a bipedal walking robot inspired by the Otto DIY robot, capable of walking, avoiding obstacles, making sounds, and showing facial expressions.

## Documentation 📄
All detailed information regarding the project, including theoretical background, electrical schematics, block diagrams, and the full building process, can be found in the attached project book (Hebrew):
[Book Two Legged Robot Full 11_05_2020.pdf](Book%20Two%20Legged%20Robot%20Full%2011_05_2020.pdf)

## Features
* **Bipedal Walking:** Uses 4 servo motors for movement.
* **Obstacle Avoidance:** Utilizes an HC-SR04 ultrasonic sensor to detect distances and avoid crashing.
* **Facial Expressions:** Displays emotions (like smiling) using an 8x8 LED Matrix.
* **Sound Effects:** Uses a buzzer to play different frequencies and tones.

## Hardware Components
* Arduino (Nano / Uno)
* 4x SG90 Micro Servo Motors
* 1x HC-SR04 Ultrasonic Distance Sensor
* 1x MAX7219 8x8 LED Matrix
* 1x Passive Buzzer
* 3D Printed Chassis (Otto DIY based)

## Pin Configuration (Arduino)
| Component | Pin(s) |
| :--- | :--- |
| **Ultrasonic Sensor** | Trig = 13, Echo = 12 |
| **LED Matrix** | DIN = 4, CS = 3, CLK = 2 |
| **Buzzer** | 7 |
| **Servo Motors** | 8, 9, 10, 11 |

## Authors
* **Liav Lugassi** (ליאב לוגסי)
* **Omri Yosef Malka** (עומרי יוסף מלכה)

*Supervised by: Sergio Priborkin*

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
