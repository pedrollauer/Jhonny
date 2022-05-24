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

modbus_t *ctx;

void setup(){
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



//Read 5 holding registers starting from address 10

}


void* loop(void *msg1){
        while(true){

        printf("Hey! I'm talking to the servodrive!\n");
        printf("=)");

uint16_t reg[5];// will store read registers values

int num = modbus_read_registers(ctx,0x300,1, reg);
int result;


result=modbus_write_register(ctx,0x30c,0x3f01);
printf("----------------------------------------->%d\n",result);



if (num !=1) {// number of read registers is not the one expected
    std::cout<<"ERRO------->"<<modbus_strerror(errno)<<std::endl;
}

std::cout<<"MITO---->"<<reg[0]<<std::endl;



        }
}


int main(int argc,char *argv[]){
        pthread_t t1;
        pthread_create(&t1,NULL,loop,NULL);
        gtk_init(&argc,&argv);
        builder=gtk_builder_new_from_file("interface.glade");
        window=GTK_WIDGET(gtk_builder_get_object(builder,"window"));
//        g_signal_connect(window,"destroy",G_CALLBACK(g_main_quit),NULL);
        gtk_builder_connect_signals(builder,NULL);

        btn_servo_on=GTK_WIDGET(gtk_builder_get_object(builder,"btn_servo_on"));
        l_status=GTK_WIDGET(gtk_builder_get_object(builder,"l_status"));
        fixed1=GTK_WIDGET(gtk_builder_get_object(builder,"fixed1"));

        gtk_widget_show(window);
        gtk_main();
        pthread_join(t1,NULL);
        modbus_close(ctx);
        modbus_free(ctx);
        return EXIT_SUCCESS;    
}

extern "C" G_MODULE_EXPORT void on_click(GtkButton *b)
{
    gtk_label_set_text(GTK_LABEL(l_status), "SERVO OFF");
}
