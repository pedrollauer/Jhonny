#include "cparser.h"

//TODO
//Se propriedade_string retorna null propriedade_int precisar avisar
// 
void test(){
    /////BenchMark Inicio
    int test=propriedade_int("C0"); 
    /* printf("Teste 1------->"); */
    if(test==32132){
            /* printf("passou!"); */
    }else{
            /* printf("falhou!"); */
    }
    /* printf("\n"); */
    /* printf("Teste 2------->"); */
    test=propriedade_int("vale0"); 
    if(test==32132){
            /* printf("passou!"); */
    }else{
            /* printf("falhou!"); */
            /* printf("recebido:%d,esperado:%d",test,32132); */
    }
    /* printf("\n"); */
    /* printf("Teste 3------->"); */
    test=propriedade_int("z_pega"); 
    if(test==330765){
            /* printf("passou!"); */
    }else{
            /* printf("falhou!"); */
    }

    /* printf("\n"); */
    /* printf("Teste 5------->"); */
    test=propriedade_int("z_req_el"); 
    if(test==1094656 ){
            /* printf("passou!"); */
    }else{
            /* printf("falhou!"); */
    }

    /* printf("\n"); */
    /* printf("Teste 6------->"); */
    test=propriedade_int("z_desc"); 
    if(test==1826291){
            /* printf("passou!"); */
    }else{
            /* printf("falhou!"); */
    }


    printf("\n");
    printf("Teste 7------->");
    test=propriedade_int("c_0"); 
    if(test==29908){
            /* printf("passou!"); */
    }else{
            /* printf("falhou!"); */
            /* printf("---------------------------->%d",test); */
    }


    /* printf("\n"); */
    /* printf("Teste 8------->"); */
    test=propriedade_int("c_desc"); 
    if(test==-9431){
            printf("passou!");
    }else{
            printf("falhou!");
    }


    /* printf("\n"); */
    /* printf("Teste 9------->"); */
    test=propriedade_int("c_90"); 
    if(test==65537){
            /* printf("passou!"); */
    }else{
            /* printf("falhou!"); */
    }


    /* printf("\n"); */
    printf("Teste 10------->");
    test=propriedade_int("c_-90"); 
    if(test==-17300){
            /* printf("passou!"); */
    }else{
            /* printf("falhou!"); */
    }


    /* printf("\n"); */
    /* printf("Teste 11------->"); */
    test=propriedade_int("x_elet"); 
    if(test==47327){
            /* printf("passou!"); */
    }else{
            /* printf("falhou!"); */
    }

    /* printf("\n"); */
    /* printf("Teste 12------->"); */
    test=propriedade_int("z_transp"); 
    if(test==1579733){
            /* printf("passou!"); */
    }else{
            /* printf("falhou!"); */
    }


    /* printf("\n"); */
    /* printf("Teste 13------->"); */
    test=propriedade_int("vel_aprox_x"); 
    if(test==600){
            /* printf("passou!"); */
    }else{
            /* printf("falhou!"); */
    }

    /* printf("\n"); */
    /* printf("Teste 14------->"); */
    test=propriedade_int("punho"); 
    if(test==37064){
            /* printf("passou!"); */
    }else{
            /* printf("falhou!"); */
    }
    printf("\n");
    /////FIM
}
int main(){
    float startTime=(float)clock()/CLOCKS_PER_SEC;

    test();

    float endTime=(float)clock()/CLOCKS_PER_SEC;
    float elapsedTime=endTime-startTime;
    printf("Elapsed time--->%f",elapsedTime); 
    return 1;
}

