#ifndef IDRIVER_H_
#define IDRIVER_H_

typedef struct 
{    
    char *(*device_name)(void);
    int (*device_init)(void);
    int (*device_write)(unsigned char state);
    int (*device_read)(void);
    int (*device_deinit)(void);
} IDriver;

#endif /* IDRIVER_H_ */
