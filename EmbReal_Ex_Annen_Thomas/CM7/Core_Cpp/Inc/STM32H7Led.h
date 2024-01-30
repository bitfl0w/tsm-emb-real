#include <cstdint>
#include "stm32h7xx_hal.h"

class STM32H7Led {
public:
	void ToggleLed(void);
	void SetLed(bool State);

	// constructor
	STM32H7Led(GPIO_TypeDef* p_Port, uint16_t p_Pin);
	STM32H7Led();
private:
	GPIO_TypeDef* m_Port;
	uint16_t m_Pin;
};

