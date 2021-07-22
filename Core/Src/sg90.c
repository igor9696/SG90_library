/*
 * sg90.c
 *
 *  Created on: Jul 21, 2021
 *      Author: Igor_S
 */

#include "main.h"
#include "sg90.h"

void sg90_init(servo_motor *motor, TIM_HandleTypeDef *htim, uint32_t channel)
{
	motor->timer = htim;
	motor->channel = channel;

}


double angle_to_pulsewidth(double angle, double angle_min, double angle_max,
		double pulse_min, double pulse_max)
{
	double pulse_width;
	pulse_width = (angle - angle_min) * (pulse_max - pulse_min) / (angle_max - angle_min) + pulse_min;


	return pulse_width;
}


//void sg90_test(servo_motor *motor)
//{
//	// set angle 0, 90, 180
//	HAL_TIM_PWM_Start(motor->timer, motor->channel);
//	__HAL_TIM_SET_COUNTER(motor->timer, 0);
//
//	motor->timer->Instance->CCR1 = 12; // 90*
//
//	HAL_Delay(1000);
//
//
//	motor->timer->Instance->CCR1 = 7; // 0*
//
//	HAL_Delay(1000);
//
//	motor->timer->Instance->CCR1 = 2; // -90*
//
//	HAL_Delay(1000);
//
//
//}

void sg90_set_angle(servo_motor *motor, uint8_t angle)
{
	// 1.5ms - position '0'
	// 1ms - position '-90'
	// 2ms - position '+90'
	double pulse_width;
	pulse_width = angle_to_pulsewidth(angle, 0, 180, 0.5, 2.4); // pulse min and max were establish by experience

	// convert pulse width to proper CCR value

	if(motor->channel == TIM_CHANNEL_1)
	{
		HAL_TIM_PWM_Start(motor->timer, motor->channel);
		motor->timer->Instance->CCR1 = (uint8_t)((pulse_width/20.) * 100);
	}

	else if(motor->channel == TIM_CHANNEL_2)
	{
		HAL_TIM_PWM_Start(motor->timer, motor->channel);
		motor->timer->Instance->CCR2 = (uint8_t)((pulse_width/20.) * 100);

	}

	else if(motor->channel == TIM_CHANNEL_3)
	{
		HAL_TIM_PWM_Start(motor->timer, motor->channel);
		motor->timer->Instance->CCR3 = (uint8_t)((pulse_width/20.) * 100);

	}

	else if(motor->channel == TIM_CHANNEL_4)
	{
		HAL_TIM_PWM_Start(motor->timer, motor->channel);
		motor->timer->Instance->CCR4 = (uint8_t)((pulse_width/20.) * 100);

	}
}
