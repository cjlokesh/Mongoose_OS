
#include "mgos.h"
#include "stdbool.h"

#define HIGH true // high state
#define LOW false // low state
#define LED 2     // GPIO 2 as led (ESP32 on board led)
#define BUTTON 0  // GPIO 0 as a Butoon (ESP32 boot/flash pin)

// Function Prototypes
void led_control(int pin, void *arg);
void gpio_init();

// App Intilization
enum mgos_app_init_result mgos_app_init(void)
{

  gpio_init(); //Intilizing the led, button pin and registering the ISR
  return MGOS_APP_INIT_SUCCESS;
}

/**********************************************************************
@fn     led_control

@brief  turns ON/OFF the led for every button press`

@param   pin -> void

@param   pin -> NULL

@return  None
 **********************************************************************/

void led_control(int pin, void *arg)
{
  // reading the current button state through 'mgos_gpio_read' function
  // Condition evaluates if button is pressed
  if (mgos_gpio_read(BUTTON))
  {
    // turn on led
    mgos_gpio_write(LED, LOW);
    printf("LED IS ONn"); //log to mos console
  }
  else
  {
    // turn off led
    mgos_gpio_write(LED, LOW);
    printf("LED IS OFF\n"); //log to mos console
  }
  (void)pin;
}

/**********************************************************************
@fn     gpio_init

@brief   defines the GPIO pins and register the ISR and ISR callback function

@param    void

@return  None
 **********************************************************************/

void gpio_init()
{
  mgos_gpio_set_mode(LED, MGOS_GPIO_MODE_OUTPUT);   //led as output
  mgos_gpio_set_mode(BUTTON, MGOS_GPIO_MODE_INPUT); // butoon as Input
  // Triggers the interrupt on every button  press and realse
  // led_control is call back function
  mgos_gpio_set_button_handler(BUTTON, MGOS_GPIO_PULL_NONE, MGOS_GPIO_INT_EDGE_NEG, 50, led_control, NULL);
}
