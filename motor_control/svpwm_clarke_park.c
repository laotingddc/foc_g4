#include "svpwm_clarke_park.h"
#include "tim.h"
#include "stdio.h"
/**
 * @file foc.c
 * @brief FOC (Field-Oriented Control) 变换算法
 * @author ddc
 * @date 2025-03-25
 * @version 1.0
 */
 

 float U_alpha, U_beta,  I_alpha, I_beta;

/**
 * @brief 逆 Park 变换 (d-q → α-β)
 * @param[in,out] self 指向 FOC 结构体的指针
 */
void R_park(FOC_t *foc_)
{
    U_alpha = foc_->Ud*foc_->cos_theta - foc_->Uq*foc_->sin_theta;
    U_beta = foc_->Ud*foc_->sin_theta + foc_->Uq*foc_->cos_theta;
     
}

/**
 * @brief Clarke 变换 (α-β 变换)
 * @param[in,out] self 指向 FOC 结构体的指针
 */
void Clarke(FOC_t *foc_)
{
	I_alpha = foc_->Current.Ia;
	I_beta = (foc_->Current.Ia + 2.0f * foc_->Current.Ib) / SQRT3;
}

/**
 * @brief Park 变换 (α-β → d-q)
 * @param[in,out] self 指向 FOC 结构体的指针
 */
void park(FOC_t *foc_)
{
    foc_->I_d = I_alpha*foc_->cos_theta + I_beta*foc_->sin_theta;
    foc_->I_q = -I_alpha*foc_->sin_theta + I_beta*foc_->cos_theta;
}

void SVPWM(FOC_t *foc_)
{
	static uint8_t sector = 0;
	static float v1, v2, v3, X, Y, Z, T1, T2, Tcmp1, Tcmp2, Tcmp3, ta, tb, tc;
	Tcmp1 = 0;
	Tcmp2 = 0;
	Tcmp3 = 0;
	sector = 0;
	//========Parameters statement================

	v1 = U_beta;
	v2 = (SQRT3 * U_alpha - U_beta) / 2.0f;
	v3 = (-SQRT3 * U_alpha - U_beta) / 2.0f;
	//========Sector calculation=================

	if (v1 > 0)
		sector = 1;

	if (v2 > 0)
		sector = sector + 2;

	if (v3 > 0)
		sector = sector + 4;
	//======== X Y Z calculation===================
	X = SQRT3 * U_beta * PWM_FRQ / UDC;
	Y = PWM_FRQ / UDC * (3 / 2.0f * U_alpha + SQRT3 / 2.0f * U_beta);
	Z = PWM_FRQ / UDC * (-3 / 2.0f * U_alpha + SQRT3 / 2.0f * U_beta);

	//=========Duty ratio calculation================
	switch (sector)
	{
	case 1:
		T1 = Z;
		T2 = Y;
		break;
	case 2:
		T1 = Y;
		T2 = -X;
		break;
	case 3:
		T1 = -Z;
		T2 = X;
		break;
	case 4:
		T1 = -X;
		T2 = Z;
		break;
	case 5:
		T1 = X;
		T2 = -Y;
		break;
	default:
		T1 = -Y;
		T2 = -Z;
		break;
	}
	if (T1 + T2 > PWM_FRQ)
	{
		T1 = T1 / (T1 + T2);
		T2 = T2 / (T1 + T2);
	}
	else
	{
		T1 = T1;
		T2 = T2;
	}

	ta = (PWM_FRQ - (T1 + T2)) / 4.0f;
	tb = ta + T1 / 2;
	tc = tb + T2 / 2;

	//==========Duty ratio calculation================
	switch (sector)
	{
	case 1:
		Tcmp1 = tb;
		Tcmp2 = ta;
		Tcmp3 = tc;
		break;
	case 2:
		Tcmp1 = ta;
		Tcmp2 = tc;
		Tcmp3 = tb;
		break;
	case 3:
		Tcmp1 = ta;
		Tcmp2 = tb;
		Tcmp3 = tc;
		break;
	case 4:
		Tcmp1 = tc;
		Tcmp2 = tb;
		Tcmp3 = ta;
		break;
	case 5:
		Tcmp1 = tc;
		Tcmp2 = ta;
		Tcmp3 = tb;
		break;
	case 6:
		Tcmp1 = tb;
		Tcmp2 = tc;
		Tcmp3 = ta;
		break;
	}                                                                                     

    TIM1->CCR1 = Tcmp1;
    TIM1->CCR2 = Tcmp2;
    TIM1->CCR3 = Tcmp3;
     printf("%f,%f,%f\n",Tcmp1,Tcmp2,Tcmp3);
}