/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define R0_Pin GPIO_PIN_0
#define R0_GPIO_Port GPIOC
#define R2_Pin GPIO_PIN_2
#define R2_GPIO_Port GPIOC
#define R3_Pin GPIO_PIN_3
#define R3_GPIO_Port GPIOC
#define D4_Pin GPIO_PIN_1
#define D4_GPIO_Port GPIOB
#define D7_Pin GPIO_PIN_10
#define D7_GPIO_Port GPIOB
#define C2_Pin GPIO_PIN_6
#define C2_GPIO_Port GPIOC
#define C3_Pin GPIO_PIN_7
#define C3_GPIO_Port GPIOC
#define D5_Pin GPIO_PIN_8
#define D5_GPIO_Port GPIOC
#define D6_Pin GPIO_PIN_9
#define D6_GPIO_Port GPIOC
#define C1_Pin GPIO_PIN_10
#define C1_GPIO_Port GPIOC
#define R1_Pin GPIO_PIN_11
#define R1_GPIO_Port GPIOC
#define C0_Pin GPIO_PIN_12
#define C0_GPIO_Port GPIOC
#define en_Pin GPIO_PIN_3
#define en_GPIO_Port GPIOB
#define rs_Pin GPIO_PIN_4
#define rs_GPIO_Port GPIOB
#define ext_1_Pin GPIO_PIN_5
#define ext_1_GPIO_Port GPIOB
#define ext_2_Pin GPIO_PIN_6
#define ext_2_GPIO_Port GPIOB
#define int_led_1_Pin GPIO_PIN_7
#define int_led_1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
