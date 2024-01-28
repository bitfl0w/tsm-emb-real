#include "STM32H7Led.h"


STM32H7Led::STM32H7Led() {

}

STM32H7Led::STM32H7Led(GPIO_TypeDef* Port, uint16_t Pin) : Port(Port), Pin(Pin) {

}

void STM32H7Led::ToggleLED() {
	HAL_GPIO_TogglePin(Port, Pin);
}
