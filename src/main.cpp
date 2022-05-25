#include <stdio.h>
#include <modbus/modbus.h>
#include <iostream>

int main(){
//Create a new RTU context with proper serial parameters (in this example,
//device name /dev/ttyS0, baud rate 9600, no parity bit, 8 data bits, 1 stop bit)
modbus_t *ctx = modbus_new_rtu("/dev/ttyUSB0", 9600, 'N', 8, 1);
int modo= modbus_rtu_set_serial_mode(ctx,MODBUS_RTU_RS485);
std::cout<<"MODO DE COMUNICAO"<<std::endl;
if(!ctx) {
    fprintf(stderr, "Failed to create the context: %s\n", modbus_strerror(errno));
    exit(1);
}

if (modbus_connect(ctx) == -1) {
    fprintf(stderr, "Unable to connect: %s\n", modbus_strerror(errno));
    modbus_free(ctx);
    exit(1);
}

//Set the Modbus address of the remote slave (to 3)
modbus_set_slave(ctx, 2);


uint16_t reg[5];// will store read registers values

//Read 5 holding registers starting from address 10
int num = modbus_read_registers(ctx,0x300,1, reg);
int result;


printf("----------------------------------------->%d\n",result);



if (num !=1) {// number of read registers is not the one expected
    std::cout<<"ERRO------->"<<modbus_strerror(errno)<<std::endl;
}

std::cout<<"MITO---->"<<reg[0]<<std::endl;


while(true){

num = modbus_read_registers(ctx,0x0012,1, reg);
result=modbus_write_register(ctx,0x40e,0x3f00);
std::cout<<"Velocidade--------->"<<reg[0]<<std::endl;
num = modbus_read_registers(ctx,0x40e,1, reg);
std::cout<<"STATUS--------->"<<num<<std::endl;

}
modbus_close(ctx);
modbus_free(ctx);
}
