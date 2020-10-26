# Line-Tracking-Robot
### This project is from the UVic 299 course ###

#### Objectives of the project: #####
* To analyze and set up the steps of building the robot. 
* Arranging all components in the proper location and  designing the schematic of the PCB 
* Shipping the PCB layout to the AP circuit, and soldering all the component on the PCB
* Writing the code for the IR sensor and the code for adjusting the movement of the robot using STM microcontroller
* Designing the Solid Work of the outer shell of the robot

# Heading 1 #

   // Enable the clock to the GPIO D-port
    //
        __HAL_RCC_GPIOE_CLK_ENABLE();

    // Configure GPIO port D

        GPIO_Init.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14; // the pin which is connected to the LED on-board
        GPIO_Init.Speed = GPIO_SPEED_MEDIUM; //IO speed
        GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP; // Push-Pull type output configuration
        GPIO_Init.Pull = GPIO_NOPULL; //No pull-up resistor is needed
        GPIO_Init.Alternate = 0; // No alternate function is being used
        HAL_GPIO_Init( GPIOE, &GPIO_Init ); //commandline to initialize the GPIO port

        __HAL_RCC_GPIOA_CLK_ENABLE();
        GPIO_Init.Pin = GPIO_PIN_0; // the pin which is connected to the LED on-board
        GPIO_Init.Speed = GPIO_SPEED_MEDIUM; //IO speed
        GPIO_Init.Mode = GPIO_MODE_INPUT; // Push-Pull type output configuration
        GPIO_Init.Pull = GPIO_PULLDOWN; //No pull-up resistor is needed
        GPIO_Init.Alternate = 0; // No alternate function is being used
                HAL_GPIO_Init( GPIOA, &GPIO_Init ); //commandline to initialize the GPIO port
 // define a variable called Counter
 
##### STM32F407 Microcontroller: #####
![alt text](https://github.com/Suchawit/Line-Tracking-Robot/blob/main/Robot_without_case.jpg)
