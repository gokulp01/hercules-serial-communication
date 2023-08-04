/** @file HL_sys_main.c 
*   @brief Application main file
*   @date 11-Dec-2018
*   @version 04.07.01
*
*   This file contains an empty main function,
*   which can be used for the application.
*/
​
/* 
* Copyright (C) 2009-2018 Texas Instruments Incorporated - www.ti.com  
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/
​
​
/* USER CODE BEGIN (0) */
#include "HL_sci.h"
#include "HL_adc.h"
#include "stdlib.h"
unsigned char command[8];
/* USER CODE END */
​
/* Include Files */
​
#include "HL_sys_common.h"
​
/* USER CODE BEGIN (1) */
/* USER CODE END */
​
/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/
​
/* USER CODE BEGIN (2) */
/* USER CODE END */
​
int main(void)
{
/* USER CODE BEGIN (3) */
    adcData_t adc_data; //ADC Data Structure
        adcData_t *adc_data_ptr = &adc_data; //ADC Data Pointer
        unsigned int NumberOfChars, value; //Declare variables
        sciInit(); //Initializes the SCI (UART) module
        adcInit(); //Initializes the ADC module
        while(1) // Loop to acquire and send ADC sample data via the SCI (UART)
        {
        adcStartConversion(adcREG1, 1U); //Start ADC conversion
        while(!adcIsConversionComplete(adcREG1, 1U)); //Wait for ADC conversion
        adcGetData(adcREG1, 1U, adc_data_ptr); //Store conversion into ADC pointer
        value = (unsigned int)adc_data_ptr->value;
        NumberOfChars = ltoa(value,(char *)command);
        sciSend(sciREG1, 2, (unsigned char *)"0x"); //Sends '0x' hex designation chars
        sciSend(sciREG1, NumberOfChars, command); //Sends the ambient light sensor data
        sciSend(sciREG1, 2, (unsigned char *)"\r\n"); //Sends new line character
        }
/* USER CODE END */
​
    return 0;
}
​
​
/* USER CODE BEGIN (4) */
/* USER CODE END */
Collapse




