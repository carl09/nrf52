
// #include <zephyr.h>
// #include <device.h>
// #include <devicetree.h>
// #include <drivers/gpio.h>

// #include <bluetooth/bluetooth.h>
// #include <bluetooth/hci.h>

// #include <sys/util.h>
#include <drivers/sensor.h>
#include <drivers/i2c.h>

#include "led.h"

#define BME280 DT_INST(0, bosch_bme280)
#define BME280_LABEL DT_LABEL(BME280)

struct device *dev_bme280;

void updateSensor(void)
{
    sensor_sample_fetch(dev_bme280);
}

int16_t getTemperature(void)
{
    struct sensor_value temp;
    sensor_channel_get(dev_bme280, SENSOR_CHAN_AMBIENT_TEMP, &temp);

    for (size_t i = 0; i < temp.val1; i++)
    {
        led1toggle(true);
        k_msleep(50);
        led1toggle(false);
        k_msleep(50);
    }

    return temp.val1; // (temp.val1 * 100) + (temp.val2 / 1000);
}

int getHumidity(void)
{
    struct sensor_value humidity;
    sensor_channel_get(dev_bme280, SENSOR_CHAN_HUMIDITY, &humidity);

    return humidity.val1; // (humidity.val1 * 100) + (humidity.val2 / 1000);
}

void setupBme280(void)
{
    dev_bme280 = device_get_binding(BME280_LABEL);
    if (dev_bme280 == NULL)
    {
        led1toggle(true);
    }
    else
    {
        led1toggle(false);
    }
}