//----------------------------------------------------------------------------

    #include <stdio.h>
    #include <stdlib.h>
    #include "cmsis/cmsis_device.h"
    #include "stm32f4xx.h"
    #include "ctype.h"
    #include "diag/Trace.h"
    #include <sys/stat.h>

// ----------------------------------------------------------------------------
//
// Standalone STM32F4 empty sample (trace via DEBUG).
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// Define LED
    #define Led                 ( GPIO_PIN_13 )

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int
main(int argc, char* argv[])
{
    GPIO_InitTypeDef GPIO_Init;

    // Initialize HAL drivers
        HAL_Init();

    //
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

         // Turn-on the LED
int x =0;
// Infinite loop
  while (1){

//Code to toggle LED using a counting logic.
//please change the number 320,000,000 to (i) 32,000,000 (ii) 3,200,000 and (iii) 320,000.
//Please use a stop watch to measure how long it takes to toggle.
//Also, check if you can see the toggling effect
     if ((  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) && x==0 ))
        {
    	 HAL_GPIO_WritePin( GPIOE, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET );
    	      HAL_GPIO_WritePin( GPIOE, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_14 , GPIO_PIN_SET );
    	      //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
    	  x++;
    	  trace_printf(" x = %d", x);

        }
      if (( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)&& x==1 ))
              {
    	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_14, GPIO_PIN_RESET);
          	  HAL_GPIO_WritePin( GPIOE, GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_SET );

          	  //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
             x++;
             trace_printf(" x = %d", x);
              }
      if (( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)&& x==2 ))
                   {
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);
              HAL_GPIO_WritePin( GPIOE, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_SET );

              //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
                  x++;
                  trace_printf(" x = %d", x);
                   }
      if (( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)&& x==3 ))
                        {
				 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_RESET);
              HAL_GPIO_WritePin( GPIOE, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13, GPIO_PIN_SET );

              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
                       x++;
                       trace_printf(" x = %d", x);
                        }
      if (( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)&& x==4 ))
                             {
				 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13, GPIO_PIN_RESET);
              HAL_GPIO_WritePin( GPIOE, GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_SET );
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
                            x++;
                            trace_printf(" x = %d", x);
                   }
      if (( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)&& x==5 ))
                             {
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
              HAL_GPIO_WritePin( GPIOE, GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_SET );

              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
                            x++;
                            trace_printf(" x = %d", x);
                             }
      if (( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)&& x==6 ))
                             {
				 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
                HAL_GPIO_WritePin( GPIOE, GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_SET );

                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
                                  x++;
                                  trace_printf(" x = %d", x);
                                   }
      if (( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)&& x==7 ))
                             {
				HAL_GPIO_WritePin( GPIOE, GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET );
                HAL_GPIO_WritePin( GPIOE, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_SET );
                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
                                        x++;
                                        trace_printf(" x = %d", x);
                                         }
      if (( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)&& x==8 ))
                    {
			   HAL_GPIO_WritePin( GPIOE, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET );
               HAL_GPIO_WritePin( GPIOE, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_SET );

               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
                                             x++;
                                             trace_printf(" x = %d", x);
                                              }
      if (( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)&& x==9 ))
                         {
				 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET );
               HAL_GPIO_WritePin( GPIOE, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_SET );
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
               trace_printf(" x = %d", x);
                                                 x = 0;
                                                   }



    }
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
