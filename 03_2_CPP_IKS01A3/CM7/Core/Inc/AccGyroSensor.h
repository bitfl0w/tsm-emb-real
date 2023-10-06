class AccGyroSensor {
private:
	const uint32_t INSTANCE = 0;
	const uint32_t FUNCTION_INIT_ACC_GYRO = MOTION_ACCELEROMOTION_GYRO;
	const uint32_t FUNCTION_ACC = MOTION_ACCELERO;
	const uint32_t FUNCTION_GYRO = MOTION_GYRO;

public:
	void InitSensor(void);
	void UpdateValues(void);
};
