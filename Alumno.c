/**************************** INCLUSION DE EMPTYRIAS PERSONALES **********************************/
#include "ArrayList.h"
#include "Alumno.h"
#include "Menu.h"
/**************************** INCLUSION DE EMPTYRIAS ESTANDAR ************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**************************** GET ****************************************************************/
int eAlumno_getLegajo(eAlumno* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = this->legajo;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAlumno_getEdad(eAlumno* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = this->edad;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char eAlumno_getSexo(eAlumno* this)
{
    char returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = this->sexo;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* eAlumno_getNombre(eAlumno* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = this->nombre;
    }
    return returnAux;
}
/**************************** SET ****************************************************************/
int eAlumno_setLegajo(eAlumno* this, int legajo)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = OK;
        this->legajo = legajo;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAlumno_setEdad(eAlumno* this, int edad)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = OK;
        this->edad = edad;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAlumno_setSexo(eAlumno* this, char sexo)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = OK;
        this->sexo = sexo;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAlumno_setNombre(eAlumno* this, char* nombre)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = OK;
        strcpy(this->nombre, nombre);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

/**************************** CONSTRUCTORES ******************************************************/
eAlumno* eAlumno_new(void)
{
   eAlumno* newAlumno;

   newAlumno = (eAlumno*)malloc(sizeof(eAlumno));
   if(newAlumno != NULL)
   {
      newAlumno->print            = eAlumno_printOne;

       //getters
      newAlumno->getNombre          = eAlumno_getNombre;
      newAlumno->getEdad           = eAlumno_getEdad;
      newAlumno->getLegajo            = eAlumno_getLegajo;
      newAlumno->getSexo         = eAlumno_getSexo;

       //setters
      newAlumno->setNombre          = eAlumno_setNombre;
      newAlumno->setEdad           = eAlumno_setEdad;
      newAlumno->setLegajo            = eAlumno_setLegajo;
      newAlumno->setSexo         = eAlumno_setSexo;
   }

   return newAlumno;
}
//-----------------------------------------------------------------------------------------------//
eAlumno* eAlumno_newParam(char* nombre,
                          int edad,
                          int legajo,
                          char sexo)
{
    eAlumno* newAlumno;

    newAlumno = eAlumno_new();

    if(newAlumno != NULL)
   {
      newAlumno->setNombre(newAlumno, nombre);
      newAlumno->setEdad(newAlumno, edad);
      newAlumno->setLegajo(newAlumno, legajo);
      newAlumno->setSexo(newAlumno, sexo);
   }

    return newAlumno;
}
//-----------------------------------------------------------------------------------------------//


/**************************** ENTRADA DE DATOS ***************************************************/
//int eAlumno_askLegajo()
//{
//   return pedirIntValido(ALUMNO_MSJ_INGRESE_ID, ALUMNO_MSJ_REINGRESE_ID, ALUMNO_ID_MIN, ALUMNO_ID_MAX);
//}
////-----------------------------------------------------------------------------------------------//
//int eAlumno_askEdad()
//{
//   return pedirIntValido(ALUMNO_MSJ_INGRESE_EDAD, ALUMNO_MSJ_REINGRESE_EDAD, ALUMNO_EDAD_MIN, ALUMNO_EDAD_MAX);
//}
////-----------------------------------------------------------------------------------------------//
//int eAlumno_askSexo()
//{
//   return pedirIntValido(ALUMNO_MSJ_INGRESE_STATS, ALUMNO_MSJ_REINGRESE_STATS, ALUMNO_STATS_MIN, ALUMNO_STATS_MAX);
//}
////-----------------------------------------------------------------------------------------------//
//char* eAlumno_askNombre()
//{
//   char* returnAux = (char*)malloc(sizeof(char)*ALUMNO_LENGTH_NAME);
//
//   pedirStringValido(returnAux, ALUMNO_MSJ_INGRESE_NAME, ALUMNO_MSJ_REINGRESE_NAME, ALUMNO_LENGTH_NAME);
//
//   return returnAux;
//}
////-----------------------------------------------------------------------------------------------//
//char* eAlumno_askLastNombre()
//{
//   char* returnAux = (char*)malloc(sizeof(char)*ALUMNO_LENGTH_LAST_NAME);
//
//   pedirStringValido(returnAux, ALUMNO_MSJ_INGRESE_LAST_NAME, ALUMNO_MSJ_REINGRESE_LAST_NAME, ALUMNO_LENGTH_LAST_NAME);
//
//   return returnAux;
//}
////-----------------------------------------------------------------------------------------------//
//eAlumno* eAlumno_askInput()
//{
//   eAlumno* newAlumno;
//
//   newAlumno = eAlumno_newParam(eAlumno_askNombre(),
//                                eAlumno_askEdad(),
//                                eAlumno_askLegajo(),
//                                eAlumno_askSexo());
//
//   return newAlumno;
//}
//-----------------------------------------------------------------------------------------------//


/**************************** INICIALIZACIONES ***************************************************/
//hardcodeo


/**************************** BUSQUEDA ***********************************************************/
int eAlumno_listIsEmpty(ArrayList* this)
{
   int returnAux = CHECK_POINTER;

   if(this != NULL)
   {
      returnAux = this->isEmpty(this);
   }
   return returnAux;
}

//-----------------------------------------------------------------------------------------------//
int eAlumno_listIsEmptyLegend(ArrayList* this)
{
   int returnAux = CHECK_POINTER;

   if(this != NULL)
   {
      returnAux = eAlumno_listIsEmpty(this);

      if(returnAux)
      {
         imprimirEnPantalla(ALUMNO_MSJ_EMPTY_LIST);
      }
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
eAlumno* eAlumno_getByLegajo(ArrayList* this, int legajo)
{
   eAlumno* oneAlumno;
   eAlumno* returnAlumno = NULL;

   for(int i=0; i<this->len(this) ; i++)
   {
      oneAlumno = this->get(this, i);

      if(oneAlumno->getLegajo(oneAlumno) == legajo)
      {
         returnAlumno = oneAlumno;
         break;
      }
   }
   return returnAlumno;
}
//-----------------------------------------------------------------------------------------------//
eAlumno* eAlumno_getByEdad(ArrayList* this, int edad)
{
   eAlumno* oneAlumno;
   eAlumno* returnAlumno = NULL;

   for(int i=0; i<this->len(this) ; i++)
   {
      oneAlumno = this->get(this, i);

      if(oneAlumno->getEdad(oneAlumno) == edad)
      {
         returnAlumno = oneAlumno;
         break;
      }
   }
   return returnAlumno;
}
//-----------------------------------------------------------------------------------------------//



/**************************** LISTADO DE DATOS ***************************************************/
int eAlumno_printOne(void* this, char* mascara)
{

   int returnAux = CHECK_POINTER;

   if(this != NULL)
   {
      returnAux = OK;
      printf(mascara,
            ((eAlumno*)this)->getNombre(this),
            ((eAlumno*)this)->getEdad(this),
            ((eAlumno*)this)->getLegajo(this),
            ((eAlumno*)this)->getSexo(this));
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//

/**************************** CARGAR ARCHIVO *****************************************************/
#define ALUMNO_MASCARA_ARCHIVO "%[^,],%[^,],%[^,],%[^\n]\n"
#define CAMPOS_A_LEER 4

int eAlumno_gestionCrearArchivo(ArrayList* this)
{
   int returnAux = CHECK_POINTER;
   eAlumno* registros[10];
   eAlumno* pAlumno;
   char nombre[50];
   char edad[50];
   char legajo[50];
   char sexo[50];
   int cantCamposLeidos;
   int huboErrorAddRegistro;
   int leidosOk = 0;
   int leidosError = 0;
   FILE* pFile;
   char* ruta = "alumnos.csv";

   registros[0] = eAlumno_newParam("Ana"  ,20,111,'F');
   registros[1] = eAlumno_newParam("Beto" ,21,112,'M');
   registros[2] = eAlumno_newParam("Jose" ,30,133,'M');
   registros[3] = eAlumno_newParam("Pipo" ,25,124,'M');
   registros[4] = eAlumno_newParam("Mary" ,40,155,'F');
   registros[5] = eAlumno_newParam("Leo"  ,64,136,'M');
   registros[6] = eAlumno_newParam("Marco",34,137,'M');
   registros[7] = eAlumno_newParam("Pola" ,65,158,'F');
   registros[8] = eAlumno_newParam("Flaco",27,119,'M');
   registros[9] = eAlumno_newParam("Flaca",64,220,'F');

   limpiarPantallaYMostrarTitulo("CREAR ARCHIVO");

   if(registros != NULL && ruta != NULL)
   {
      returnAux = OK;

      pFile = fopen(ruta, "w"); //abro para crear archivo

      if(pFile == NULL)
      {
         printf("\nNo pudo abrirse el archivo %s para escritura", ruta);
      }
      else
      {
         //genero archivo
         for(int i=0 ; i<10 ; i++)
         {
            pAlumno = registros[i];
            fprintf(pFile, "%s,%d,%d,%c\n", pAlumno->getNombre(pAlumno),
                                            pAlumno->getEdad(pAlumno),
                                            pAlumno->getLegajo(pAlumno),
                                            pAlumno->getSexo(pAlumno));
         }
         fclose(pFile);//cierro el modo escritura
      }

      pFile = fopen(ruta, "r"); //abro modo lectura

      if(pFile == NULL)
      {
         printf("\nNo pudo abrirse el archivo %s para lectura", ruta);
      }
      else
      {
         if(!this->isEmpty(this))
         {
            //limpio lista si no esta vacia
            this->clear(this);
         }

         cantCamposLeidos = fscanf(pFile, ALUMNO_MASCARA_ARCHIVO, nombre, edad, legajo, sexo);
         printf("\n%s sexo",sexo);
         while(!feof(pFile))
         {
            if(feof(pFile))
            {
               break;
            }

            if(cantCamposLeidos == CAMPOS_A_LEER)
            {
               pAlumno = eAlumno_new();
               if(pAlumno != NULL)
               {
                  huboErrorAddRegistro = 0;
                  huboErrorAddRegistro += pAlumno->setNombre(pAlumno, nombre);
                  huboErrorAddRegistro += pAlumno->setEdad(pAlumno, atoi(edad));
                  huboErrorAddRegistro += pAlumno->setLegajo(pAlumno, atoi(legajo));
                  huboErrorAddRegistro += pAlumno->setSexo(pAlumno, sprintf(sexo, "%c", sexo));
               }
               else
               {
                  huboErrorAddRegistro = 1;
               }

               if(!huboErrorAddRegistro)
               {
                  this->add(this, pAlumno);
                  leidosOk++;
               }
               else
               {
                  leidosError++;
               }
            }
            else
            {
               leidosError++;
            }

            cantCamposLeidos = fscanf(pFile, ALUMNO_MASCARA_ARCHIVO, nombre, edad, legajo, sexo);
         }

         this->print(this,
                     ALUMNO_PAGESIZE,
                     eAlumno_printOne,
                     ALUMNO_PRINT_MASK_CABECERA,
                     ALUMNO_PRINT_MASK);
         printf("\n\nSe leyo un archivo desde la ruta %s", ruta);
         printf("\nSe cargaron %d registros.", leidosOk);
         if(!leidosError)
         {
            printf("\nHubo errores con %d registros.", leidosError);
         }
      }
   }
   pausa();
   return returnAux;
}
//-----------------------------------------------------------------------------------------------//


/**************************** GESTION DE DATOS ***************************************************/
void eAlumno_delete(eAlumno* this)
{
    free(this);
}
//-----------------------------------------------------------------------------------------------//
void eAlumno_gestionListar(ArrayList* this)
{
   limpiarPantallaYMostrarTitulo(ALUMNO_LISTADO_TITULO);

   if(this != NULL)
    {
      if(eAlumno_listIsEmptyLegend(this) == 0)
      {
         eAlumno_sortByEdad(this);
         this->print(this, ALUMNO_PAGESIZE, eAlumno_printOne,ALUMNO_PRINT_MASK_CABECERA,ALUMNO_PRINT_MASK);
      }
    }
    pausa();
}
//-----------------------------------------------------------------------------------------------//
void eAlumno_gestionOrdenar(ArrayList* this)
{
   limpiarPantallaYMostrarTitulo(ALUMNO_ORDEN_TITULO);

   if(!eAlumno_listIsEmptyLegend(this))
   {
      eAlumno_sortByEdad(this);
      //eAlumno_sortByNombre(this);
      imprimirEnPantalla(ALUMNO_MSJ_ORDEN_OK);
   }
   pausa();
}
//-----------------------------------------------------------------------------------------------//


/**************************** ORDENAMIENTO *******************************************************/
int eAlumno_compareByEdad(void* pA, void* pB)
{
   int returnAux = 0;

   if(((eAlumno*)pA)->getEdad(pA) > ((eAlumno*)pB)->getEdad(pB))
   {
      returnAux = 1;
   }
   else if(((eAlumno*)pA)->getEdad(pA) < ((eAlumno*)pB)->getEdad(pB))
   {
      returnAux = -1;
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAlumno_compareByNombre(void* pA,void* pB)
{
   return strcmp(((eAlumno*)pA)->nombre, ((eAlumno*)pB)->nombre);
}
//-----------------------------------------------------------------------------------------------//
int eAlumno_sortByEdad(ArrayList* this)
{
   int returnAux = CHECK_POINTER;

   if(this!=NULL)
   {
      returnAux = OK;
      this->sort(this, eAlumno_compareByEdad, ALUMNO_ORDEN_ASC);
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAlumno_sortByNombre(ArrayList* this)
{
   int returnAux = CHECK_POINTER;

   if(this!=NULL)
   {
      returnAux = OK;
      this->sort(this, eAlumno_compareByNombre, ALUMNO_ORDEN_ASC);
   }

   return returnAux;
}
//-----------------------------------------------------------------------------------------------//
