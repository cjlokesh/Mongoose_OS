#include "mgos.h"
#include "mgos_mqtt.h"
#include "stdbool.h"

#define HIGH true // high state
#define BUTTON 0  // GPIO 0 as a Butoon (ESP32 boot/flash pin)

// Function Prototypes
void mqtt_data(int pin, void *arg);
void gpio_init();

// App Intilization
enum mgos_app_init_result mgos_app_init(void)
{

  gpio_init(); //Intilizing the led, button pin and registering the ISR
  return MGOS_APP_INIT_SUCCESS;
}

/**********************************************************************
* @fn     mqtt_data

* @brief  sends the data over the mqtt for every button press 

* @param  pin -> void

* @param   pin -> NULL

* @return  None
 **********************************************************************/

void mqtt_data(int pin, void *arg)
{
  // reading the current button state through 'mgos_gpio_read' function
  // Condition evaluates if button is pressed
  if (mgos_gpio_read(BUTTON))
  {
    // Send data over mqtt
    // MQTT data in JSON format
    //Data sent to the publisher is "key : value"
    mgos_mqtt_pubf(mgos_sys_config_get_mqtt_pub(), 0, false, "{key: value}");
    //Log to mos console
    printf("MQTT publisher is sent the data\n");
  }
  (void)pin;
}

/**********************************************************************
* @fn      gpio_init

* @brief   defines the GPIO pins and register the ISR and ISR callback function

* @param    void

* @return  None
 **********************************************************************/

void gpio_init()
{
  mgos_gpio_set_mode(BUTTON, MGOS_GPIO_MODE_INPUT); // butoon as Input
  // Triggers the interrupt on every button press and realse
  // mqtt_data is call back function
  mgos_gpio_set_button_handler(BUTTON, MGOS_GPIO_PULL_NONE, MGOS_GPIO_INT_EDGE_NEG, 50, mqtt_data, NULL);
}