/******************************************************************************
 * Module: 
 * File Name: Hardware_arm_gpio_driver.h
 * Version: 1
 * Date: 4/1/2022
 * Description: registers or connection with their macros and data types
 * Author: Zyad Ahmed Mackawy (ZAM)
 *******************************************************************************/
#ifndef __HARDWARE_ARM_GPIO_DRIVER_H__
#define __HARDWARE_ARM_GPIO_DRIVER_H__

/* AFIO */

#define AFIO_BASE 0x40010000

/* GPIO */

#define GPIO_BASE 0x40010800



/* GPIOx_CRA start */
// Port configuration register ALL
#define GPIOx_CRA_OFFSET                    0x00
#define GPIOx_CRA_DIFF_OFFSET               0x04
#define GPIOx_CRA_ACTUAL_OFFSET(PINY)       ((((PINY)/8)*GPIOx_CRA_DIFF_OFFSET)+GPIOx_CRA_OFFSET)
#define GPIOx_CRA_BASE(X,PINY)              ((GPIO_BASE+((X)*GPIO_PORT_STEP))+GPIOx_CRA_ACTUAL_OFFSET(PINY))
#define GPIOx_CRA_REG(X,PINY)               (*(volatile u32 *)GPIOx_CRA_BASE(X,PINY))

/*
#define GPIOx_CRA_MODEY0(PINY)              0+(PIN_POS(X))
#define GPIOx_CRA_MODEY1(PINY)              1+(PIN_POS(X))
#define GPIOx_CRA_CONFIGY0(PINY)            2+(PIN_POS(X))
#define GPIOx_CRA_CONFIGY1(PINY)            3+(PIN_POS(X))
*/
/* GPIOx_CRA end */
//--------------------------------------


/* GPIOx_CRL start */
// Port configuration register low
#define GPIOx_CRL_OFFSET 0x00
#define GPIOx_CRL_BASE(X) ((GPIO_BASE+((X)*GPIO_PORT_STEP))+GPIOx_CRL_OFFSET)
#define GPIOx_CRL_REG(X) (*(volatile u32 *)GPIOx_CRL_BASE(X))
/* GPIOx_CRL end */
//--------------------------------------


/* GPIOx_CRH start */
// Port configuration register high 
#define GPIOx_CRH_OFFSET 0x04
#define GPIOx_CRH_BASE(X) ((GPIO_BASE+((X)*GPIO_PORT_STEP))+GPIOx_CRH_OFFSET)
#define GPIOx_CRH_REG(X) (*(volatile u32 *)GPIOx_CRH_BASE(X))
/* GPIOx_CRH end */
//--------------------------------------


/* GPIOx_IDR start */
// Port input data register 
#define GPIOx_IDR_OFFSET 0x08h
#define GPIOx_IDR_BASE(X) ((GPIO_BASE+((X)*GPIO_PORT_STEP))+GPIOx_IDR_OFFSET)
#define GPIOx_IDR_REG(X) (*(volatile u32 *)GPIOx_IDR_BASE(X))
/* GPIOx_IDR end */
//--------------------------------------


/* GPIOx_ODR start */
// Port output data register 
#define GPIOx_ODR_OFFSET 0x0C
#define GPIOx_ODR_BASE(X) ((GPIO_BASE+((X)*GPIO_PORT_STEP))+GPIOx_ODR_OFFSET)
#define GPIOx_ODR_REG(X) (*(volatile u32 *)GPIOx_ODR_BASE(X))
/* GPIOx_ODR end */
//--------------------------------------






/* GPIOx_BSRR start */
// Port bit set/reset register
#define GPIOx_BSRR_OFFSET 0x10
#define GPIOx_BSRR_BASE(X) ((GPIO_BASE+((X)*GPIO_PORT_STEP))+GPIOx_BSRR_OFFSET)
#define GPIOx_BSRR_REG(X) (*(volatile u32 *)GPIOx_BSRR_BASE(X))
/* GPIOx_BSRR end */
//--------------------------------------







/* GPIOx_BRR start */
// Port bit reset register 
#define GPIOx_BRR_OFFSET 0x14
#define GPIOx_BRR_BASE(X) ((GPIO_BASE+((X)*GPIO_PORT_STEP))+GPIOx_BRR_OFFSET)
#define GPIOx_BRR_REG(X) (*(volatile u32 *)GPIOx_BRR_BASE(X))
/* GPIOx_BRR end */
//--------------------------------------







/* GPIOx_LCKR start */
// Port configuration lock register 
#define GPIOx_LCKR_OFFSET 0x18
#define GPIOx_LCKR_BASE(X) ((GPIO_BASE+((X)*GPIO_PORT_STEP))+GPIOx_LCKR_OFFSET)
#define GPIOx_LCKR_REG(X) (*(volatile u32 *)GPIOx_LCKR_BASE(X))
/* GPIOx_LCKR end */
//--------------------------------------





//--------------------------------------	


#endif /* __HARDWARE_ARM_GPIO_DRIVER_H__ */