/*
 * sg90.h
 *
 *  Created on: Jul 21, 2021
 *      Author: Igor_S
 */

#ifndef INC_SG90_H_
#define INC_SG90_H_

#include "tim.h"


typedef struct servo_motor
{
	TIM_HandleTypeDef *timer;
	uint32_t channel;

}servo_motor;

void sg90_init(servo_motor *motor, TIM_HandleTypeDef *htim, uint32_t channel);
void sg90_set_angle(servo_motor *motor, uint8_t angle);

#endif /* INC_SG90_H_ */
