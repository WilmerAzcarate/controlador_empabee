#include <Arduino.h>

#ifndef GET_ENV_H
#define GET_ENV_H

class GetEnv
{
public:
    GetEnv(){}
    static char *getApiUrl()
    {
        const char *api_url_env = getenv("API_URL");
        char *api_url = "";
        if (api_url_env == nullptr)
        {
            Serial.println("No se obtuvo una direccion de api");
        }
        else
        {
            strcpy(api_url, api_url_env);
        }
        return api_url;
    }

    static int getSerialPort()
    {
        const char *serial_port_env = getenv("SERIAL_PORT");
        int serial_port = 0;
        if (serial_port_env == nullptr)
        {
            Serial.println("No se obtuvo un puerto serial");
        }
        else
        {
            serial_port = atoi(serial_port_env);
        }

        return serial_port;
    }

    static char *getControladorId()
    {
        const char *c_id_env = getenv("C_ID");
        char *c_id = "";
        if (c_id_env == nullptr)
        {
            Serial.println("No se obtuvo una id valida para el controlador");
        }
        else
        {
            strcpy(c_id, c_id_env);
        }
        return c_id;
    }

    static char *getSsId()
    {
        const char *ssid_env = getenv("SSID");
        char *ssid = "";
        if (ssid_env == nullptr)
        {
            Serial.println("No se obtuvo un nombre de red valido");
        }
        else
        {
            strcpy(ssid, ssid_env);
        }
        return ssid;
    }
    static char *getPassKey()
    {
        const char *pass_env = getenv("WPASS");
        char *pass = "";
        if (pass_env == nullptr)
        {
            Serial.println("No se obtuvo una clave de red valida");
        }
        else
        {
            strcpy(pass, pass_env);
        }
        return pass;
    }

    static int getServerPort()
    {
        const char *w_server_port_env = getenv("WSERVER_PORT");
        int w_server_port = 0;
        if (w_server_port_env == nullptr)
        {
            Serial.println("No se obtuvo un puerto de red valido");
        }
        else
        {
            w_server_port = atoi(w_server_port_env);
        }
        return w_server_port;
    }
};
#endif