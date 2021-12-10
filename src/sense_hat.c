#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define HTS221_ADDRESS 	0x5F
#define LPS25H_ADDRESS  0x5C

// Struct which contains the file descriptors for i2c access
struct i2c_files
{
    int HTS221;
    int LPS25H;
};

// Stuct which contains the current state of each sensor
// -1 = configuration not attempted
// 0 = configuration attempted but failed
// 1 = confugration succeeded 
struct sensor_states
{
    int HTS221;
    int LP25H;
};

struct i2c_files fds = {-1, -1};
struct sensor_states state = {-1, -1};

unsigned char sensor_initializer[32];

int init(int i2c_num)
{
    char filename[32];
    sprintf(filename, "/dev/i2c-%d", i2c_num);

    fds.HTS221 = open(filename, O_RDWR);
    if(ioctl(fds.HTS221, I2C_SLAVE, HTS221_ADDRESS) < 0)
    {
        fprintf(stderr, "Failed to acquire bus for HTS221 temperature and humidty sensor\n");
        state.HTS221 = 0;
    }
    else
    {
        init_HTS221(fds.HTS221);
        state.HTS221 = 1;
    }

    fds.LPS25H = open(filename, O_RDWR);
    if(ioctl(fds.LPS25H, I2C_SLAVE, LPS25H_ADDRESS) < 0)
    {
        fprintf(stderr, "Failed to acquire bus for LP25H pressure sensor\n");
        state.LP25H = 0;
    }
    else
    {
        init_LP15H(fds.LPS25H);
        state.LP25H = 1;
    }

}

void init_HTS221(int file)
{
    // code to initialize and caliberate HTS221 goes here
}

void init_LP15H(int file)
{
    // code to intialize LP15H goes here
}