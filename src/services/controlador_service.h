#ifndef CONTROLADOR_SERVICE_H
#define CONTROLADOR_SERVICE_H

#include <HTTPClient.h>
#include <models/Controlador.h>
#include <env/get_env.h>

class ControladorService
{
private:
    const char *m_baseURL;

public:
    ControladorService(const char *baseURL) : m_baseURL(baseURL) {}

    void getControlador(char *path)
    {
        HTTPClient http;
        const char *authorizationToken = GetEnv::getControladorId();
        http.begin(this->m_baseURL + String(path)+"/"+authorizationToken);
        http.addHeader("X-Sensor-UUID", authorizationToken);

        int httpCode = http.GET();
        String response = "";

        if (httpCode > 0)
        {
            response = http.getString();
        }
        else
        {
            Serial.printf("[HTTP] GET failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
        Serial.println(response);
    }
};

#endif