//
// Reads air pressure
//
int get_pressure(int *pressure, int *p_temp);

//
// Reads the temperature and humidity
//
int get_temp_humid(int *temp, int *humid);

//
// Initializes i2c
//
int init(int i2c_num);

//
// closes i2c
//
void stop(void);