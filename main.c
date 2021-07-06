#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "Map.h"
#include "pp.h"

int incorrectos_total = 0, correctos_total = 0, aprobados_total = 0, rechazados_total = 0, puntaje_total = 0, dia = 0, finales_o[8];


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
//  retorna 1 si son key1 < key2

int lower_than_int(void * key1, void * key2) {
    if(*(int*)key1 < *(int*)key2) return 1;
    return 0;
}

int higher_than_int(void * key1, void * key2) {
    if(*(int*)key1 > *(int*)key2) return 1;
    return 0;
}

int main(){
    int opcion = 0, cont_finales=0;
    char nombre_run[4];
    Map* nombres_h = createMap(is_equal_int);
    Map* nombres_m = createMap(is_equal_int);
    Map* apellidos = createMap(is_equal_int);
    Map* paises = createMap(is_equal_int);
    Map* paisesMal = createMap(is_equal_int);
    Map* saludos = createMap(is_equal_int);
    Map* despedidas = createMap(is_equal_int);
    Map* motivos = createMap(is_equal_int);
    Map* series = createMap(is_equal_int);
    Map* tabla_punt = createMap(is_equal_int);
    setSortFunction(tabla_punt, lower_than_int);
    Map* finales = createMap(is_equal_int);
    Map* fechas_b = createMap(is_equal_int);
    Map* fechas_m = createMap(is_equal_int);
    Map* s_a = createMap(is_equal_int);
    Map* s_m = createMap(is_equal_int);
    Map* s_t = createMap(is_equal_int);
    Map* s_x = createMap(is_equal_int);
    Map* s_y = createMap(is_equal_int);
    Map* s_z = createMap(is_equal_int);
//aqui se empizan a llenar los mapas
    char archivo[30];

    strcpy(archivo, "finales_obtenidos.txt");
    leer_progreso(finales_o, archivo);

    strcpy(archivo, "finales.txt");
    leer_archivo(finales, archivo);

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

    strcpy(archivo, "motivos.txt");
    leer_archivo(motivos, archivo);

    strcpy(archivo, "fechas_bien.txt");
    leer_archivo(fechas_b, archivo);

    strcpy(archivo, "fechas_mal.txt");
    leer_archivo(fechas_m, archivo);

    strcpy(archivo, "s_a.txt");
    leer_archivo(s_a, archivo);

    strcpy(archivo, "s_m.txt");
    leer_archivo(s_m, archivo);

    strcpy(archivo, "s_t.txt");
    leer_archivo(s_t, archivo);

    strcpy(archivo, "s_x.txt");
    leer_archivo(s_x, archivo);

    strcpy(archivo, "s_y.txt");
    leer_archivo(s_y, archivo);

    strcpy(archivo, "s_z.txt");
    leer_archivo(s_z, archivo);
//  LLENAR MAPA FINALES
    Pair* a;
    int aux,gen,opcion2;
    clock_t tm1, tm2,tmi;
    pj *persona;
    char fecha[20],fecha2[20], razon[50];
/*  si correcto es 0, los datos se seleccionaran para que sea correcto, si no se seleccionara otro 
    numero para ver que dato se insertara incorrectamente  */
    int correcto, puntaje, incorrectos, correctos, aprobados, rechazados;
    srand(time(NULL));
    while (opcion!=5){
    /* SWITCH MENU */
        switch (opcion){
    //Caso 1: Empezar nuevo juego 
        case 1:
            do{
                printf("1.- Comenzar una nueva partida\n2.- Continuar partida anterior\n");
                scanf("%d", &opcion2); 
            }while(opcion2 != 1 && opcion2!=2);
            
            if(opcion2 == 1){
                dia = 1;
            }else if(opcion2 == 2){
                //leer archivo
                strcpy(archivo, "partida_actual.txt");
                FILE *archivoEntrada = fopen(archivo, "r");
                char linea[50];
                char *token;

                fscanf(archivoEntrada, "%d", &incorrectos_total);
                fscanf(archivoEntrada, ",%d", &correctos_total);
                fscanf(archivoEntrada, ",%d", &aprobados_total);
                fscanf(archivoEntrada, ",%d", &rechazados_total);
                fscanf(archivoEntrada, ",%d", &puntaje_total);
                fscanf(archivoEntrada, ",%d", &dia);

                /* Se cierra el archivo. */
                if (fclose(archivoEntrada) == EOF){
                /* Si hubo algun problema con cerrar el archivo se imprime el siguiente mensaje. */
                printf("El archivo no se pudo cerrar correctamente");
                }
            }
            correcto = 0 , puntaje = 0, incorrectos = 0, correctos = 0, aprobados = 0, rechazados = 0;
            
            while(dia < 8){
                
            //1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111    
            //1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111    
            //1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111    
                if(dia == 1){
                    system("cls");
                    printf("DIA 1:\n");
                    printf("Como sabras soy tu supervisor, asi que mi deber es darte la bienvenida a tu nuevo puesto de trabajo en la aduana chilena! \n*Dice fingiendo emocion*\n");
                    printf("Estaras encargado de revisar los documentos de la gente que busca ingresar a nuestro pais, ");
                    printf("bastante facil no?, pero fijate bien, hay mas gente con papeles falsos de lo que esperarias\n");
                    printf("Por cierto, cada vez que te equivoques descontaremos una parte de tu salario. Buena suerte y viva Chile! \n*Suspira aburrido y se va*\n\n");
                    printf("CUANDO ESTES LISTO PARA COMENZAR PRESIONA <ENTER>\n");
                    getch();
                    system("cls");
                    strcpy(fecha ,"20.06.1586");
                    tm1 = clock();
                    tm2 = clock();
                    tmi = clock();
                    do{                        
                    //se elige si la persona debera ser aprobada(1) o no(0)
                        correcto = rand() % 2;
                        persona = (pj*)malloc(sizeof(pj));

                    //se elige un numero para elegir los diferentes datos de la persona
                        gen = rand() % 2;                        
                        if(gen == 1){
                            strcpy(persona->genero, "F");
                            aux = rand()%43;
                            a = searchMap(nombres_m, &aux);
                            strcpy(persona->nombre, a->info);
                        }
                        if(gen == 0){
                            strcpy(persona->genero, "M");
                            aux = rand()%42;
                            a = searchMap(nombres_h, &aux);
                            strcpy(persona->nombre, a->info);
                        }
                        aux = rand() % 69;
                        a = searchMap(apellidos,&aux);
                        strcpy(persona->apellido, a->info);

                        aux = rand()%4;
                        a = searchMap(motivos, &aux);
                        strcpy(persona->motivo, a->info);
                        
                        aux = rand() % 23;
                        a = searchMap(paises,&aux);
                        strcpy(persona->pais,a->info);

                        aux = rand() % 16;
                        a = searchMap(fechas_b, &aux);
                        strcpy(persona->fecha, a->info);
                        
                        aux = rand() % 30;
                        a = searchMap(series, &aux);
                        strcpy(persona->serie,a->info);

                        if(correcto == 1){
                            aux = rand() % 3;
                            if(aux == 0){
                                aux = rand() % 23;
                                a = searchMap(paisesMal ,&aux);
                                strcpy(razon,"PAIS MAL ESCRITO");
                                strcpy(persona->pais,a->info);
                            }else if(aux == 1){
                                if(gen == 1){
                                    aux = rand() % 42;
                                    a = searchMap(nombres_h, &aux);
                                    strcpy(persona->nombre, a->info);
                                }
                                if(gen == 0){
                                    aux = rand() % 42;
                                    a = searchMap(nombres_m, &aux);
                                    strcpy(persona->nombre, a->info);
                                }
                                strcpy(razon,"GENERO EN PASAPORTE");
                            }else if(aux == 2){
                                aux = rand() % 16;
                                a = searchMap(fechas_m, &aux);
                                strcpy(persona->fecha, a->info);
                                strcpy(razon,"PASAPORTE VENCIDO");
                            }
                        }else{
                            strcpy(razon,"PASAPORTE CORRECTO");
                        }

                    //printear cuadro
                        printf("Restricciones: solo pasaportes validos\n");
                        printf("\n\nFECHA ACTUAL: %s\n\n", fecha);
                        print_pasaporte(persona);
                        printf("<OPCIONES>\n");
                        printf("PRESIONA EL NUMERO CORRESPONDIENTE Y <ENTER>\n");
                        printf("1. APROBAR\n2. RECHAZAR\n\n");
                        scanf("%d", &aux);
                        if((aux - 1) != correcto){
                            incorrectos++;
                    // MOSTRAR RAZON POR PANTALLA
                            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
                            printf("                            AMONESTACION\n");
                            printf("                            RAZON: %s\n\n", razon);
                            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
                        }else{
                            correctos++;
                        }
                        if(aux == 1){
                            aprobados++;
                        }else{
                            rechazados++;
                        }
                        printf("PARA DEJAR PASAR AL SIGUIENTE PRESIONA <ENTER>");
                        getch();
                        system("cls");
                    tm2 = clock();
                    }  while(30 > ((tm2 - tm1) / CLOCKS_PER_SEC));
                    puntaje = (correctos*50) - (incorrectos*25);
                    puntaje_total += puntaje;
                    incorrectos_total += incorrectos;
                    correctos_total += correctos_total;
                    aprobados_total += aprobados;
                    rechazados_total += rechazados;
                    printf("PUNTAJE: %d\n", puntaje);
                    if(puntaje < 0){ //CONDICIONES PERDER
                        printf("Final 6 de 8: Despedido!\n\n\n");
                        dia = 8;
                        finales_o[5] = 1;
                        actualizar_finales_o(finales_o);
                        agregar_puntuacion(puntaje_total);
                        if(((tmi - tm1) / CLOCKS_PER_SEC) < 60){
                            printf("Logro 4 de 8: Speedrun!\n\n\n");
                            dia = 8;
                            finales_o[3] = 1;
                            actualizar_finales_o(finales_o);
                        }
                        if(aprobados_total == 0 && finales_o[0]!=1){
                            printf("Logro 1 de 8: YOU SHALL NOT PASS!\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[0]=1;
                            actualizar_finales_o(finales_o);
                            system("cls");
                        }
                        if(rechazados_total == 0 && finales_o[1]!=1){
                            printf("Logro 2 de 8: Moises\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[1]=1;
                            actualizar_finales_o(finales_o);
                        }
                        if(correctos_total >= 100 && finales_o[4] != 1){
                            printf("Logro 5 de 8: Sonic\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[4]=1;
                            actualizar_finales_o(finales_o);
                        }
                    }else{
                        printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                        getch();
                        system("cls");
                    }
                    dia++;
                    guardar_progreso_partida(incorrectos_total,correctos_total, aprobados_total, rechazados_total, puntaje_total, dia);
                }
                
           //2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
           //2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
           //2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
                if(dia==2){
                    printf("DIA 2:\n");
                    printf("Veo que le agarraste el ritmo, desafortunadamente quieren limitar la cantidad de gente que entra al pais, ");
                    printf("por lo que a partir de hoy cada dia no podras autorizar pasaportes que contengan cierta letra en la serie de su pasaporte, asi que hoy no ");
                    printf("podra pasar nadie que tenga la letra X en la serie de su pasaporte\n");
                    printf("Buena suerte y VIVA CHILE!\n\n");
                    printf("CUANDO ESTES LISTO PARA COMENZAR PRESIONA <ENTER>\n");
                    getch();
                    system("cls");
                    puntaje = 0, aprobados = 0, rechazados = 0, incorrectos = 0, correctos = 0;
                    tm1 = clock();
                    strcpy(fecha ,"21.06.1586");
                    do{                       
                    //se elige si la persona debera ser aprobada(1) o no(0)
                        correcto = rand() % 2;
                        persona = (pj*)malloc(sizeof(pj));

                    //se elige un numero para elegir los diferentes datos de la persona
                        gen = rand() % 2;
                        if(gen == 1){
                            strcpy(persona->genero, "F");
                            aux = rand()%42;
                            a = searchMap(nombres_m, &aux);
                            strcpy(persona->nombre, a->info);
                        }else if(gen == 0){
                            strcpy(persona->genero, "M");
                            aux = rand()%42;
                            a = searchMap(nombres_h, &aux);
                            strcpy(persona->nombre, a->info);
                        }

                        aux = rand() % 69;
                        a = searchMap(apellidos,&aux);
                        strcpy(persona->apellido, a->info);

                        aux = rand()%4;
                        a = searchMap(motivos, &aux);
                        strcpy(persona->motivo, a->info);
                        
                        aux = rand() % 23;
                        a = searchMap(paises,&aux);
                        strcpy(persona->pais,a->info);

                        aux = rand() % 16;
                        a = searchMap(fechas_b, &aux);
                        strcpy(persona->fecha, a->info);

                        aux = rand() % 29;
                        a = searchMap(series, &aux);
                        strcpy(persona->serie,a->info);

                        if(correcto == 1){
                            aux = rand() % 4;
                            if(aux == 0){
                                aux = rand() % 23;
                                a = searchMap(paisesMal ,&aux);
                                strcpy(razon,"PAIS MAL ESCRITO");
                                strcpy(persona->pais,a->info);
                            }else if(aux == 1){
                                if(gen == 1){
                                    aux = rand() % 43;
                                    a = searchMap(nombres_h, &aux);
                                    strcpy(persona->nombre, a->info);
                                }
                                if(gen == 0){
                                    aux = rand() % 43;
                                    a = searchMap(nombres_m, &aux);
                                    strcpy(persona->nombre, a->info);
                                }
                                strcpy(razon,"GENERO EN PASAPORTE");
                            }else if(aux == 2){
                                aux = rand() % 16;
                                a = searchMap(fechas_m, &aux);
                                strcpy(persona->fecha, a->info);
                                strcpy(razon,"PASAPORTE VENCIDO");
                            }else if(aux == 3){
                                aux = rand() % 14;
                                a = searchMap(s_x, &aux);
                                strcpy(persona->serie, a->info);
                                strcpy(razon,"PASAPORTE RESTRINGIDO");
                            }
                        }else{
                            strcpy(razon,"PASAPORTE CORRECTO");
                        }
                        
                    //printear cuadro
                        printf("Restricciones: solo pasaportes validos\n");
                        printf("               pasaportes con letra X en su serie no podran ser autorizados\n");
                        printf("\n\nFECHA ACTUAL: %s\n\n", fecha);
                        print_pasaporte(persona);
                        printf("<OPCIONES>\n");
                        printf("PRESIONA EL NUMERO CORRESPONDIENTE Y <ENTER>\n");
                        printf("1. APROBAR\n2. RECHAZAR\n\n");
                        scanf("%d", &aux);
                        if((aux - 1) != correcto){
                            incorrectos++;
                    // MOSTRAR RAZON POR PANTALLA
                            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
                            printf("                            AMONESTACION\n");
                            printf("                            RAZON: %s\n\n", razon);
                            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
                        }else{
                            correctos++;
                        }
                        if(aux == 1){
                            aprobados++;
                        }else{
                            rechazados++;
                        }
                        printf("PARA DEJAR PASAR AL SIGUIENTE PRESIONA <ENTER>");
                        getch();
                        system("cls");
                        if(puntaje < 0){ //CONDICIONES PERDER
                            printf("Final 6 de 8: Despedido!\n\n\n");
                            dia = 8;
                            finales_o[5] = 1;
                            actualizar_finales_o(finales_o);
                            agregar_puntuacion(puntaje_total);
                            if(((tmi - tm1) / CLOCKS_PER_SEC) < 60){
                                printf("Logro 4 de 8: Speedrun!\n\n\n");
                                dia = 8;
                                finales_o[3] = 1;
                                actualizar_finales_o(finales_o);
                            }
                            if(aprobados_total == 0 && finales_o[0]!=1){
                                printf("Logro 1 de 8: YOU SHALL NOT PASS!\n\n\n");
                                printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                                getch();
                                finales_o[0]=1;
                                actualizar_finales_o(finales_o);
                                system("cls");
                            }
                            if(rechazados_total == 0 && finales_o[1]!=1){
                                printf("Logro 2 de 8: Moises\n\n\n");
                                printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                                getch();
                                finales_o[1]=1;
                                actualizar_finales_o(finales_o);
                                system("cls");
                            }
                            if(correctos_total >= 100 && finales_o[4] != 1){
                                printf("Logro 5 de 8: Sonic\n\n\n");
                                printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                                getch();
                                finales_o[4]=1;
                                actualizar_finales_o(finales_o);
                            }
                        }
                    tm2 = clock();
                    }while(30 > ((tm2 - tm1) / CLOCKS_PER_SEC));
                    puntaje = (correctos*50) - (incorrectos*25);
                    puntaje_total += puntaje;
                    incorrectos_total += incorrectos;
                    correctos_total += correctos_total;
                    aprobados_total += aprobados;
                    rechazados_total += rechazados;
                    printf("PUNTAJE: %d\n", puntaje);                    
                    printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                    getch();
                    system("cls");
                    dia++;
                    guardar_progreso_partida(incorrectos_total,correctos_total, aprobados_total, rechazados_total, puntaje_total, dia);
                }
           //333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
           //333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
           //333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
                if(dia==3){
                    printf("DIA 3:\n");
                    printf("Veo que le agarraste el ritmo, al igual que ayer, hoy habran series de pasaporte restringidas, ");
                    printf("siendo hoy las que poseen una letra <Y>, oh y por cierto argentinos no podran pasar");
                    printf("\n");
                    printf("Buena suerte y VIVA CHILE!\n\n");
                    printf("CUANDO ESTES LISTO PARA COMENZAR PRESIONA <ENTER>\n");
                    getch();
                    system("cls");
                    puntaje = 0, aprobados = 0, rechazados = 0, incorrectos = 0, correctos = 0;
                    tm1 = clock();
                    strcpy(fecha ,"22.06.1586");
                    do{                       
                    //se elige si la persona debera ser aprobada(1) o no(0)
                        correcto = rand() % 2;
                        persona = (pj*)malloc(sizeof(pj));

                    //se elige un numero para elegir los diferentes datos de la persona
                        gen = rand() % 2;
                        if(gen == 1){
                            strcpy(persona->genero, "F");
                            aux = rand()%42;
                            a = searchMap(nombres_m, &aux);
                            strcpy(persona->nombre, a->info);
                        }else if(gen == 0){
                            strcpy(persona->genero, "M");
                            aux = rand()%42;
                            a = searchMap(nombres_h, &aux);
                            strcpy(persona->nombre, a->info);
                        }

                        aux = rand() % 69;
                        a = searchMap(apellidos,&aux);
                        strcpy(persona->apellido, a->info);

                        aux = rand()%4;
                        a = searchMap(motivos, &aux);
                        strcpy(persona->motivo, a->info);
                        
                        aux = rand() % 22;
                        a = searchMap(paises,&aux);
                        strcpy(persona->pais,a->info);

                        aux = rand() % 16;
                        a = searchMap(fechas_b, &aux);
                        strcpy(persona->fecha, a->info);

                        aux = rand() % 29;
                        a = searchMap(series, &aux);
                        strcpy(persona->serie,a->info);

                        if(correcto == 1){
                            aux = rand() % 4;
                            if(aux == 0){
                                aux = rand() % 23;
                                a = searchMap(paisesMal ,&aux);
                                strcpy(razon,"PAIS MAL ESCRITO");
                                strcpy(persona->pais,a->info);
                            }else if(aux == 1){
                                if(gen == 1){
                                    aux = rand() % 43;
                                    a = searchMap(nombres_h, &aux);
                                    strcpy(persona->nombre, a->info);
                                }
                                if(gen == 0){
                                    aux = rand() % 43;
                                    a = searchMap(nombres_m, &aux);
                                    strcpy(persona->nombre, a->info);
                                }
                                strcpy(razon,"GENERO EN PASAPORTE");
                            }else if(aux == 2){
                                aux = rand() % 16;
                                a = searchMap(fechas_m, &aux);
                                strcpy(persona->fecha, a->info);
                                strcpy(razon,"PASAPORTE VENCIDO");
                            }else if(aux == 3){
                                aux = rand() % 14;
                                a = searchMap(s_y, &aux);
                                strcpy(persona->serie, a->info);
                                strcpy(razon,"PASAPORTE RESTRINGIDO");
                            }else if(aux == 4){
                                aux = 22;
                                a = searchMap(paises, &aux);
                                strcpy(persona->pais,a->info);
                                strcpy(razon,"PAIS");
                            }
                        }else{
                            strcpy(razon, "Pasaporte valido");
                        }
                        
                    //printear cuadro
                        printf("Restricciones: Solo pasaportes validos\n");
                        printf("               Pasaportes con letra Y en su serie no podran ser autorizados\n");
                        printf("               No argentinos\n");
                        printf("\n\nFECHA ACTUAL: %s\n\n", fecha);
                        print_pasaporte(persona);
                        printf("<OPCIONES>\n");
                        printf("PRESIONA EL NUMERO CORRESPONDIENTE Y <ENTER>\n");
                        printf("1. APROBAR\n2. RECHAZAR\n\n");
                        scanf("%d", &aux);
                        if((aux - 1) != correcto){
                            incorrectos++;
                    // MOSTRAR RAZON POR PANTALLA
                            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
                            printf("                            AMONESTACION\n");
                            printf("                            RAZON: %s\n\n", razon);
                            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
                        }else{
                            correctos++;
                        }
                        if(aux == 1){
                            aprobados++;
                        }else{
                            rechazados++;
                        }
                        printf("PARA DEJAR PASAR AL SIGUIENTE PRESIONA <ENTER>");
                        getch();
                        system("cls");
                    tm2 = clock();
                    }while(30 > ((tm2 - tm1) / CLOCKS_PER_SEC));
                    puntaje = (correctos*50) - (incorrectos*25);
                    puntaje_total += puntaje;
                    incorrectos_total += incorrectos;
                    correctos_total += correctos_total;
                    aprobados_total += aprobados;
                    rechazados_total += rechazados;
                    printf("PUNTAJE: %d\n", puntaje);
                    if(puntaje < 0){ //CONDICIONES PERDER
                        printf("Final 6 de 8: Despedido!\n\n\n");
                        dia = 8;
                        finales_o[5] = 1;
                        actualizar_finales_o(finales_o);
                        agregar_puntuacion(puntaje_total);
                        if(((tmi - tm1) / CLOCKS_PER_SEC) < 60){
                            printf("Logro 4 de 8: Speedrun!\n\n\n");
                            dia = 8;
                            finales_o[3] = 1;
                            actualizar_finales_o(finales_o);
                        }
                        if(aprobados_total == 0 && finales_o[0]!=1){
                            printf("Logro 1 de 8: YOU SHALL NOT PASS!\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[0]=1;
                            actualizar_finales_o(finales_o);
                            system("cls");
                        }
                        if(rechazados_total == 0 && finales_o[1]!=1){
                            printf("Logro 2 de 8: Moises\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[1]=1;
                            actualizar_finales_o(finales_o);
                            system("cls");
                        }
                        if(correctos_total >= 100 && finales_o[4] != 1){
                            printf("Logro 5 de 8: Sonic\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[4]=1;
                            actualizar_finales_o(finales_o);
                        }
                    }
                    printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                    getch();
                    system("cls");
                    dia++;
                    guardar_progreso_partida(incorrectos_total,correctos_total, aprobados_total, rechazados_total, puntaje_total, dia);
                }
           //444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
           //444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
           //444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
                if(dia == 4){
                    printf("DIA 4:\n");
                    printf("Eres el primero que dura tanto ;), comienzas a hacer que sea dificil odiarte... Buena suerte en lo que queda de semana, la necesitaras. ");
                    printf("Volviendo a lo que nos llama, nos informan que argentinos ni peruanos podran pasar, el motivo es confidencial, solo cumple ordenes, ");
                    printf("ademas series con la letra *M* estan restringidos por hoy y se necesita un ticket de acceso valido por hoy\n");
                    printf("Buena suerte y VIVA CHILE!\n\n");
                    printf("CUANDO ESTES LISTO PARA COMENZAR PRESIONA <ENTER>\n");
                    getch();
                    system("cls");
                    puntaje = 0, aprobados = 0, rechazados = 0, incorrectos = 0, correctos = 0;
                    tm1 = clock();
                    tm2 = clock();
                    strcpy(fecha ,"23.06.1586");
                    do{                        
                    //se elige si la persona debera ser aprobada(1) o no(0)
                        correcto = rand() % 2;
                        persona = (pj*)malloc(sizeof(pj));
                        
                    //se elige un numero para elegir los diferentes datos de la persona
                        gen = rand() % 2;
                        if(gen == 1){
                            strcpy(persona->genero, "F");
                            aux = rand()%42;
                            a = searchMap(nombres_m, &aux);
                            strcpy(persona->nombre, a->info);
                        }else if(gen == 0){
                            strcpy(persona->genero, "M");
                            aux = rand()%42;
                            a = searchMap(nombres_h, &aux);
                            strcpy(persona->nombre, a->info);
                        }

                        strcpy(fecha2 ,"23.06.1586");
                        
                        aux = rand() % 69;
                        a = searchMap(apellidos,&aux);
                        strcpy(persona->apellido, a->info);

                        aux = rand()%4;
                        a = searchMap(motivos, &aux);
                        strcpy(persona->motivo, a->info);
                        
                        aux = rand() % 21;
                        a = searchMap(paises,&aux);
                        strcpy(persona->pais,a->info);

                        aux = rand() % 16;
                        a = searchMap(fechas_b, &aux);
                        strcpy(persona->fecha, a->info);

                        aux = rand() % 29;
                        a = searchMap(series, &aux);
                        strcpy(persona->serie,a->info);

                        if(correcto == 1){
                            aux = rand() % 6;
                            if(aux == 0){
                                aux = rand() % 23;
                                a = searchMap(paisesMal ,&aux);
                                strcpy(razon,"PAIS MAL ESCRITO");
                                strcpy(persona->pais,a->info);
                            }else if(aux == 1){
                                if(gen == 1){
                                    aux = rand() % 43;
                                    a = searchMap(nombres_h, &aux);
                                    strcpy(persona->nombre, a->info);
                                }
                                if(gen == 0){
                                    aux = rand() % 43;
                                    a = searchMap(nombres_m, &aux);
                                    strcpy(persona->nombre, a->info);
                                }
                                strcpy(razon,"GENERO EN PASAPORTE");
                            }else if(aux == 2){
                                aux = rand() % 16;
                                a = searchMap(fechas_m, &aux);
                                strcpy(persona->fecha, a->info);
                                strcpy(razon,"PASAPORTE VENCIDO");
                            }else if(aux == 3){
                                aux = rand() % 14;
                                a = searchMap(s_m, &aux);
                                strcpy(persona->serie, a->info);
                                strcpy(razon,"PASAPORTE RESTRINGIDO");
                            }else if(aux == 4){
                                aux = rand()%2 + 21;
                                a = searchMap(paises, &aux);
                                strcpy(razon,"Pais");
                            }else if(aux == 5){
                                aux = rand()%3;
                                if(aux==0)strcpy(fecha2, "22.06.1586");
                                if(aux==1)strcpy(fecha2, "20.06.1586");
                                if(aux==2)strcpy(fecha2, "19.06.1586");
                                strcpy(razon, "Ticket de acceso");
                            }
                        }else{
                            strcpy(razon, "Pasaporte valido");
                        }
                        
                    //printear cuadro
                        printf("Restricciones: Solo pasaportes validos\n");
                        printf("               Pasaportes con letra M en su serie no podran ser autorizados\n");
                        printf("               No argentinos, ni peruanos\n");
                        printf("               Ticket de acceso valido\n");
                        printf("\n\nFECHA ACTUAL: %s\n\n", fecha);
                        print_pasaporte(persona);

                        printf("////////////////////////////////////////////////////////////////// \n\n");
                        printf("               Ticket de acceso para el dia: %s\n\n", fecha2);
                        printf("////////////////////////////////////////////////////////////////// \n\n\n");

                        printf("<OPCIONES>\n");
                        printf("PRESIONA EL NUMERO CORRESPONDIENTE Y <ENTER>\n");
                        printf("1. APROBAR\n2. RECHAZAR\n\n");
                        scanf("%d", &aux);
                        if((aux - 1) != correcto){
                            incorrectos++;
                    // MOSTRAR RAZON POR PANTALLA
                            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
                            printf("                            AMONESTACION\n");
                            printf("                            RAZON: %s\n\n", razon);
                            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
                        }else{
                            correctos++;
                        }
                        if(aux == 1){
                            aprobados++;
                        }else{
                            rechazados++;
                        }
                        printf("PARA DEJAR PASAR AL SIGUIENTE PRESIONA <ENTER>");
                        getch();
                        system("cls");
                    tm2 = clock();
                    }while(30 > ((tm2 - tm1) / CLOCKS_PER_SEC));
                    puntaje = (correctos*50) - (incorrectos*25);
                    puntaje_total += puntaje;
                    incorrectos_total += incorrectos;
                    correctos_total += correctos_total;
                    aprobados_total += aprobados;
                    rechazados_total += rechazados;
                    printf("PUNTAJE: %d\n", puntaje);
                    if(puntaje < 0){ //CONDICIONES PERDER
                        printf("Final 6 de 8: Despedido!\n\n\n");
                        dia = 8;
                        finales_o[5] = 1;
                        actualizar_finales_o(finales_o);
                        agregar_puntuacion(puntaje_total);
                        if(((tmi - tm1) / CLOCKS_PER_SEC) < 60){
                            printf("Logro 4 de 8: Speedrun!\n\n\n");
                            dia = 8;
                            finales_o[3] = 1;
                            actualizar_finales_o(finales_o);
                        }
                        if(aprobados_total == 0 && finales_o[0]!=1){
                            printf("Logro 1 de 8: YOU SHALL NOT PASS!\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[0]=1;
                            actualizar_finales_o(finales_o);
                            system("cls");
                        }
                        if(rechazados_total == 0 && finales_o[1]!=1){
                            printf("Logro 2 de 8: Moises\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[1]=1;
                            actualizar_finales_o(finales_o);
                            system("cls");
                        }
                        if(correctos_total >= 100 && finales_o[4] != 1){
                            printf("Logro 5 de 8: Sonic\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[4]=1;
                            actualizar_finales_o(finales_o);
                        }
                    }
                    printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                    getch();
                    system("cls");
                    dia++;
                    guardar_progreso_partida(incorrectos_total,correctos_total, aprobados_total, rechazados_total, puntaje_total, dia);
                }
            //5555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555
            //5555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555
            //5555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555           
                if(dia==5){
                    printf("DIA 5:\n");
                    printf("Tengo prisa, asi que, en resumen los jefes dicen que solo residentes de CHILE, ECUADOR, PARAGUAY, NICARAGUA y URUGUAY podran pasar,");
                    printf(" el motivo sigue siendo confidencial, solo obedece, ademas series con la letra *A* estan restringidos por hoy");
                    printf(", no olvides los tickets de acceso y por cierto, quienes vienen por trabajo tampoco pueden pasar");
                    printf("\n");
                    printf("Buena suerte y VIVA CHILE!\n\n");
                    printf("CUANDO ESTES LISTO PARA COMENZAR PRESIONA <ENTER>\n");
                    getch();
                    system("cls");
                    puntaje = 0, aprobados = 0, rechazados = 0, incorrectos = 0, correctos = 0;
                    tm1 = clock();
                    tm2 = clock();
                    strcpy(fecha ,"24.06.1586");
                    do{                        
                    //se elige si la persona debera ser aprobada(1) o no(0)
                        correcto = rand() % 2;
                        persona = (pj*)malloc(sizeof(pj));
                        
                    //se elige un numero para elegir los diferentes datos de la persona
                        gen = rand() % 2;
                        if(gen == 1){
                            strcpy(persona->genero, "F");
                            aux = rand()%42;
                            a = searchMap(nombres_m, &aux);
                            strcpy(persona->nombre, a->info);
                        }else if(gen == 0){
                            strcpy(persona->genero, "M");
                            aux = rand()%42;
                            a = searchMap(nombres_h, &aux);
                            strcpy(persona->nombre, a->info);
                        }

                        strcpy(fecha2 ,"24.06.1586");

                        aux = rand() % 69;
                        a = searchMap(apellidos,&aux);
                        strcpy(persona->apellido, a->info);
                        do{
                            aux = rand()%4;
                        }while(aux ==1);
                        
                        a = searchMap(motivos, &aux);
                        strcpy(persona->motivo, a->info);
                        
                        aux = rand() % 5;
                        a = searchMap(paises,&aux);
                        strcpy(persona->pais,a->info);

                        aux = rand() % 16;
                        a = searchMap(fechas_b, &aux);
                        strcpy(persona->fecha, a->info);

                        aux = rand() % 29;
                        a = searchMap(series, &aux);
                        strcpy(persona->serie,a->info);

                        if(correcto == 1){
                            aux = rand() % 7;
                            if(aux == 0){
                                aux = rand() % 23;
                                a = searchMap(paisesMal ,&aux);
                                strcpy(razon,"PAIS MAL ESCRITO");
                                strcpy(persona->pais,a->info);
                            }else if(aux == 1){
                                if(gen == 1){
                                    aux = rand() % 43;
                                    a = searchMap(nombres_h, &aux);
                                    strcpy(persona->nombre, a->info);
                                }
                                if(gen == 0){
                                    aux = rand() % 43;
                                    a = searchMap(nombres_m, &aux);
                                    strcpy(persona->nombre, a->info);
                                }
                                strcpy(razon,"GENERO EN PASAPORTE");
                            }else if(aux == 2){
                                aux = rand() % 16;
                                a = searchMap(fechas_m, &aux);
                                strcpy(persona->fecha, a->info);
                                strcpy(razon,"PASAPORTE VENCIDO");
                            }else if(aux == 3){
                                aux = rand() % 14;
                                a = searchMap(s_a, &aux);
                                strcpy(persona->serie, a->info);
                                strcpy(razon,"PASAPORTE RESTRINGIDO");
                            }else if(aux == 4){
                                aux = rand() % 18;
                                aux = aux + 5;
                                a = searchMap(paises, &aux);
                                strcpy(razon,"Pais restringido");
                            }else if(aux == 5){
                                aux = rand()%3;
                                if(aux==0)strcpy(fecha2, "25.06.1586");
                                if(aux==1)strcpy(fecha2, "20.06.1586");
                                if(aux==2)strcpy(fecha2, "19.06.1586");
                                strcpy(razon,"Ticket de acceso");
                            }else if(aux == 6){
                                strcpy(persona->motivo, "Trabajo");
                                strcpy(razon,"Motivo");
                            }
                
                        }else{
                            strcpy(razon,"PASAPORTE CORRECTO");
                        }
                        
                    //printear cuadro
                        printf("Restricciones: Solo pasaportes validos\n");
                        printf("               Pasaportes con letra A en su serie no podran ser autorizados\n");
                        printf("               No argentinos ni peruanos\n");
                        printf("               Ticket de acceso valido\n");
                        printf("               Quienes vienen por trabajo no pueden pasar\n");
                        printf("\n\nFECHA ACTUAL: %s\n\n", fecha);
                        print_pasaporte(persona);
                        printf("////////////////////////////////////////////////////////////////// \n\n");
                        printf("               Ticket de acceso para el dia: %s\n\n", fecha2);
                        printf("////////////////////////////////////////////////////////////////// \n\n\n");

                        printf("<OPCIONES>\n");
                        printf("PRESIONA EL NUMERO CORRESPONDIENTE Y <ENTER>\n");
                        printf("1. APROBAR\n2. RECHAZAR\n\n");
                        scanf("%d", &aux);
                        if((aux - 1) != correcto){
                            incorrectos++;
                    // MOSTRAR RAZON POR PANTALLA
                            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
                            printf("                            AMONESTACION\n");
                            printf("                            RAZON: %s\n\n", razon);
                            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
                        }else{
                            correctos++;
                        }
                        if(aux == 1){
                            aprobados++;
                        }else{
                            rechazados++;
                        }
                        printf("PARA DEJAR PASAR AL SIGUIENTE PRESIONA <ENTER>");
                        getch();
                        system("cls");
                    tm2 = clock();
                    }while(30 > ((tm2 - tm1) / CLOCKS_PER_SEC));
                    puntaje = (correctos*50) - (incorrectos*25);
                    puntaje_total += puntaje;
                    incorrectos_total += incorrectos;
                    correctos_total += correctos_total;
                    aprobados_total += aprobados;
                    rechazados_total += rechazados;
                    printf("PUNTAJE: %d\n", puntaje);
                    if(puntaje < 0){ //CONDICIONES PERDER
                        printf("Final 6 de 8: Despedido!\n\n\n");
                        dia = 8;
                        finales_o[5] = 1;
                        actualizar_finales_o(finales_o);
                        agregar_puntuacion(puntaje_total);
                        if(((tmi - tm1) / CLOCKS_PER_SEC) < 60){
                            printf("Logro 4 de 8: Speedrun!\n\n\n");
                            dia = 8;
                            finales_o[3] = 1;
                            actualizar_finales_o(finales_o);
                        }
                        if(aprobados_total == 0 && finales_o[0]!=1){
                            printf("Logro 1 de 8: YOU SHALL NOT PASS!\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[0]=1;
                            actualizar_finales_o(finales_o);
                            system("cls");
                        }
                        if(rechazados_total == 0 && finales_o[1]!=1){
                            printf("Logro 2 de 8: Moises\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[1]=1;
                            actualizar_finales_o(finales_o);
                            system("cls");
                        }
                        if(correctos_total >= 100 && finales_o[4] != 1){
                            printf("Logro 5 de 8: Sonic\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[4]=1;
                            actualizar_finales_o(finales_o);
                        }
                    }
                    printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                    getch();
                    system("cls");
                    dia++;
                    guardar_progreso_partida(incorrectos_total,correctos_total, aprobados_total, rechazados_total, puntaje_total, dia);
                }
           //66666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666
           //66666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666
           //66666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666
                if(dia==6){
                    printf("DIA 6:\n");
                    printf("Wow, me impresiona que sigues aqui... esto ya es raro...\n Pero bueno, llendo al grano\n");
                    printf("Hoy solo residentes de CHILE, ECUADOR, PARAGUAY, NICARAGUA, URUGUAY, COLOMBIA, MEXICO, EEUU, COSTA RICA ");
                    printf("y BRASIL pueden entrar.");
                    printf(" El motivo sigue siendo confidencial, solo espero que no estemos en guerra o algo asi...\n Dejando el tema de lado, los pasaportes con series con la letra *T* estan restringidos por hoy");
                    printf(", recuerda los tickets de acceso y hoy no podran pasar turistas");
                    printf("\n");
                    printf("Buena suerte y VIVA CHILE!\n\n");
                    printf("CUANDO ESTES LISTO PARA COMENZAR PRESIONA <ENTER>\n");
                    getch();
                    system("cls");
                    puntaje = 0, aprobados = 0, rechazados = 0, incorrectos = 0, correctos = 0;
                    tm1 = clock();
                    tm2 = clock();
                    strcpy(fecha ,"25.06.1586");
                    do{                        
                    //se elige si la persona debera ser aprobada(1) o no(0)
                        correcto = rand() % 2;
                        persona = (pj*)malloc(sizeof(pj));
                        
                    //se elige un numero para elegir los diferentes datos de la persona
                        gen = rand() % 2;
                        if(gen == 1){
                            strcpy(persona->genero, "F");
                            aux = rand()%42;
                            a = searchMap(nombres_m, &aux);
                            strcpy(persona->nombre, a->info);
                        }else if(gen == 0){
                            strcpy(persona->genero, "M");
                            aux = rand()%42;
                            a = searchMap(nombres_h, &aux);
                            strcpy(persona->nombre, a->info);
                        }

                        strcpy(fecha2 ,"25.06.1586");

                        aux = rand() % 69;
                        a = searchMap(apellidos,&aux);
                        strcpy(persona->apellido, a->info);

                        do{
                            aux = rand()%4;
                        }while(aux == 0);
                        a = searchMap(motivos, &aux);
                        strcpy(persona->motivo, a->info);
                        
                        aux = rand() % 10;
                        a = searchMap(paises,&aux);
                        strcpy(persona->pais,a->info);

                        aux = rand() % 16;
                        a = searchMap(fechas_b, &aux);
                        strcpy(persona->fecha, a->info);

                        aux = rand() % 29;
                        a = searchMap(series, &aux);
                        strcpy(persona->serie,a->info);

                        if(correcto == 1){
                            aux = rand() % 7;
                            if(aux == 0){
                                aux = rand() % 23;
                                a = searchMap(paisesMal ,&aux);
                                strcpy(razon,"PAIS MAL ESCRITO");
                                strcpy(persona->pais,a->info);
                            }else if(aux == 1){
                                if(gen == 1){
                                    aux = rand() % 43;
                                    a = searchMap(nombres_h, &aux);
                                    strcpy(persona->nombre, a->info);
                                }
                                if(gen == 0){
                                    aux = rand() % 43;
                                    a = searchMap(nombres_m, &aux);
                                    strcpy(persona->nombre, a->info);
                                }
                                strcpy(razon,"GENERO EN PASAPORTE");
                            }else if(aux == 2){
                                aux = rand() % 16;
                                a = searchMap(fechas_m, &aux);
                                strcpy(persona->fecha, a->info);
                                strcpy(razon,"PASAPORTE VENCIDO");
                            }else if(aux == 3){
                                aux = rand() % 14;
                                a = searchMap(s_t, &aux);
                                strcpy(persona->serie, a->info);
                                strcpy(razon,"PASAPORTE RESTRINGIDO");
                            }else if(aux == 4){
                                aux = rand() % 13;
                                aux = aux + 10;
                                a = searchMap(paises, &aux);
                                strcpy(razon,"Pais restringido");
                            }else if(aux == 5){
                                aux = rand()%3;
                                if(aux==0)strcpy(fecha2, "24.06.1586");
                                if(aux==1)strcpy(fecha2, "20.06.1586");
                                if(aux==2)strcpy(fecha2, "15.06.1586");
                                strcpy(razon,"Ticket de acceso");
                            }else if(aux == 6){
                                strcpy(persona->motivo, "Turismo");
                                strcpy(razon,"Motivo");
                            }
                        }else{
                            strcpy(razon,"PASAPORTE CORRECTO");
                        }
                        
                    //printear cuadro
                        printf("Restricciones: Solo pasaportes validos\n");
                        printf("               Pasaportes con letra T en su serie no podran ser autorizados\n");
                        printf("               Ticket de acceso valido\n");
                        printf("               Solo residentes de CHILE, ECUADOR, PARAGUAY, NICARAGUA, URUGUAY, COLOMBIA, MEXICO, EEUU, COSTA RICA y BRASIL\n");
                        printf("               No turistas\n");
                        printf("\n\nFECHA ACTUAL: %s\n\n", fecha);
                        print_pasaporte(persona);
                        printf("////////////////////////////////////////////////////////////////// \n\n");
                        printf("               Ticket de acceso para el dia: %s\n\n", fecha2);
                        printf("////////////////////////////////////////////////////////////////// \n\n\n");

                        printf("<OPCIONES>\n");
                        printf("PRESIONA EL NUMERO CORRESPONDIENTE Y <ENTER>\n");
                        printf("1. APROBAR\n2. RECHAZAR\n\n");
                        scanf("%d", &aux);
                        if((aux - 1) != correcto){
                            incorrectos++;
                    // MOSTRAR RAZON POR PANTALLA
                            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
                            printf("                            AMONESTACION\n");
                            printf("                            RAZON: %s\n\n", razon);
                            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
                        }else{
                            correctos++;
                        }
                        if(aux == 1){
                            aprobados++;
                        }else{
                            rechazados++;
                        }
                        printf("PARA DEJAR PASAR AL SIGUIENTE PRESIONA <ENTER>");
                        getch();
                        system("cls");
                    tm2 = clock();
                    }while(30 > ((tm2 - tm1) / CLOCKS_PER_SEC));
                    puntaje = (correctos*50) - (incorrectos*25);
                    puntaje_total += puntaje;
                    incorrectos_total += incorrectos;
                    correctos_total += correctos_total;
                    aprobados_total += aprobados;
                    rechazados_total += rechazados;
                    printf("PUNTAJE: %d\n", puntaje);
                    if(puntaje < 0){ //CONDICIONES PERDER
                        printf("Final 6 de 8: Despedido!\n\n\n");
                        dia = 8;
                        finales_o[5] = 1;
                        actualizar_finales_o(finales_o);
                        agregar_puntuacion(puntaje_total);
                        if(((tmi - tm1) / CLOCKS_PER_SEC) < 60){
                            printf("Logro 4 de 8: Speedrun!\n\n\n");
                            dia = 8;
                            finales_o[3] = 1;
                            actualizar_finales_o(finales_o);
                        }
                        if(aprobados_total == 0 && finales_o[0]!=1){
                            printf("Logro 1 de 8: YOU SHALL NOT PASS!\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[0]=1;
                            actualizar_finales_o(finales_o);
                            system("cls");
                        }
                        if(rechazados_total == 0 && finales_o[1]!=1){
                            printf("Logro 2 de 8: Moises\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[1]=1;
                            actualizar_finales_o(finales_o);
                            system("cls");
                        }
                        if(correctos_total >= 100 && finales_o[4] != 1){
                            printf("Logro 5 de 8: Sonic\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[4]=1;
                            actualizar_finales_o(finales_o);
                        }
                    }
                    printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                    getch();
                    system("cls");
                    dia++;
                    guardar_progreso_partida(incorrectos_total,correctos_total, aprobados_total, rechazados_total, puntaje_total, dia);
                }
            //7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
            //7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
            //7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
                if(dia==7){
                    printf("DIA 7:\n");
                    printf("Ya llegaste bastante lejos, asi que creo que debo decirte lo que esta pasando...\n");
                    printf("Hoy me entere de que nuestro jefe esta loco, ha estado cambiando las reglas como si fuera un juego maniaco para que nos despidan, ");
                    printf("pero hoy... es distinto... veras, si cometemos el mas minimo error... nos matara tot\n");
                    printf("Asi que ten mucho cuidado y... pase lo que pase... quiero que sepas que te quiero <NOMBRE JUGADOR>\n");
                    printf("*EJEM* Nos informan que solo residentes de CHILE, ECUADOR, PARAGUAY, NICARAGUA, URUGUAY, COLOMBIA, MEXICO, EEUU, COSTA RICA ");
                    printf(", BRASIL, FILIPINAS, INDIA, EGIPTO, FRANCIA e INGLATERRA podran pasar");
                    printf(" ademas series con la letra *Z* estan restringidos por hoy");
                    printf(", recuerda los tickets de acceso y que hoy no podran pasar turistas");
                    printf("\n");
                    printf("Buena suerte y QUE DIOS TE BENDIGA!\n\n");
                    printf("*se aleja con paso cansado*  *se escucha un disparo*\n\n");
                    printf("CUANDO ESTES LISTO PARA COMENZAR PRESIONA <ENTER>\n");
                    getch();
                    system("cls");
                    puntaje = 0, aprobados = 0, rechazados = 0, incorrectos = 0, correctos = 0;
                    tm1 = clock();
                    tm2 = clock();
                    strcpy(fecha ,"26.06.1586");
                    do{                        
                    //se elige si la persona debera ser aprobada(1) o no(0)
                        correcto = rand() % 2;
                        persona = (pj*)malloc(sizeof(pj));
                        
                    //se elige un numero para elegir los diferentes datos de la persona
                        gen = rand() % 2;
                        if(gen == 1){
                            strcpy(persona->genero, "F");
                            aux = rand()%42;
                            a = searchMap(nombres_m, &aux);
                            strcpy(persona->nombre, a->info);
                        }else if(gen == 0){
                            strcpy(persona->genero, "M");
                            aux = rand()%42;
                            a = searchMap(nombres_h, &aux);
                            strcpy(persona->nombre, a->info);
                        }

                        strcpy(fecha2 ,"26.06.1586");

                        aux = rand() % 69;
                        a = searchMap(apellidos,&aux);
                        strcpy(persona->apellido, a->info);

                        do{
                            aux = rand()%4;
                        }while(aux == 0);
                        a = searchMap(motivos, &aux);
                        strcpy(persona->motivo, a->info);
                        
                        aux = rand() % 15;
                        a = searchMap(paises,&aux);
                        strcpy(persona->pais,a->info);

                        aux = rand() % 16;
                        a = searchMap(fechas_b, &aux);
                        strcpy(persona->fecha, a->info);

                        aux = rand() % 29;
                        a = searchMap(series, &aux);
                        strcpy(persona->serie,a->info);

                        if(correcto == 1){
                            aux = rand() % 7;
                            if(aux == 0){
                                aux = rand() % 23;
                                a = searchMap(paisesMal ,&aux);
                                strcpy(razon,"PAIS MAL ESCRITO");
                                strcpy(persona->pais,a->info);
                            }else if(aux == 1){
                                if(gen == 1){
                                    aux = rand() % 43;
                                    a = searchMap(nombres_h, &aux);
                                    strcpy(persona->nombre, a->info);
                                }
                                if(gen == 0){
                                    aux = rand() % 43;
                                    a = searchMap(nombres_m, &aux);
                                    strcpy(persona->nombre, a->info);
                                }
                                strcpy(razon,"GENERO EN PASAPORTE");
                            }else if(aux == 2){
                                aux = rand() % 16;
                                a = searchMap(fechas_m, &aux);
                                strcpy(persona->fecha, a->info);
                                strcpy(razon,"PASAPORTE VENCIDO");
                            }else if(aux == 3){
                                aux = rand() % 14;
                                a = searchMap(s_z, &aux);
                                strcpy(persona->serie, a->info);
                                strcpy(razon,"PASAPORTE RESTRINGIDO");
                            }else if(aux == 4){
                                aux = rand() % 8;
                                aux = aux + 15;
                                a = searchMap(paises, &aux);
                                strcpy(razon,"Pais restringido");
                            }else if(aux == 5){
                                aux = rand()%3;
                                if(aux==0)strcpy(fecha2, "24.06.1586");
                                if(aux==1)strcpy(fecha2, "20.06.1586");
                                if(aux==2)strcpy(fecha2, "15.06.1586");
                                strcpy(razon,"Ticket de acceso");
                            }else if(aux == 6){
                                strcpy(persona->motivo, "Turismo");
                                strcpy(razon,"Motivo");
                            }
                        }else{
                            strcpy(razon,"PASAPORTE CORRECTO");
                        }
                        
                    //printear cuadro
                        printf("Restricciones: Solo pasaportes validos\n");
                        printf("               Pasaportes con letra Z en su serie no podran ser autorizados\n");
                        printf("               Ticket de acceso valido\n");
                        printf("               Solo residentes de CHILE, ECUADOR, PARAGUAY, NICARAGUA, URUGUAY, COLOMBIA, MEXICO, EEUU, COSTA RICA, BRASIL, FILIPINAS, INDIA, EGIPTO, FRANCIA E INGLATERRA\n");
                        printf("               No turistas\n");
                        printf("\n\nFECHA ACTUAL: %s\n\n", fecha);
                        print_pasaporte(persona);
                        printf("////////////////////////////////////////////////////////////////// \n\n");
                        printf("               Ticket de acceso para el dia: %s\n\n", fecha2);
                        printf("////////////////////////////////////////////////////////////////// \n\n\n");

                        printf("<OPCIONES>\n");
                        printf("PRESIONA EL NUMERO CORRESPONDIENTE Y <ENTER>\n");
                        printf("1. APROBAR\n2. RECHAZAR\n\n");
                        scanf("%d", &aux);
                        if((aux - 1) != correcto){
                            incorrectos++;
                    // MOSTRAR RAZON POR PANTALLA
                            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
                            printf("                            AMONESTACION\n");
                            printf("                            RAZON: %s\n\n", razon);
                            printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n");
                    //FINAL    
                        }else{
                            correctos++;
                        }
                        if(aux == 1){
                            aprobados++;
                        }else{
                            rechazados++;
                        }
                        if(incorrectos==1){
                            printf("Oh no... *PIUM PIUM*\n\n\n");
                            printf("Final 8 de 8: Fusilado\n\n\n");
                            dia = 8;
                            finales_o[7] = 1;
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            system("cls");
                            actualizar_finales_o(finales_o);
                            agregar_puntuacion(puntaje_total);
                        }
                        printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                        getch();
                        system("cls");
                    tm2 = clock();
                    }while(30 > ((tm2 - tm1) / CLOCKS_PER_SEC));
                    puntaje = (correctos*50) - (incorrectos*25);
                    puntaje_total += puntaje;
                    incorrectos_total += incorrectos;
                    correctos_total += correctos_total;
                    aprobados_total += aprobados;
                    rechazados_total += rechazados;
                    printf("PUNTAJE: %d\n", puntaje);
                    if(incorrectos == 0){
                        printf("Te salvas por hoy... *RISA MALIGNA*\n\n\n");
                        printf("Final 7 de 8: Viva Chile!\n\n\n");
                        printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                        getch();
                        dia = 8;
                        finales_o[6] = 1;
                        system("cls");
                        actualizar_finales_o(finales_o);
                        agregar_puntuacion(puntaje_total);
                        if(incorrectos_total == 0){
                            printf("Logro 3 de 8: Robot\n\n\n");
                            printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                            getch();
                            finales_o[2]=1;
                            actualizar_finales_o(finales_o);
                            system("cls");
                        }
                    }
                    if(aprobados_total == 0 && finales_o[0]!=1){
                        printf("Logro 1 de 8: YOU SHALL NOT PASS!\n\n\n");
                        printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                        getch();
                        finales_o[0]=1;
                        actualizar_finales_o(finales_o);
                        system("cls");
                    }
                    if(rechazados_total == 0 && finales_o[1]!=1){
                        printf("Logro 2 de 8: Moises\n\n\n");
                        printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                        getch();
                        finales_o[1]=1;
                        actualizar_finales_o(finales_o);
                        system("cls");
                    }
                    if(correctos_total >= 100 && finales_o[4] != 1){
                        printf("Logro 5 de 8: Sonic\n\n\n");
                        printf("PRESIONA <ENTER> PARA CONTINUAR\n");
                        getch();
                        finales_o[4]=1;
                        actualizar_finales_o(finales_o);
                    }
                    dia++;
                    guardar_progreso_partida(incorrectos_total,correctos_total, aprobados_total, rechazados_total, puntaje_total, dia);
                }
            opcion = 0;
            break;
    //Caso 2: Tabla de puntajes 
        case 2:
            tabla_punt = createMap(is_equal_int);
            strcpy(archivo, "partidas_terminadas.txt");
            leer_punt(tabla_punt, archivo);
    //Se obtiene el primer elemento del mapa de puntajes para ver si hay elementos o no y determinar que se va a mostrar por pantalla
            a = firstMap(tabla_punt);
            if (a==NULL){
                printf("No hay puntajes para mostrar :c\n");
            }else{
                printf("Usuario | Puntaje\n");
                while(a!=NULL){
                    printf("%s      %d\n", a->info, a->key);
                    a = nextMap(tabla_punt);
                }
            }
            tabla_punt = NULL;
            opcion = 0;
            break;
       //Caso 3: Mostrar finales obtenidos 
        case 3:
            system("cls");
            for(int i = 0; i<8;i++){
                if(finales_o[i] == 1) cont_finales++;
            }
            a = firstMap(finales);
            if (cont_finales==0){
                printf("No has obtenido ningun final/logro para mostrar :c\n\n");
                opcion = 0;
                break;
            }else{
                printf("====================================================================\n");
                printf("| Nombre                    | Metodo de obtencion                  |\n");
                printf("====================================================================\n\n");
                while(a!=NULL){
                    if(finales_o[a->key]==1){
                        printf("%s\n", a->info);
                    }
                    a = nextMap(finales);
                }
            }
            opcion = 0;
            break;
       //Caso 4: Salir de la aplicacion
        case 4:
            break;
        default:
            printf("====================================================\n");
            printf("|    Papers, please - Copiado por Calce-Team ;)    |\n");
            printf("====================================================\n\n"); 
            printf("1.- Jugar\n2.- Tabla de puntajes\n");
            printf("3.- Finales y logros obtenidos\n4.- Salir");
            printf("\n\n ~Seleccione una opcion, ingrese un <NUMERO>: ");
            scanf("%d", &opcion);
            printf("\n\n");
            break;
            }
        }    
    }
}