#include <gtk/gtk.h>
#include <gtk/gtkx.h>


GtkWidget *window;
GtkWidget *fixed1;
GtkWidget *btn_servo_on;
GtkWidget *l_status;
GtkBuilder *builder;


int main(int argc,char *argv[]){
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
        return EXIT_SUCCESS;    
}
extern "C" G_MODULE_EXPORT void on_click(GtkButton *b)
{
    gtk_label_set_text(GTK_LABEL(l_status), "SERVO OFF");
}
