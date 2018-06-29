/**************************** INCLUSION DE EMPTYRIAS PERSONALES **********************************/
#include "General.h"
#include "Menu.h"
#include "ArrayList.h"
#include "Alumno.h"


/**************************** INCLUSION DE EMPTYRIAS ESTANDAR ************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int returnAux = CHECK_POINTER;
   eMenu menuPrincipal = {/*titulo del menu*/{"PARCIAL 2, MODELO 2"},
                          /*cantidad de opciones*/3,
                          /*codigos*/{1,2,
                                      0},
                          /*descripciones*/"\n  1. CREAR ARCHIVO ALUMNOS.CSV"
                                           "\n  2. LISTAR ORDENADO POR EDAD"
                                           "\n  0. SALIR DEL PROGRAMA"};
    int opcion;
    char salirDelPrograma = 'N';

    //ARRAYS DE ESTRUCTURAS
    ArrayList* alumnos = al_newArrayList();

    if(alumnos == NULL)
    {
        printf("No pudieron inicializarse los listados");
        salirDelPrograma = 'S';
    }

    while(salirDelPrograma == 'N')
    {
        limpiarPantalla();
        opcion = eMenu_pedirOpcion(&menuPrincipal);
        switch(opcion)
        {
            case 1:
                eAlumno_gestionCrearArchivo(alumnos);
                break;
            case 2:
                eAlumno_gestionListar(alumnos);
                break;
            case 3:

                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:

                break;
            case 9:

                break;
            case 10:

                break;
            case 11:

                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                returnAux = OK;
                break;
        }

    }
    return returnAux;
}
