typedef enum Port_PinDirectionType {
    PORT_PIN_IN,
    PORT_PIN_OUT,
} Port_PinDirectionType;

typedef enum Dio_LevelType {
    STD_LOW,
    STD_HIGH,
} Dio_LevelType;


//Port Driver function definitions
void Port_Init(unsigned char port_index);
void Port_SetPinDirection(unsigned char port_index, unsigned char pins_mask, Port_PinDirectionType pins_direction);
void Port_SetPinPullUp(unsigned char port_index, unsigned char pins_mask,unsigned char enable);
void Port_SetPinPullDown(unsigned char port_index, unsigned char pins_mask,unsigned char enable);

//DIO(Digital I/O) Driver function definitions 
unsigned char DIO_ReadPort(unsigned char port_index, unsigned char pins_mask);
void DIO_WritePort(unsigned char port_index, unsigned char pins_mask,unsigned char pins_level);
void DIO_FlipPort(unsigned char port_index, unsigned char pins_mask);
