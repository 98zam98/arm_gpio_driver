/******************************************************************************
 * Module: 
 * File Name: Program_arm_gpio_driver.c
 * Version: 1
 * Date: 4/1/2022
 * Description: function prototypes and variables and macro functions that can be called by user 
 * Author: Zyad Ahmed Mackawy (ZAM)
 *******************************************************************************/
#include "../../macro.h"
#include "private_arm_gpio_driver.h"
#include "interface_arm_gpio_driver.h"
#include "hardware_arm_gpio_driver.h"
#include "config_arm_gpio_driver.h"

/* Private */

//--------------------------------------

/* Interface*/

void void_init_Input_Analog_GPIO(char PORTX, char PINY)
{
    /*
    CNF1 = 0
    CNF0 = 0
    MODE1 = INPUT 0
    MODE0 = INPUT 0
    */
    //CNF1 = 0
    CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
    //CNF0 = 0
    CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
    //MODE1 = INPUT 0
    CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
    //MODE0 = INPUT 0
    CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
}

void void_init_Input_floating_GPIO(char PORTX, char PINY)
{
    /*
    CNF1 = 0
    CNF0 = 1
    MODE1 = INPUT 0
    MODE0 = INPUT 0
    */
    //CNF1 = 0
    CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
    //CNF0 = 1
    SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
    //MODE1 = INPUT 0
    CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
    //MODE0 = INPUT 0
    CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
}

void void_init_Input_pull_down_GPIO(char PORTX, char PINY)
{
    /*
    CNF1 = 1
    CNF0 = 0
    MODE1 = INPUT 0
    MODE0 = INPUT 0
    PxODR = 0
    */
    //CNF1 = 1
    SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
    //CNF0 = 0
    CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
    //MODE1 = INPUT 0
    CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
    //MODE0 = INPUT 0
    CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
    //PxODR = 0
    CLEARBIT(GPIOx_ODR_REG(PORTX), PINY);
}

void void_init_Input_pull_up_GPIO(char PORTX, char PINY)
{
    /*
    CNF1 = 1
    CNF0 = 0
    MODE1 = INPUT 0
    MODE0 = INPUT 0
    PxODR = 1
    */
    //CNF1 = 1
    SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
    //CNF0 = 0
    CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
    //MODE1 = INPUT 0
    CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
    //MODE0 = INPUT 0
    CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
    //PxODR = 1
    SETBIT(GPIOx_ODR_REG(PORTX), PINY);
}

void void_init_output_push_pull_GPIO(char PORTX, char PINY, char MODE)
{
    /*
    CNF1 = 0
    CNF0 = 0
    */
    if (MODE != INPUT_u2_value_GPIOx_PORTS)
    {
        //CNF1 = 0
        CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        //CNF0 = 0
        CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));

        //MODE1
        if (MODE & 0b0010)
        {
            SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }
        else
        {
            CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }

        //MODE0
        if (MODE & 0b0001)
        {
            SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }
        else
        {
            CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }
    }
}
 
void void_init_output_open_drain_GPIO(char PORTX, char PINY, char MODE)
{
    /*
    CNF1 = 0
    CNF0 = 1
    */
    if (MODE != INPUT_u2_value_GPIOx_PORTS)
    {
        //CNF1 = 0
        CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        //CNF0 = 1
        SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));

        //MODE1
        if (MODE & 0b0010)
        {
            SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }
        else
        {
            CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }

        //MODE0
        if (MODE & 0b0001)
        {
            SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }
        else
        {
            CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }
    }
}

void void_init_output_push_pull_AFIO(char PORTX, char PINY, char MODE)
{
    /*
    CNF1 = 1
    CNF0 = 0
    */
    if (MODE != INPUT_u2_value_GPIOx_PORTS)
    {
        //CNF1 = 1
        SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        //CNF0 = 0
        CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));

        //MODE1
        if (MODE & 0b0010)
        {
            SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }
        else
        {
            CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }

        //MODE0
        if (MODE & 0b0001)
        {
            SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }
        else
        {
            CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }
    }
}


void void_init_output_open_drain_AFIO(char PORTX, char PINY, char MODE)
{
    /*
    CNF1 = 1
    CNF0 = 1
    */
    if (MODE != INPUT_u2_value_GPIOx_PORTS)
    {
        //CNF1 = 1
        SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        //CNF0 = 1
        SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(CONFIG0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));

        //MODE1
        if (MODE & 0b0010)
        {
            SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }
        else
        {
            CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE1_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }

        //MODE0
        if (MODE & 0b0001)
        {
            SETBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }
        else
        {
            CLEARBIT(GPIOx_CRA_REG(PORTX, PINY), GPIOx_CRA_ZBIT_YPIN(MODE0_u2_value_GPIOx_CRA_BITS_Port_configuration, PINY));
        }
    }
}


//--------------------------------------
