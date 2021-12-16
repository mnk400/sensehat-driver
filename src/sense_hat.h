#ifdef __cplusplus
extern "C"{
#endif 
//
// Reads air pressure from LPS25H
//
int get_pressure();

//
// Reads air pressure from LPS25H
//
float get_temperature_from_lps25h();

//
// Reads the temperature from HTS221
//
float get_temperature();

//
// Reads the humidity from HTS221
//
float get_humidity();

//
// Initializes i2c
//
int init(int i2c_num);

//
// closes i2c
//
void stop(void);

#ifdef __cplusplus
}
#endif