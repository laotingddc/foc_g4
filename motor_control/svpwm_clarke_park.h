#ifndef _SVPWM_CLARKE_PARK_H_
#define _SVPWM_CLARKE_PARK_H_

#include "stdint.h"

#define SQRT3 1.732050807568877f // sqrt(3)
#define PWM_FRQ 8500.0f
#define UDC 20.0f

//电流结构体
typedef struct 
{
    float Ia;          		/* A 相电流*/
    float Ib; 					  /* B 相电流*/
    float Ic;  						/* C 相电流*/
}Current_t;
// FOC 结构体
typedef struct
{
    float Udc;    				/* 母线电压*/
    float Ud;     				/* 直轴电压*/
    float Uq;     				/* 交轴电压*/
    float I_d;   					/* 直轴电流*/
    float I_q;   					/* 交轴电流*/
    //float theta;  			/* 角度（单位：°）*/
    float sin_theta;      /* 正弦角度*/
    float cos_theta;      /* 余弦角度*/
    Current_t Current;    /* 电流*/
    // 变换函数指针0

}FOC_t;
void SVPWM(FOC_t *foc_);
void park(FOC_t *foc_);
void Clarke(FOC_t *foc_);
void R_park(FOC_t *foc_);

#endif