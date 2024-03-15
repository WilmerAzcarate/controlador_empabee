#include <Arduino.h>
#include <WiFi.h>
#include <services/controlador_service.h>
#include <env/get_env.h>

const char *api_url = GetEnv::getApiUrl();
int serial_port = GetEnv::getSerialPort();
const char *ssid = GetEnv::getSsId();
const char *pass = GetEnv::getPassKey();
int w_server_port = GetEnv::getServerPort();

WiFiClient client;
ControladorService controlador_service = ControladorService(api_url);

void setup()
{
    WiFi.mode(WIFI_STA);

    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        while (WiFi.status() != WL_CONNECTED)
        {
            WiFi.begin(ssid, pass);
            Serial.print(".");
            delay(5000);
        }
        Serial.println("\nConnected.");

        controlador_service.getControlador("/controladores");
    }
}

void loop()
{
    
}
