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
  //printf("~Por favor ingrese el archivo que se desea leer:\n");
  
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
    
    //printf("%d, ", par->key);
    //printf("%s\n", par->info);
/* Se agrega en la lista los datos de la variable 'Lugar'. */
    insertMap(mapa,&par->key,par);
    cont++;
  }
  if (fclose(archivoEntrada) == EOF){
/* Si hubo algun problema al cerrar el archivo se imprime el siguiente mensaje. */
    //printf("El archivo no se pudo cerrar correctamente\n");
  }
  else{
    //printf("El archivo se ha leido correctamente!\n");
  }
}