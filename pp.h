#include "Map.h"

typedef struct{
    int key;
    char info[100];
}Pair;

typedef struct{
    int id;
    int flag;
    char title[50];
    char hist[100];
}FIN;

typedef struct {
    char nombre[30];
    char apellido[30];
    char serie[30];
    char motivo[30];
    char pais[30];
    char genero[2];
    char fecha[15];
}pj;

void leer_archivo(Map*, char*);