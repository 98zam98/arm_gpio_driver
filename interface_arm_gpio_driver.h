/******************************************************************************
 * Module: 
 * File Name: Interface_arm_gpio_driver.h
 * Version: 1
 * Date: 4/1/2022
 * Description: function prototypes and variables and macro functions that can be called by user 
 * Author: Zyad Ahmed Mackawy (ZAM)
 *******************************************************************************/

#ifndef __INTERFACE_ARM_GPIO_DRIVER_H__
#define __INTERFACE_ARM_GPIO_DRIVER_H__

/* function prototypes*/
void void_init_Input_Analog_GPIO(char PORTX,char PINY);
void void_init_Input_floating_GPIO(char PORTX,char PINY);
void void_init_Input_pull_down_GPIO(char PORTX,char PINY);
void void_init_Input_pull_up_GPIO(char PORTX,char PINY);

void void_init_output_push_pull_GPIO(char PORTX,char PINY,char MODE);
void void_init_output_open_drain_GPIO(char PORTX,char PINY,char MODE);

void void_init_output_push_pull_AFIO(char PORTX,char PINY,char MODE);
void void_init_output_open_drain_AFIO(char PORTX,char PINY,char MODE);


//--------------------------------------	


/* variables */


enum u2_value_GPIOx_PORTS
{
    A_u2_value_GPIOx_PORTS,
    B_u2_value_GPIOx_PORTS,
    C_u2_value_GPIOx_PORTS,
};

enum u2_value_GPIOx_MODES
{
    INPUT_u2_value_GPIOx_PORTS,
    OUTPUT_10_MHz_u2_value_GPIOx_PORTS,
    OUTPUT_2_MHz_u2_value_GPIOx_PORTS,
    OUTPUT_50_MHz_u2_value_GPIOx_PORTS,
};

//--------------------------------------	


/* macro function*/


#define MACRO_CONFIG_high_output_GPIO( PORTX, PINY)            SETBIT(GPIOx_ODR_REG(PORTX),PINY)
#define MACRO_CONFIG_low_output_GPIO( PORTX, PINY)             CLEARBIT(GPIOx_ODR_REG(PORTX),PINY)

#define MACRO_READ_input_GPIO( PORTX, PINY)                    GETBIT(GPIOx_IDR_REG(PORTX),PINY)
//--------------------------------------	


#endif /* __INTERFACE_ARM_GPIO_DRIVER_H__ */