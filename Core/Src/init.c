#include "common.h"

/**
 * @brief  初始化硬件设备
 * @param  None
 * @retval None
 * @note   此函数需在cubemx外设初始化完成后调用
 * @warning 重复调用可能导致硬件状态异常
 */
void Hardware_Init(void)
{
    /*初始化三相互补pwm */
    HAL_TIM_Base_Start_IT(&htim1);

    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);

    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);
	
	    /*adc校准 */
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
    HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
    /*使能注入通道*/
    HAL_ADCEx_InjectedStart(&hadc1);
    HAL_ADCEx_InjectedStart(&hadc2);
    /*使能注入通道中断*/
    __HAL_ADC_ENABLE_IT(&hadc1, ADC_IT_JEOC);
    __HAL_ADC_ENABLE_IT(&hadc2, ADC_IT_JEOC);
}
