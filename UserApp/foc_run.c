#include "common.h"
//#include "foc.h"
#include "svpwm_clarke_park.h"
#include "arm_math.h"
uint16_t adcvalue1[4];
FOC_t motor;
void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    static float theta;
  
    /*电流采集*/
    if(hadc->Instance == ADC1){
    adcvalue1[0] = hadc->Instance->JDR1;
    adcvalue1[1] = hadc->Instance->JDR2;
    adcvalue1[2] = hadc->Instance->JDR3;
    }
    if(hadc->Instance == ADC2){
     adcvalue1[3] = hadc->Instance->JDR1;
    }
     motor.Ud = 0;
     motor.Uq = 1;
    theta += 0.01;
    if (theta > 6.28)
    {
       // theta= 0;
    }
		//motor.theta=theta;
    motor.sin_theta = arm_sin_f32(theta);
    motor.cos_theta = arm_cos_f32(theta);
   
    R_park(&motor);
    SVPWM(&motor);
    
}