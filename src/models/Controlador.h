#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <ArduinoJson.h>
#include <LinkedList.h>
#include <models/Sensor.h>
#include <models/Colmena.h>

class Controlador
{
private:
    String uuid;
    LinkedList<Sensor> sensores;
    Colmena colmena;

public:
    Controlador()
    {
        LinkedList<Sensor> sensores;
        this->uuid = "";
        this->sensores = sensores;
    }

    Controlador(String uuid, LinkedList<Sensor> sensores, Colmena colmena)
    {
        this->uuid = uuid;
        this->sensores = sensores;
        this->colmena = colmena;
    }

    String getUuid()
    {
        return this->uuid;
    }

    LinkedList<Sensor> getSensores()
    {
        return this->sensores;
    }

    static Controlador fromJson(JsonObject jsonStr)
    {
        String uuid = jsonStr["uuid"].as<String>();

        JsonObject colmenaJson = jsonStr["colmena"];
        Colmena colmena = Colmena::fromJson(colmenaJson);

        LinkedList<Sensor> sensores;
        JsonArray sensoresArray = jsonStr["sensores"].as<JsonArray>();
        for (JsonVariant sensorVariant : sensoresArray)
        {
            JsonObject sensorJson = sensorVariant.as<JsonObject>();
            Sensor sensor = Sensor::fromJson(sensorJson);
            sensores.add(sensor);
        }

        return Controlador(uuid, sensores, colmena);
    }
};

#endif