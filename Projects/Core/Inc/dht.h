/*
 * dht.h
 *
 *  Created on: 23 Jul 2021
 *      Author: alyas
 */

#ifndef APPLICATION_CORE_DHT_H_
#define APPLICATION_CORE_DHT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

typedef struct
{
  float temperature;      /*!< in degC */
  float humidity;         /*!< in % */
} DHT11_t;

void Set_Pin_Input(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void Set_Pin_Output(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void DHT11_Start(void);
uint8_t DHT11_Check_Response(void);
uint8_t DHT11_Read (void);
DHT11_t DHT11_Process (void);

#ifdef __cplusplus
}
#endif

#endif /* APPLICATION_CORE_DHT_H_ */
