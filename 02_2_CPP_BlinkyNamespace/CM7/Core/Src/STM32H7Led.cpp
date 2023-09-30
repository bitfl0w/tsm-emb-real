#include "STM32H7Led.h"

// parametrized constructor
myhal::STM32H7Led::STM32H7Led(GPIO_TypeDef* p_Port, uint16_t p_Pin) :
	m_Port(p_Port),
	m_Pin(p_Pin) {
}

// empty constructor
myhal::STM32H7Led::STM32H7Led() {

}

// method definition
void myhal::STM32H7Led::ToggleLed() {
	HAL_GPIO_TogglePin(m_Port, m_Pin);
}
