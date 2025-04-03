NodeMCU ESP8266 webserver that will display a website

Enter your wifi credentials into
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
And it will connect to the wifi

The webserver will default post the site to port 80 at the IP the ESP8266 gets from the wifi
Libraries that are used:
ESP8266WebServer.h
ESP8266WiFi.h

Nothing else at the moment BONK!!!
