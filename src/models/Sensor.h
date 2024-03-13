#include <ArduinoJson.h>
#include <LinkedList.h>

class Sensor
{
private:
    int id;
    LinkedList<float> medidas;

public:
    Sensor()
    {
        LinkedList<float> medidas;
        this->id = 0;
        this->medidas = medidas;
    }

    Sensor(int id, LinkedList<float> medidas)
    {
        this->id = id;
        this->medidas = medidas;
    }

    int getId()
    {
        return this->id;
    }

    void addMedida(float medida)
    {
        this->medidas.add(medida);
    }

    void clearMedidas()
    {
        this->medidas.clear();
    }

    LinkedList<float> getMedidas()
    {
        return this->medidas;
    }

    float getPromedio()
    {
        float addition = 0;
        int number_of_elements = this->medidas.size();
        float average = 0;

        if (!number_of_elements)
        {
            return average;
        }

        for (int i = 0; i < number_of_elements; i++)
        {
            addition += this->medidas.get(i);
        }

        average = addition / number_of_elements;

        return average;
    }

    static Sensor fromJson(JsonObject sensorJson)
    {
        Sensor sensor;

        sensor.id = sensorJson["id"];

        return sensor;
    }

    String toJson()
    {
        String jsonStr = "{\"sensor\":" + String(id) + ",\"medidas\":[";

        for (int i = 0; i < medidas.size(); i++)
        {
            jsonStr += String(medidas.get(i));
            if (i < medidas.size() - 1)
            {
                jsonStr += ",";
            }
        }

        jsonStr += "]}";
        return jsonStr;
    }
};