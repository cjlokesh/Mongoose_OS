# How to connect device to wifi in STA mode

## Overview

This app shows how to make your device as acess point(WIFI Ap mode).
wifi configuration is done in mos.yml file.

Note: The controller platform used for this project is ESP32, you can choose what ever the controller supported by mongoose os but mos.yml configuration remains same.

In mos.yml file the IP address for gateway will be reserved for gateway.
After flashing this code, The "ESP32_MONGOOSE_OS SSID" will be available to connect.
Connect to the "ESP32_MONGOOSE_OS SSID" and hit the IP 192.168.1.1 you will be index.html page content in the browser.

Lokesh CJ
