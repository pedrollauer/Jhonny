#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *propriedade_string(char* name){
    FILE   *file;
    file=fopen("config.cfg","r"); 
    char c;
    char *return_string=(char *) malloc(sizeof(char));
    short size=1;

    while(c!=EOF){
       c=getc(file); 

       if(c==*(name)){
           do{    
                size++;
                c=getc(file); 
                if(c!=*(name+size-1)){
                    break;
                    size=0;
                }
           }while(c!='=');
           size=0;
           while(c!='\n'){
                size++;
                c=getc(file);
                return_string=realloc(return_string,size*sizeof(char));
                *(return_string+size)='\0';
                *(return_string+size-1)=c;
           }
       }
    }
    fclose(file);
    return return_string;
}


int propriedade_int(char* name){
    
    int retorneMe=atoi(propriedade_string(name));
    return retorneMe;
}
int main(){
    float startTime=(float)clock()/CLOCKS_PER_SEC;

    /////BenchMark Inicio
    char *z_rec_el=propriedade_string("C0");
    int x_elet=propriedade_int("vale0");
    printf("Property--->%s\n",z_rec_el);
    printf("Property--->%d\n",x_elet);
    /////FIM
    float endTime=(float)clock()/CLOCKS_PER_SEC;
    float elapsedTime=endTime-startTime;
    printf("Elapsed time--->%f",elapsedTime); 
    return 1;
}
