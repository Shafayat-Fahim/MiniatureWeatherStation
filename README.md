### Miniature Weather Station

In this repository, we will work on our Microprocessor, Interfacing and Assembly Language project, which involves constructing and running a Miniature Weather Station. This project is a **Miniature Weather Station** designed using an **ESP8266 + Mega2560 hybrid board** to collect, process, and upload environmental data to **ThingSpeak** over WiFi. It leverages multiple sensors to measure temperature, humidity, air quality (eCO₂ and TVOC), and wind speed.

---

## 🧠 Project Objectives

- Collect real-time environmental data from surroundings.
- Transmit the data wirelessly to a cloud platform (ThingSpeak) for monitoring and visualization.
- Utilize a hybrid board to combine WiFi and sensor communication seamlessly.
- Serve as a foundational prototype for future smart agriculture, weather forecasting, or pollution monitoring systems.

---

## 🔧 Hardware Components

| Component         | Description                                                                 |
|------------------|-----------------------------------------------------------------------------|
| **Mega2560 + ESP8266 Hybrid Board** | A microcontroller board combining ATmega2560 and ESP8266 WiFi module. |
| **AHT21**         | Temperature and humidity sensor by Adafruit (I2C).                          |
| **ENS160**        | Air quality sensor (measures eCO₂ and TVOC) by DFRobot (I2C).               |
| **Analog Anemometer** | Measures wind speed by generating voltage proportional to wind force.  |
| **Jumper Wires**  | For sensor and module connections.                                          |
| **Breadboard / PCB** | Used for prototyping sensor connections.                                |
| **WiFi Access Point** | Required for ESP8266 to connect and transmit data.                    |

---

## 🧪 Sensor Measurements

| Sensor     | Measurement      | Unit        |
|------------|------------------|-------------|
| **AHT21**  | Temperature       | °C          |
|            | Humidity          | % RH        |
| **ENS160** | eCO₂ (equivalent CO₂) | ppm      |
|            | TVOC (Total Volatile Organic Compounds) | ppb  |
| **Anemometer** | Wind Speed     | m/s (approx) |

---

## 🔗 System Architecture

- **Mega2560**: Collects data from AHT21, ENS160, and analog anemometer.
- **Serial3 Communication**: Sends sensor data to onboard ESP8266.
- **ESP8266**: Parses and uploads data to ThingSpeak via HTTP.
- **ThingSpeak**: Visualizes data on a public/private cloud dashboard.

---

## 🛠️ Setup Instructions

1. **Install Required Arduino Libraries**
   - `Adafruit AHTX0`
   - `DFRobot_ENS160`
   - `ESP8266WiFi`
   - `ESP8266HTTPClient`
  
2. **Wiring Overview**
   - AHT21 → SDA/SCL to Mega (Wire/I2C) ENS160 → SDA/SCL to Mega (Wire/I2C), address 0x53 Anemometer → Analog pin A0 ESP8266 → Connected internally to Serial3 on Mega2560
  
3. **Set DIP Switches on Board**
- To program Mega2560: `DIP 3 & 4 ON`
- To run ESP8266: `DIP 1 & 2 ON`

4. **Upload Arduino Code**
- Upload Mega2560 sketch via Arduino IDE.
- Then, upload ESP8266 sketch using the same IDE, selecting the correct port and board.

5. **Configure ThingSpeak**
- Create a channel with at least 5 fields.
- Copy the API Key into the ESP8266 sketch.

---

## 📈 ThingSpeak Dashboard

- The ESP8266 sends data every 20 seconds to ThingSpeak.
- Fields represent:
- Field 1: Temperature (°C)
- Field 2: Humidity (%)
- Field 3: eCO₂ (ppm)
- Field 4: TVOC (ppb)
- Field 5: Wind Speed (m/s)

---

## 🧑‍💻 Developers

- Developed by **Shafayat Alam Fahim**, **Promit Chowhan Polok**, **Md. Asifuzzaman**, **Abdul Shahariar Shafin**, **Pial Mondal**, **Atkia Mubassira Nafisa** of **Independent University, Bangladesh**
- Guided by **Noor-E Sadman** 

---

