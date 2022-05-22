#include "cparser.h"
#include <stdbool.h>
char *propriedade_string(char* name){
    FILE   *file;
    file=fopen("config.cfg","r"); 
    char c;
    char *return_string=(char *) malloc(sizeof(char));
    short size=0;
    bool start_line=true;

    while((c=getc(file))!=EOF){
            if(start_line){
                    start_line=false;
                    if(c==*(name)){
                            size=0;
                        while((c=getc(file))!='='){ 
                                    size++;
                                    if(c==*(name+size)){
                                            continue;
                                    }else{
                                            break;
                                    }
                            }
                                    if((size+1)==strlen(name) ){
                   
                                            size=0;
                                           while((c=getc(file))!='\n'){
                                                    size++;
                                                    return_string=(char *)realloc(return_string,(size+1)*sizeof(char));
                                                    *(return_string+size)='\0';
                                                    *(return_string+size-1)=c;
                                            }     
                                                return return_string;
                                            }
                                        
                    
            }
            }

            if(c=='\n'){
                    start_line=true;
            }
    }
    fclose(file);
    return NULL;
}


int propriedade_int(char* name){
    
    int retorneMe=atoi(propriedade_string(name));
    return retorneMe;
}
