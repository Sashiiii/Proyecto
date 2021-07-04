#include "pp.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void* create_pair(){
    Pair* p = (Pair*)malloc(sizeof(Pair));
    p->key = 0;  
    return p;
}

void leer_archivo(Map* mapa, char* archivo){
  int cont = 0;
  Pair* par; 
  
  FILE *archivoEntrada = fopen(archivo, "r");
/* Si hubo algun problema con abrir el archivo imprime el siguiente mensaje. */
  if (archivoEntrada == NULL){
    //printf("El archivo no se pudo abrir en modo lectura");
    return;
  }
/* Aqui se almacenaran el archivo por linea. */
  char linea[1024];
  char *datos;
  while ((fscanf(archivoEntrada, "%[^\n]s", linea) != EOF)){
    par = create_pair();
    fgetc(archivoEntrada);

    datos = strtok(linea, "\0");
    strcpy(par->info,datos);
    par->key = cont;
    
    insertMap(mapa,&par->key,par);
    cont++;
  }
  
  if (fclose(archivoEntrada) == EOF){
// Si hubo algun problema al cerrar el archivo se imprime el siguiente mensaje. 
    //printf("El archivo no se pudo cerrar correctamente\n");
  }
  else{
    //printf("El archivo se ha leido correctamente!\n");
  }
}

void leer_progreso(int* arreglo, char* archivo){
  int i;
  int contenido;
  FILE *archivoEntrada = fopen(archivo, "r");
  if (archivoEntrada == NULL){
    printf("El archivo no se pudo abrir en modo lectura\n");
    return;
  }
  for (i = 0; i < 8; i++){
    fscanf(archivoEntrada, "%d", &arreglo[i]);
  }
  printf("\n\n\n");
  fclose(archivoEntrada);
}

/* Funcion para leer el archivo con las puntuaciones de partidas anteriores */
void leer_punt(Map* puntajes, char* archivo){

  /* Se abre el archivo correspondiente. */
  FILE *archivoEntrada = fopen(archivo, "r");
  char linea[50];
  char *token;
  Pair* par;

  while (fscanf(archivoEntrada, "%[^\n]s", linea) != EOF){
    fgetc(archivoEntrada);
    par = create_pair();

    token = strtok(linea, ",");
    par->key = atoi(token);
    token = strtok(NULL, ",");
    strcpy(par->info, token);

    insertMap(puntajes, &par->key, par);
  }

  /* Se cierra el archivo. */
  if (fclose(archivoEntrada) == EOF){
    /* Si hubo algun problema con cerrar el archivo se imprime el siguiente mensaje. */
    printf("El archivo no se pudo cerrar correctamente");
  }
}

void actualizar_finales_o(int* array){
  char archivo[30];
  strcpy(archivo, "finales_obtenidos.txt");
  FILE *archivoE = fopen(archivo, "w");

  for(int i = 0; i<8 ; i++){
    fprintf(archivoE,"%d", array[i]);
    if(i!=7)fprintf(archivoE," ");
  }
  fclose(archivoE);
}
void agregar_puntuacion( int puntaje_total){
  char linea[10];
  char nombre_run[4];
  char archivo[30];
  strcpy(archivo, "partidas_terminadas.txt");
  FILE *archivoE = fopen(archivo, "r");
  printf("INGRESA TU NOMBRE (USANDO 3 CARACTERES) Y PRESIONA <ENTER>: ");
  scanf("%s", nombre_run);
  if((fscanf(archivoE, "%[^\n]s", linea) != EOF)){
    fclose(archivoE);
    archivoE = fopen(archivo, "a");
    fprintf(archivoE, "\n%d,%s",puntaje_total,nombre_run);
  }else{
    fclose(archivoE);
    archivoE = fopen(archivo, "a");
    fprintf(archivoE, "%d,%s",puntaje_total,nombre_run);
  }
  fclose(archivoE);
}