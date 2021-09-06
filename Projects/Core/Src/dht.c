/*
 * dht.c
 *
 *  Created on: 23 Jul 2021
 *      Author: alyas
 */


/* Includes ------------------------------------------------------------------*/
#include "dht.h"
#include "main.h"

/* USER CODE BEGIN 0 */
extern UART_HandleTypeDef huart2;
char DHT11_Data[14] = {'\0'};
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure DMA                                                              */
/*----------------------------------------------------------------------------*/

/* USER CODE BEGIN 1 */

/**
  * @brief Function to change pin into input
  * @param GPIO type, GPIO pin
  * @retval None
  */
void SetPin_Input(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

/**
  * @brief Function to change pin into output
  * @param GPIO type, GPIO pin
  * @retval None
  */
void SetPin_Output(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

/**
  * @brief Function to start communication with DHT11 sensor
  * @param None
  * @retval None
  */
void DHT11_Start(void)
{
	SetPin_Output(DHT11_PORT, DHT11_PIN); // Set pin as output
	HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, 1);
	delay_us(1000);
	HAL_GPIO_WritePin (DHT11_PORT, DHT11_PIN, 0); // pull down pin to low
	delay_us(18000);   // wait 18ms for DHT11 to detect signal
	HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, 1); //pull up pin to high
	delay_us(20); //wait 20us for DHT11 response
	SetPin_Input(DHT11_PORT, DHT11_PIN);  // Set pin back as input
}

/**
  * @brief Function to check DHT11 availability (respond from the sensor)
  * @param None
  * @retval None
  */
uint8_t DHT11_Check_Response(void)
{
	uint8_t Response = 0;
	delay_us(40);
	if (!(HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN))) // if DHT11 sends response
	{
		delay_us(80); // wait for 80 us for DHT11 to start data transmission
		if ((HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN))) Response = 1; //if data
		else Response = -1;
	}
	while ((HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN))); // wait for the pin to go low
	return Response;
}

/**
  * @brief Function to read sensor DHT11's data
  * @param None
  * @retval None
  */
uint8_t DHT11_Read (void)
{
	uint8_t i, j;
	for (j = 0; j < 8; j++)
	{
		while (!(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)));   // wait for the pin to go high
		delay_us(40);   // wait for 40 us
		if (!(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))) 
		{
			i &= ~(1<<(7-j));   // write bit 0 if the pin is low
		}
		else i |= (1<<(7-j));  // write bit 1 if the pin is high
		while ((HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)));  // wait for the pin to go low
	}
	return i;
}

void DHT11_Process (void){
	//Initialization
	uint8_t Available = {0};
	uint8_t RH_byte1 = {0};
	uint8_t RH_byte2 = {0};
	uint8_t Temp_byte1 = {0};
	uint8_t Temp_byte2 = 0;
	uint8_t Sum = {0};
	float Temp_f = {0};
	float RH_f = {0};
	char str[30] = {'\0'};


	//DHT 11 Process
	DHT11_Start();
	Available   = DHT11_Check_Response();
	RH_byte1    = DHT11_Read();
	RH_byte2    = DHT11_Read();
	Temp_byte1  = DHT11_Read();
	Temp_byte2  = DHT11_Read();
	Sum     	= DHT11_Read();

	Temp_f = (float) (Temp_byte1);
	RH_f	 = (float) (RH_byte1);

	sprintf(DHT11_Data,"T%02d.%02d;H%02d.%02dF\r\n",(int)(Temp_f),(int)(Temp_f*100)%100,(int)(RH_f),(int)(RH_f*100)%100);
	//sprintf(str,"T%d;H%d\r\n",(int)(Temp_f),(int)(RH_f));
	//HAL_UART_Transmit(&huart2, str, sizeof(str), 100);

	HAL_Delay(1200);

}
/* USER CODE END 1 */

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
