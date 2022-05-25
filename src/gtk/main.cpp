#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <pthread.h>
#include <modbus/modbus.h>
#include <iostream>

GtkWidget *window;
GtkWidget *fixed1;
GtkWidget *btn_servo_on;
GtkWidget *l_status;
GtkBuilder *builder;

int status_servo=0;

int parar(){
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





result=modbus_write_register(ctx,0x40e,0x3f05);



modbus_close(ctx);
modbus_free(ctx);
}

int direita(){
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








status_servo=1;
gtk_label_set_text(GTK_LABEL(l_status), "SERVO ON");
result=modbus_write_register(ctx,0x40e,0x3f07);


modbus_close(ctx);
modbus_free(ctx);
}
int esquerda(){
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







                status_servo=1;
    gtk_label_set_text(GTK_LABEL(l_status), "SERVO ON");
result=modbus_write_register(ctx,0x40e,0x3f03);



modbus_close(ctx);
modbus_free(ctx);
}
int servo_on(int comando){
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



if(comando==1){

result=modbus_write_register(ctx,0x40e,0x3f01);
}else{

result=modbus_write_register(ctx,0x40e,0x3f00);
}



modbus_close(ctx);
modbus_free(ctx);
}
int main(int argc,char *argv[]){




        gtk_init(&argc,&argv);
        builder=gtk_builder_new_from_file("interface.glade");
        window=GTK_WIDGET(gtk_builder_get_object(builder,"window"));
//        g_signal_connect(window,"destroy",G_CALLBACK(g_main_quit),NULL);
        gtk_builder_connect_signals(builder,NULL);

        btn_servo_on=GTK_WIDGET(gtk_builder_get_object(builder,"btn_servo_on"));
        l_status=GTK_WIDGET(gtk_builder_get_object(builder,"l_status"));
        fixed1=GTK_WIDGET(gtk_builder_get_object(builder,"fixed1"));
gtk_window_set_default_size(GTK_WINDOW(window), 800, 500); 
        gtk_widget_show(window);
        gtk_main();



        return EXIT_SUCCESS;    
}

extern "C" G_MODULE_EXPORT void on_pressed(GtkButton *b)
{

        fprintf(stderr, "Voce apertou\n");
        printf("Voce apertou!");
}
extern "C" G_MODULE_EXPORT void on_release(GtkButton *b)
{
        fprintf(stderr, "Voce soltou\n");
        printf("Voce soltou!");
}
extern "C" G_MODULE_EXPORT void on_click(GtkButton *b)
{
       

        printf("Voce clicou!");
        if(status_servo==1){
                status_servo=0;
    gtk_label_set_text(GTK_LABEL(l_status), "SERVO OFF");
        }else{
                status_servo=1;
    gtk_label_set_text(GTK_LABEL(l_status), "SERVO ON");
        }
        servo_on(status_servo);
}
extern "C" G_MODULE_EXPORT void parar(GtkButton *b)
{
        fprintf(stderr, "parar");
        parar();
}
extern "C" G_MODULE_EXPORT void esquerda(GtkButton *b)
{
        fprintf(stderr, "esquerda");
        esquerda();
}
extern "C" G_MODULE_EXPORT void direita(GtkButton *b)
{
        direita();
        fprintf(stderr, "direita");
}
