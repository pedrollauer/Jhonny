#include <stdio.h>
#include <modbus/modbus.h>
#include <iostream>
int main(void) {
  std::cout<<"Conectando modbus..."<<std::endl;
  modbus_t *mb;
  uint16_t tab_reg[32];
  mb = modbus_new_tcp("192.168.1.3",1502);
  modbus_connect(mb);
  std::cout << "Conectando";
  int someValue; 

  /* Read 5 registers from the address 0 */
  modbus_write_bit(mb,0,true);
  someValue=modbus_read_registers(mb, 0, 1, tab_reg);
  std::cout<<"M0-----> "<<someValue<<std::endl;
  modbus_close(mb);
  modbus_free(mb);
}

