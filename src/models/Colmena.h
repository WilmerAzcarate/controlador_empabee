#include <ArduinoJson.h>

class Colmena
{
private:
    String nombre;
    float *temperatura_minima;
    float *temperatura_maxima;
    float *peso_minimo;
    float *peso_maximo;
    float *humedad_minima;
    float *humedad_maxima;

public:
    Colmena()
    {
        this->nombre = "";
        this->temperatura_minima = nullptr;
        this->temperatura_maxima = nullptr;
        this->peso_minimo = nullptr;
        this->peso_minimo = nullptr;
        this->humedad_minima = nullptr;
        this->humedad_maxima = nullptr;
    }

    Colmena(
        String nombre,
        float *temperatura_minima,
        float *temperatura_maxima,
        float *peso_minimo,
        float *peso_maximo,
        float *humedad_minima,
        float *humedad_maxima) : temperatura_minima(temperatura_minima),
                                 temperatura_maxima(temperatura_maxima),
                                 peso_minimo(peso_minimo),
                                 peso_maximo(peso_maximo),
                                 humedad_minima(humedad_minima),
                                 humedad_maxima(humedad_maxima)
    {
        this->nombre = nombre;
    }

    ~Colmena()
    {
        delete this->temperatura_minima;
        delete this->temperatura_maxima;
        delete this->peso_minimo;
        delete this->peso_maximo;
        delete this->humedad_minima;
        delete this->humedad_maxima;
    }

    String getNombre() const
    {
        return this->nombre;
    }

    float *getTemperaturaMinima() const
    {
        return this->temperatura_minima;
    }

    float *getTemperaturaMaxima() const
    {
        return this->temperatura_maxima;
    }

    float *getPesoMinimo() const
    {
        return this->peso_minimo;
    }

    float *getPesoMaximo() const
    {
        return this->peso_maximo;
    }

    float *getHumedadMinima() const
    {
        return this->humedad_minima;
    }

    float *getHumedadMaxima() const
    {
        return this->humedad_maxima;
    }

    static Colmena fromJson(JsonObject colmenaJson)
    {
        String nombre;
        float *temperatura_minima = nullptr;
        float *temperatura_maxima = nullptr;
        float *peso_minimo = nullptr;
        float *peso_maximo = nullptr;
        float *humedad_minima = nullptr;
        float *humedad_maxima = nullptr;

        nombre = colmenaJson["nombre"].as<String>();
        if (!colmenaJson["temperatura_minima"].isNull())
            temperatura_minima = new float(colmenaJson["temperatura_minima"].as<float>());
        if (!colmenaJson["temperatura_maxima"].isNull())
            temperatura_maxima = new float(colmenaJson["temperatura_maxima"].as<float>());
        if (!colmenaJson["peso_minimo"].isNull())
            peso_minimo = new float(colmenaJson["peso_minimo"].as<float>());
        if (!colmenaJson["peso_maximo"].isNull())
            peso_maximo = new float(colmenaJson["peso_maximo"].as<float>());
        if (!colmenaJson["humedad_minima"].isNull())
            humedad_minima = new float(colmenaJson["humedad_minima"].as<float>());
        if (!colmenaJson["humedad_maxima"].isNull())
            humedad_maxima = new float(colmenaJson["humedad_maxima"].as<float>());

        // Crear y devolver el objeto Colmena
        return Colmena(nombre, temperatura_minima, temperatura_maxima, peso_minimo, peso_maximo, humedad_minima, humedad_maxima);
    }
};