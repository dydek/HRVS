#ifndef __SENSORS_H_
#define __SENSORS_H_

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <dht_nonblocking.h>
#include <State.h>
#include "Config.h"

#define DHT_READING_DELTA 1000

DHT_nonblocking dht_in_1(DHTPIN_1, DHT_TYPE_22);
DHT_nonblocking dht_in_2(DHTPIN_2, DHT_TYPE_22);

OneWire oneWire(A2);
DallasTemperature sensors(&oneWire);
static float dallas_last_reading = 0;
static float dht1_last_reading = 0;
static float dht2_last_reading = 0;

// static int should_read_id = 1;

void configureSensors()
{
    sensors.begin();
    sensors.setResolution(12);
    sensors.setWaitForConversion(false);
}

void DHT1SensorUpdate()
{
    if (millis() - dht1_last_reading > DHT_READING_DELTA)
    {
        float temperature;
        float humidity;
        if (dht_in_1.measure(&temperature, &humidity) == true)
        {
            current_values.in_temp_post = temperature;
            current_values.in_humidity = humidity;
            dht1_last_reading = millis();
        }
    }
}

void DHT2SensorUpdate()
{
    if (millis() - dht2_last_reading > DHT_READING_DELTA)
    {
        float temperature;
        float humidity;
        if (dht_in_2.measure(&temperature, &humidity) == true)
        {
            current_values.out_temp_pre = temperature;
            current_values.out_humidity = humidity;
            dht2_last_reading = millis();
        }
    }
}

void D18B20SensorsUpdate()
{
    if (dallas_last_reading == 0)
    {
        sensors.requestTemperatures();
        dallas_last_reading = millis();
    }

    if (millis() - dallas_last_reading > 800)
    {
        current_values.in_temp_pre = sensors.getTempCByIndex(0);
        current_values.out_temp_post = sensors.getTempCByIndex(1);
        dallas_last_reading = 0;
    }
}
#endif