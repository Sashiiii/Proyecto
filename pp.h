#include "Map.h"

typedef struct{
    int key;
    char info[100];
}Pair;

typedef struct{
    int id;
    int flag;
    char title[100];
    char hist[1000];
}FIN;

typedef struct {
    char nombre[100];
    char apellido[100];
    char serie[100];
    char motivo[100];
    char pais[100];
    char genero[2];
}pj;

void leer_archivo(Map*, char*);