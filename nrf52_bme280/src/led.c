
#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)

#define LED0 DT_GPIO_LABEL(LED0_NODE, gpios)
#define PIN0 DT_GPIO_PIN(LED0_NODE, gpios)

#define LED1 DT_GPIO_LABEL(LED1_NODE, gpios)
#define PIN1 DT_GPIO_PIN(LED1_NODE, gpios)

#define FLAGS0 DT_GPIO_FLAGS(LED0_NODE, gpios)
#define FLAGS1 DT_GPIO_FLAGS(LED1_NODE, gpios)

const struct device *led0;
const struct device *led1;

void setupLed(void)
{
    led0 = device_get_binding(LED0);
    gpio_pin_configure(led0, PIN0, GPIO_OUTPUT_ACTIVE | FLAGS0);

    led1 = device_get_binding(LED1);
    gpio_pin_configure(led1, PIN1, GPIO_OUTPUT_ACTIVE | FLAGS1);
}

void led0toggle(bool led_is_on)
{
    gpio_pin_set(led0, PIN0, (int)led_is_on);
}

void led1toggle(bool led_is_on)
{
    gpio_pin_set(led1, PIN1, (int)led_is_on);
}