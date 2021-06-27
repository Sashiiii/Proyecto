#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Map.h"
#include "pp.h"

int is_equal_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0) return 1;
    return 0;
}

//  función para comparar claves de tipo string
//  retorna 1 si son key1<key2

int lower_than_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2) < 0) return 1;
    return 0;
}

//  función para comparar claves de tipo int
//  retorna 1 si son iguales

int is_equal_int(void * key1, void * key2) {
    if(*(int*)key1 == *(int*)key2) return 1;
    return 0;
}

//  función para comparar claves de tipo int
//  retorna 1 si son key1<key2

int lower_than_int(void * key1, void * key2) {
    if(*(int*)key1 < *(int*)key2) return 1;
    return 0;
}

int higher_than_int(void * key1, void * key2) {
    if(*(int*)key1 > *(int*)key2) return 1;
    return 0;
}

int main(){
    int opcion = 0;
  //Aqui inicializamos los mapas   
    Map* nombres_h = createMap(is_equal_int);
    Map* nombres_m = createMap(is_equal_int);
    Map* apellidos = createMap(is_equal_int);
    Map* paises = createMap(is_equal_int);
    Map* paisesMal = createMap(is_equal_int);
    Map* saludos = createMap(is_equal_int);
    Map* despedidas = createMap(is_equal_int);
    Map* series = createMap(is_equal_int);
    Map* tabla_punt = createMap(is_equal_int);
    setSortFunction(tabla_punt, lower_than_int);
    Map* finales = createMap(is_equal_int);

  //aqui se empizan a llenar los mapas
    char archivo[30];
    strcpy(archivo, "nombres_h.txt");
    leer_archivo(nombres_h, archivo);

    strcpy(archivo, "nombres_m.txt");
    leer_archivo(nombres_m, archivo);

    strcpy(archivo, "apellidos.txt");
    leer_archivo(apellidos, archivo);

    strcpy(archivo, "paises.txt");
    leer_archivo(paises, archivo);

    strcpy(archivo, "paisesMalEscritos.txt");
    leer_archivo(paisesMal, archivo);

    strcpy(archivo, "saludos.txt");
    leer_archivo(saludos, archivo);

    strcpy(archivo, "despedidas.txt");
    leer_archivo(despedidas, archivo);

    strcpy(archivo, "series.txt");
    leer_archivo(series, archivo);
    Pair* a;
    int dia,gen;
    clock_t tm1, tm2;
    int asd;
    while (opcion!=5){
    /* SWITCH MENU */
        switch (opcion){
    //Caso 1: Empezar nuevo juego 
        case 1:
            printf("Soy\n1. Chico\n2. Chica\n");
            scanf("%d",gen);
            if(gen == 1){
                printf("Bienvenido a tu nuevo trabajo en <CHILE>!\n");
                printf("Estaras encargado de revisar los documentos de la gente que busca ingresar a nuestro pais\n");
            }
            if(gen == 2){
                printf("Bienvenida a tu nuevo trabajo en <CHILE>!\n");
                printf("Estaras encargada de revisar los documentos de la gente que busca ingresar a nuestro pais\n");
            }
            dia = 1;
            while(dia<=7){
                if(dia==1){
                    tm1 = clock();
                    while(300 > (tm2 - tm1) / CLOCKS_PER_SEC){                        

                        /* DIA 1 */

                    tm2 = clock();
                    }
                    //printf("amount of processor time: %d ticks and %d seconds\n",(tm2 - tm1), (tm2 - tm1) / CLOCKS_PER_SEC);              
                    dia++;
                }
           
                if(dia==2){
                    tm1 = clock();
                    while(300 > (tm2 - tm1) / CLOCKS_PER_SEC){

                        /* DIA 2 */

                    tm2 = clock();
                    }             
                    dia++;
                }         
           
                if(dia==3){
                    tm1 = clock();
                    while(300 > (tm2 - tm1) / CLOCKS_PER_SEC){

                        /* DIA 3 */
                
                    tm2 = clock();
                    }             
                    dia++;
                }
           
                if(dia==4){
                    tm1 = clock();
                    while(300 > (tm2 - tm1) / CLOCKS_PER_SEC){

                        
                        /* DIA 4 */
                
                    tm2 = clock();
                    }             
                    dia++;
                }
           
                if(dia==5){
                    tm1 = clock();
                    while(300 > (tm2 - tm1) / CLOCKS_PER_SEC){

                        /* DIA 5 */

                    tm2 = clock();
                    }             
                    dia++;
                }
           
                if(dia==6){
                    tm1 = clock();
                    while(300 > (tm2 - tm1) / CLOCKS_PER_SEC){
                        /* DIA 6 */

                    tm2 = clock();
                    }             
                    dia++;
                }

                if(dia==7){
                    tm1 = clock();
                    while(300 > (tm2 - tm1) / CLOCKS_PER_SEC){

                        /* DIA 7 */
                
                    tm2 = clock();
                    }             
                    dia++;
                }
            }
            break;
    //Caso 2: Cargar partida
        case 2:
            break;
    //Caso 3: Tabla de puntajes 
        case 3:

    //Se obtiene el primer elemento del mapa de puntajes para ver si hay elementos o no y determinar que se va a mostrar por pantalla
            a = firstMap(tabla_punt);
            if (a==NULL){
                printf("No hay puntajes para mostrar :c\n");
            }else{
                printf("Usuario  |  Puntaje\n");
                while(a!=NULL){
                    printf("%s , %d\n", a->info, a->key);
                    a = nextMap(tabla_punt);
                }
            }
            opcion = 0;
        break;
       //Caso 4: Mostrar finales obtenidos 
        case 4:
            opcion = 0;
            break;
       //Caso 5: Salir de la aplicacion 
        case 5:
            break;
        default:
            printf("==========================\n");
            printf("|   PEPE DAME EL PAPEL   |\n");
            printf("==========================\n\n"); 
            printf("1.- Empezar nuevo juego\n2.- Cargar partida\n3.- Tabla de puntajes\n");
            printf("4.- Mostrar finales obtenidos\n5.- Salir");
            printf("\n\n ~Seleccione una opcion, escriba un *NUMERO*: ");
            scanf("%d", &opcion);
            printf("\n\n");
            break;
        }
    }    
}