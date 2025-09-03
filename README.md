# ESP32 Network Eater

**ESP32 Network Eater** is a prototype system built with ESP32 that continuously generates internet traffic. The user can specify which Wi-Fi network to connect to and which website to target. The ESP32 downloads the target site in small chunks to continuously utilize the internet.  

---

## Features
- Accepts Wi-Fi SSID and password from the user.  
- Accepts target website URL from the user.  
- Downloads website content in small chunks to continuously generate network traffic.  
- Efficient use of memory (RAM-friendly).  
- Operates almost non-stop for maximum network usage.  

---

## Usage
1. Upload the code to ESP32.  
2. Open the Serial Monitor (115200 baud).  
3. Enter Wi-Fi SSID and password.  
4. Enter the target website URL.  
5. ESP32 will start downloading the site continuously, generating internet traffic.  

---

## Disclaimer
- This project is intended for **educational purposes and personal testing** only.  
- **Do not use this project to target third-party websites or networks without permission.**  
- The creator of this project **assumes no responsibility** for misuse or any consequences arising from improper use.  
- Excessive network usage may trigger rate limits or temporary blocks by service providers.  
- Ensure continuous power supply if running 24/7.
- Running the ESP32 continuously may cause it to overheat.

---

## Development Ideas
- Add a web-based interface for dynamic user input.  
- Support multiple websites in parallel for increased traffic generation.  
- Implement adjustable traffic speed and chunk size for flexible testing.  
