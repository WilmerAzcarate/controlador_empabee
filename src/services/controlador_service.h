#include <ArduinoJson.h>
#include <LinkedList.h>
#include <WiFiNINA.h>
#include <HttpClient.h>
#include <models/Controlador.h>

class ControladorService
{
private:
    String server_name;
    int port;
    String request_url;
    WiFiClient wifiClient;
    HttpClient http = HttpClient(wifiClient);

public:
    ControladorService()
    {
        this->server_name = SERVER_NAME;
        this->port = SERVER_PORT;
        this->request_url = REQUEST_URL;
        this->request_url += "/controladores";
    }

    Controlador getControlador(String uuid)
    {
        String requestUrl = this->request_url;
        requestUrl += uuid;
        int data = this->http.get(this->ñserver_name.c_str(), this->port, requestUrl.c_str());
        return Controlador::fromJson(data);
    }
};