class AccSensor {
private:
	const uint32_t INSTANCE = 1;
	const uint32_t FUNCTION_ACC = MOTION_ACCELERO;

private:
	void InitSensor(void);
	void UpdateValues(void);
};
