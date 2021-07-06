#include "Map.h"

typedef struct{
    int key;
    char info[90];
}Pair;

typedef struct{
    int flag;
    Pair hist;
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
void leer_progreso(int*, char*);
void leer_punt(Map*, char* );
void actualizar_finales_o(int*);
void agregar_puntuacion( int);
void guardar_progreso_partida(int, int, int, int, int, int);
void print_pasaporte(pj*);
void reset_progreso_partida();