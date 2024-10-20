# Using this module

## Connecting wires to Raspberry Pi 2

| OLED Pin | Raspberry Pi 2 Pin |
|---|---|
| VCC |	3.3V |
| GND |	GND |
| DIN |	GPIO 10 (SPI MOSI) |
| CLK |	GPIO 11 (SPI SCK) |
| CS | GPIO 8 (SPI SS) |
| DC | GPIO 25 |
| RST |	GPIO 27 |

## Python installs

sudo apt-get update
sudo apt-get install python3-pip
sudo apt-get install python3-pil
sudo apt-get install python3-numpy
sudo pip3 install spidev
sudo apt-get install python3-smbus

## Demo/example code/libraries

sudo apt-get install p7zip-full
sudo wget https://files.waveshare.com/upload/2/2c/OLED_Module_Code.7z
7z x OLED_Module_Code.7z
cd OLED_Module_Code/RaspberryPi