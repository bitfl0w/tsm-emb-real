#include "STM32H7Led.h"
#include "stm32h7xx_hal.h"

// parametrized constructor
STM32H7Led::STM32H7Led(GPIO_TypeDef* p_Port, uint16_t p_Pin) :
	m_Port(p_Port),
	m_Pin(p_Pin) {
	HAL_GPIO_WritePin(p_Port, p_Pin, GPIO_PIN_RESET); // turn off leds upon creation
}

// empty constructor
STM32H7Led::STM32H7Led() {

}

// method definition
void STM32H7Led::ToggleLed() {
	HAL_GPIO_TogglePin(m_Port, m_Pin);
}

void STM32H7Led::SetLed(bool State) {
	if(State) {
		HAL_GPIO_WritePin(m_Port, m_Pin, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(m_Port, m_Pin, GPIO_PIN_RESET);
	}
}
