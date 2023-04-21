# Spotify Arduino Controller

This is a work-in-progress project for controlling Spotify playback using an Arduino and physical buttons. 

## Requirements

- ESP32
- Spotify Premium account
- Spotify Client ID and Client Secret
- ArduinoJson library
- SpotifyArduino library

## Installation

1. Install the necessary libraries:

   - `WiFi.h`
   - `WiFiClientSecure.h`
   - `SpotifyArduino.h`
   - `SpotifyArduinoCert.h`
   - `ArduinoJson.h`

2. Connect the physical buttons and potentiometer to the Arduino board:

   - `playButtonPin`
   - `pauseButtonPin`
   - `nextButtonPin`
   - `previousButtonPin`
   - `potPin`

3. Update `config.h` with your network and Spotify credentials:

   - `WIFI_SSID`
   - `WIFI_PASSWORD`
   - `SPOTIFY_CLIENT_ID`
   - `SPOTIFY_CLIENT_SECRET`
   - `SPOTIFY_REFRESH_TOKEN`

4. Upload the sketch to your Arduino board and open the Serial Monitor.

5. Verify that you are connected to the WiFi network and that the Access Tokens have been refreshed.

6. Control your Spotify playback with the physical buttons and potentiometer.

## Usage

The physical buttons and potentiometer control the following Spotify actions:

- `play()`: Play the current track
- `pause()`: Pause the current track
- `nextTrack()`: Skip to the next track
- `previousTrack()`: Skip to the previous track
- `setVolume()`: Set the volume level of the Spotify player using the potentiometer

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE.md) file for details.
