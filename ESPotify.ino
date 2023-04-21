// Libraries
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <SpotifyArduino.h>
#include <SpotifyArduinoCert.h>
#include <ArduinoJson.h>
#include "config.h"

// Network & Spotify Definitions

char ssid[] = WIFI_SSID;         
char password[] = WIFI_PASSWORD; 

char clientId[] = SPOTIFY_CLIENT_ID;     // My client ID for Spotify
char clientSecret[] = SPOTIFY_CLIENT_SECRET; // My client Secret for Spotify

// Country code, including this is advisable
#define SPOTIFY_MARKET "IE"

#define SPOTIFY_REFRESH_TOKEN SPOTIFY_REFRESHER_TOKEN

// Hardware Definitions
int potPin = 36;
int playButtonPin = 18;
int pauseButtonPin = 19;
int nextButtonPin = 21;
int previousButtonPin = 22;

// Debouncing
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

WiFiClientSecure client;
SpotifyArduino spotify(client, clientId, clientSecret, SPOTIFY_REFRESH_TOKEN);

void setup() {
  Serial.begin(115200);

  pinMode(playButtonPin, INPUT_PULLUP);
  pinMode(pauseButtonPin, INPUT_PULLUP);
  pinMode(nextButtonPin, INPUT_PULLUP);
  pinMode(previousButtonPin, INPUT_PULLUP);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
      delay(500);
      Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Handle HTTPS Verification
  client.setCACert(spotify_server_cert);

  Serial.println("Refreshing Access Tokens");
  if (!spotify.refreshAccessToken())
  {
      Serial.println("Failed to get access tokens");
  }
}

void setSpotifyVolumeWithPot(int potPin)
{
  // Read the potentiometer value
  int potValue = analogRead(potPin);

  // Map the potentiometer value to a volume level between 0 and 100
  int volume = map(potValue, 0, 4095, 0, 100);

  // Set the volume on the Spotify player
  if (spotify.setVolume(volume))
  {
      Serial.print("Spotify volume set to ");
      Serial.println(volume);
  }
  else
  {
      Serial.println("Failed to set Spotify volume");
  }
}

void playButtonPressed(int playButtonPin) {
  // Check if the button is pressed and debounced
  int buttonState = digitalRead(playButtonPin);
  if (buttonState == LOW && (millis() - lastDebounceTime) > debounceDelay) {
    Serial.println("Play button pressed");
    spotify.play();
    lastDebounceTime = millis();
  }
}

void pauseButtonPressed(int pauseButtonPin) {
  // Check if the button is pressed and debounced
  int buttonState = digitalRead(pauseButtonPin);
  if (buttonState == LOW && (millis() - lastDebounceTime) > debounceDelay) {
    Serial.println("Pause button pressed");
    spotify.pause();
    lastDebounceTime = millis();
  }
}

void nextButtonPressed(int nextButtonPin) {
  // Check if the button is pressed and debounced
  int buttonState = digitalRead(nextButtonPin);
  if (buttonState == LOW && (millis() - lastDebounceTime) > debounceDelay) {
    Serial.println("Next button pressed");
    spotify.nextTrack();
    lastDebounceTime = millis();
  }
}

void previousButtonPressed(int previousButtonPin) {
  // Check if the button is pressed and debounced
  int buttonState = digitalRead(previousButtonPin);
  if (buttonState == LOW && (millis() - lastDebounceTime) > debounceDelay) {
    Serial.println("Previous button pressed");
    spotify.previousTrack();
    lastDebounceTime = millis();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  setSpotifyVolumeWithPot(potPin);
  playButtonPressed(playButtonPin);
  pauseButtonPressed(pauseButtonPin);
  nextButtonPressed(nextButtonPin);
  previousButtonPressed(previousButtonPin);
}
