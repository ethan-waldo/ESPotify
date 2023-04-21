# ESPotify

## Description

ESPotify is a project for the intro to microcontrollers class that enables the user to control their Spotify playback and volume using physical buttons and a potentiometer. The system uses an ESP32 microcontroller and connects to the Spotify Web API.

### Task(s) the system is designed to perform

- Play and pause music
- Skip to the next or previous track
- Adjust volume using a potentiometer

### Hardware

The following hardware was used in the project:

- ESP32 microcontroller
- Potentiometer
- Push buttons (play, pause, next, previous)
- Breadboard
- Jumper Wires

| Component  | GPIO Pin |
| ------------- | ------------- |
| Potentiometer  | '36' |
| Play Button | '18'  |
| Pause Button | '19'  |
| Next Button | '21'  |
| Previous Button | '22'  |
## Installation

1. Clone the repository to your local machine.
2. Open the ESPotify.ino file in the Arduino IDE.
3. Install the following libraries:
    - WiFi
    - WiFiClientSecure
    - SpotifyArduino
    - ArduinoJson
4. Modify the following lines in the config.h file to match your Spotify credentials and WiFi network:
    ```
    #define WIFI_SSID "Your WiFi SSID"
    #define WIFI_PASSWORD "Your WiFi password"
    #define SPOTIFY_CLIENT_ID "Your Spotify client ID"
    #define SPOTIFY_CLIENT_SECRET "Your Spotify client secret"
    #define SPOTIFY_REFRESHER_TOKEN "Your Spotify refresh token"
    ```
5. Upload the code to your ESP32 microcontroller.

## Usage

1. Connect your ESP32 to power and wait for it to connect to your WiFi network.
2. Use the physical buttons to control your Spotify playback and the potentiometer to adjust the volume.

## Credits

- [SpotifyArduino library](https://github.com/witnessmenow/spotify-api-arduino)
- [ArduinoJson library](https://github.com/bblanchon/ArduinoJson)
- [WiFi library](https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/src/WiFi.h)
- [WiFi Client Secure library](https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFiClientSecure)