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
    
    while (opcion!=5){
        switch (opcion){
       //Caso 1: Empezar nuevo juego 
        case 1:
            /* code */
            break;
       //Caso 2: Cargar partida
        case 2:
            break;
       //Caso 3: Tabla de puntajes 
        case 3:
    //Se limpia la pantalla
            system("cls");
    //Se obtiene el primer elemento del mapa de puntajes para ver si hay elementos o no y determinar que se va a 
    //mostrar por pantalla
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
            printf("=========================\n");
            printf("|  PEPE DAME EL PAPEL   |\n");
            printf("=========================\n\n"); 
       
            printf("1.- Empezar nuevo juego\n2.- Cargar partida\n3.- Tabla de puntajes\n");
            printf("4.- Mostrar finales obtenidos\n5.- Salir");
            printf("\n\n ~Seleccione una opcion, escriba un *NUMERO*: ");
            scanf("%d", &opcion);
            printf("\n\n");
            break;
        }
    }    
}