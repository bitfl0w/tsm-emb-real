#include <cstdint>
#include "stm32h7xx_hal.h"

namespace myhal {
	class STM32H7Led {
	public:
		void ToggleLed(void);

		// constructor
		STM32H7Led(GPIO_TypeDef* p_Port, uint16_t p_Pin);
		STM32H7Led();
	private:
		GPIO_TypeDef* m_Port;
		uint16_t m_Pin;
	};
}

