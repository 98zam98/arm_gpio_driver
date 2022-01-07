/******************************************************************************
 * Module: 
 * File Name: Private_arm_gpio_driver.h
 * Version: 1
 * Date: 4/1/2022
 * Description: function prototypes and variables and macro functions that should not get called by user 
 * Author: Zyad Ahmed Mackawy (ZAM)
 *******************************************************************************/

#ifndef __PRIVATE_ARM_GPIO_DRIVER_H__
#define __PRIVATE_ARM_GPIO_DRIVER_H__

/* function prototypes*/

//--------------------------------------	


/* variables */
#define GPIO_PORT_STEP      0X400

enum u2_value_GPIOx_CRA_BITS_Port_configuration
{
    MODE0_u2_value_GPIOx_CRA_BITS_Port_configuration,
    MODE1_u2_value_GPIOx_CRA_BITS_Port_configuration,
    CONFIG0_u2_value_GPIOx_CRA_BITS_Port_configuration,
    CONFIG1_u2_value_GPIOx_CRA_BITS_Port_configuration,
};

//--------------------------------------	


/* macro function*/

#define GPIOx_CRA_PIN_POS(PINY)             ((PINY)%8)*4
#define GPIOx_CRA_ZBIT_YPIN(BITZ,PINY)      (BITZ+(GPIOx_CRA_PIN_POS(PINY)))

//--------------------------------------	


#endif /* __PRIVATE_ARM_GPIO_DRIVER_H__ */