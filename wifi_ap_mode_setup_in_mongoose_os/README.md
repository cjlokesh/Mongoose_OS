# How to connect device to wifi in STA mode

## Overview

<br/>This app shows how to make your device as access point(WIFI AP mode),
wifi configuration is done in mos.yml file.

<br/><br/>The controller platform used for this project is ESP32, you can choose what ever the controller supported by mongoose os but mos.yml configuration remains same.

<br/><br/>In mos.yml file the IP address for gateway will be reserved for gateway.
<br/>After flashing this code, The "ESP32_MONGOOSE_OS SSID" will be available to connect.
<br/>Connect to the "ESP32_MONGOOSE_OS SSID" and hit the IP 192.168.1.1 you will be index.html page content in the browser.

<br/><br/>Note: For more about wifi configuration API please refer respective mongoose os library sections.

<br/><br/>Regarsds
Lokesh CJ
