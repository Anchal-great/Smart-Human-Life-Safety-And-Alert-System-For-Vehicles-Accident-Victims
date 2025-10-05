# 🚗 Smart Human Life Safety and Alert System for Vehicle Accident Victims

## 🔍 Overview
The **Smart Human Life Safety and Alert System** is designed to detect vehicle accidents automatically and send an emergency alert to rescue services or family members.  
This system uses **Arduino**, **Impact Sensor**, **GSM**, **GPS**, **LCD Display**, and **Buzzer** to reduce response time in accidents and help save lives.

If an accident occurs, the system asks the victim through the LCD — **“Are you OK?”**  
If the person does not respond within a few seconds, it automatically sends an **SMS alert with the GPS location** to predefined emergency contacts.

---

## ⚙️ Components Used
| Component | Description |
|------------|-------------|
| Arduino UNO | Main microcontroller board |
| Impact Sensor | Detects collision or sudden impact |
| GSM Module (SIM900A) | Sends SMS alert to emergency contacts |
| GPS Module (Neo-6M) | Detects real-time location coordinates |
| LCD Display (16x2) | Displays system messages |
| Buzzer | Alerts user after collision detection |
| Push Button | Used for manual acknowledgment |
| Jumper Wires, Breadboard, Power Supply | Circuit connections |

---

## 🧠 Working Principle
1. When the **impact sensor** detects a sudden shock, the **buzzer** sounds and a message appears on the LCD asking, “Are you OK?”
2. If the victim presses the **button** (indicating they are safe), the system cancels the alert.
3. If no response is received within a preset time, the **GPS module** obtains the location.
4. The **GSM module** sends an SMS alert containing the **latitude and longitude** to emergency contacts.
5. This helps in quick rescue response and reduces fatalities caused by delayed help.

---

## 🖥️ System Workflow
1. Accident detected → Impact sensor triggers
2. LCD displays → “Are you OK?”
3. If no response → Get GPS location
4. GSM sends → SMS alert with coordinates
5. Emergency team reaches faster 🚑

---

## 🧾 Technologies Used
- Arduino IDE  
- Embedded C
- GSM & GPS Communication Protocols  
- Electronic Circuit Design  
- Real-time Monitoring

