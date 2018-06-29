#pragma once
#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED


/**************************** INCLUSION DE EMPTYRIAS PERSONALES **********************************/
#include "ArrayList.h"
#include "General.h"
#include "Menu.h"

/**************************** CONSTANTES *********************************************************/
#define ALUMNO_EMPTY EMPTY
#define ALUMNO_OCCUPIED OCCUPIED
#define ALUMNO_EMPTY_LEGEND "Vacio"
#define ALUMNO_OCCUPIED_LEGEND "Ocupado"
#define TRUE "true"
#define FALSE "false"
#define ALUMNO_PAGESIZE 20

/**************************** LIMITES ************************************************************/
#define ALUMNO_LENGTH_NAME 51
#define ALUMNO_LENGTH_LAST_NAME 51
#define ALUMNO_LEGAJO_MIN 1
#define ALUMNO_LEGAJO_MAX 1000000
#define ALUMNO_EDAD_MIN 1
#define ALUMNO_EDAD_MAX 1000000
#define ALUMNO_SEXO_MIN 1
#define ALUMNO_SEXO_MAX 1000000
#define ALUMNO_LENGTH_RESERVAS 10

/**************************** MASCARAS ***********************************************************/
#define ALUMNO_PRINT_MASK "\n%s \t %d \t %d \t %c"
#define ALUMNO_PARSE_MASK "%[^,],%[^,],%[^,],%[^\n]\n"
#define ALUMNO_LISTADO_RECUENTO "\n%d registros."

/**************************** TITULOS ************************************************************/
#define ALUMNO_ALTA_TITULO "ALTA DE PERSON"
#define ALUMNO_BAJA_TITULO "BAJA DE PERSON"
#define ALUMNO_MODIFICACION_TITULO "MODIFICACION DE PERSON"
#define ALUMNO_LISTADO_TITULO "LISTADO DE PERSONS"
#define ALUMNO_LISTADO_RANGO_TITULO "LISTADO DE PERSONS POR RANGO"
#define ALUMNO_PARSER_TITULO "PARSER ARCHIVO CSV DE PERSONS"
#define ALUMNO_ORDEN_TITULO "ORDENAR LISTA DE PERSONS"

/**************************** MENSAJES INFO ******************************************************/
#define ALUMNO_MSJ_ALTA_OK "\nLa Alumno se dio de alta"
#define ALUMNO_MSJ_BAJA_OK "\nLa Alumno se dio de baja"
#define ALUMNO_MSJ_MODIFICACION_SIN_CAMBIOS "\nNo hubo cambio alguno"
#define ALUMNO_MSJ_MODIFICACION_OK "\nLa Alumno se modifico"
#define ALUMNO_MSJ_REGISTRO_ACTUAL "\n\nREGISTRO DE PERSON ACTUAL:\n----------------------------"
#define ALUMNO_MSJ_REGISTRO_MODIFICADO "\n\nREGISTRO MODIFICADO:\n--------------------"
#define ALUMNO_MSJ_ORDEN_OK "\n\nSe ordeno listado por nombre"
#define ALUMNO_LISTADO_RANGO_INGRESO "\n\nSe deben ingresar los ID desde y hasta\n--------------------------------------"

/**************************** MENSAJES INPUT *****************************************************/
#define ALUMNO_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicha Alumno?"
#define ALUMNO_MSJ_INGRESE_LEGAJO "\n\nIngrese el ID de Alumno: "
#define ALUMNO_MSJ_INGRESE_EDAD "\n\nIngrese el DNI de Alumno: "
#define ALUMNO_MSJ_INGRESE_SEXO "\n\nIngrese sexo de Alumno: "
#define ALUMNO_MSJ_INGRESE_NAME "\nIngrese Nombre: "
#define ALUMNO_MSJ_INGRESE_LAST_NAME "\nIngrese Apellido: "

/**************************** MENSAJES ERROR *****************************************************/
#define ALUMNO_MSJ_LEGAJO_NO_EXISTE "\nEl ID de Alumno ingresado no existe"
#define ALUMNO_MSJ_EDAD_NO_EXISTE "\nEl DNI de Alumno ingresado no existe"
#define ALUMNO_MSJ_EDAD_YA_EXISTE "\nEl DNI %d ya existe en la lista"
#define ALUMNO_MSJ_EMPTY_LIST "\n\nLa lista de Alumnos esta vacia o todos los registros se dieron de baja"
#define ALUMNO_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Alumno"
#define ALUMNO_MSJ_REINGRESE_LEGAJO "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: "
#define ALUMNO_MSJ_REINGRESE_EDAD "\nEl DNI debe ser un numero mayor que ALUMNO_EDAD_MIN y menor que ALUMNO_EDAD_MAX. Reingrese un DNI valido:"
#define ALUMNO_MSJ_REINGRESE_SEXO "\nEl valor de stat debe ser un numero mayor que ALUMNO_SEXO_MIN y menor que ALUMNO_SEXO_MAX. Reingrese un sexo valido:"
#define ALUMNO_MSJ_REINGRESE_NAME "\nNombre no valido. Reingrese por favor hasta 50 caracteres: "
#define ALUMNO_MSJ_REINGRESE_LAST_NAME "\nApellido no valido. Reingrese por favor hasta 50 caracteres: "

/**************************** LISTADOS ***********************************************************/
#define ALUMNO_PRINT_MASK_CABECERA "\nNOMBRE \t EDAD \t LEGAJO SEXO\n------ \t ---- \t ------ ----"

/**************************** ORDENAMIENTO *******************************************************/
#define ALUMNO_ORDEN_ASC 1
#define ALUMNO_ORDEN_DESC 0

/**************************** ESTRUCTURAS ********************************************************/
struct
{
   char nombre[ALUMNO_LENGTH_NAME];
   int edad;
   int legajo;
   char sexo;

   int (*print)();

    //getters
   char* (*getNombre)();
   int (*getEdad)();
   int (*getLegajo)();
   char (*getSexo)();

    //setters
   int (*setNombre)();
   int (*setEdad)();
   int (*setLegajo)();
   int (*setSexo)();

}typedef eAlumno;


/**************************** GET ****************************************************************/
int eAlumno_getIsEmpty(eAlumno* this);
int eAlumno_getLegajo(eAlumno* this);
int eAlumno_getEdad(eAlumno* this);
char eAlumno_getSexo(eAlumno* this);
char* eAlumno_getNombre(eAlumno* this);
char* eAlumno_getLastNombre(eAlumno* this);
int eAlumno_isEmpty(eAlumno* this);
char* eAlumno_getIsEmptyLegend(eAlumno* this);


/**************************** SET ****************************************************************/
int eAlumno_setIsEmpty(eAlumno* this, int isEmpty);
int eAlumno_setLegajo(eAlumno* this, int id);
int eAlumno_setEdad(eAlumno* this, int edad);
int eAlumno_setSexo(eAlumno* this, char sexo);
int eAlumno_setNombre(eAlumno* this, char* nombre);
int eAlumno_setLastNombre(eAlumno* this, char* lastNombre);

/**************************** CONSTRUCTORES ******************************************************/
eAlumno* eAlumno_new(void);
eAlumno* eAlumno_newParam(char* nombre,
                          int edad,
                          int legajo,
                          char sexo);

/**************************** ENTRADA DE DATOS ***************************************************/
int eAlumno_askLegajo();
int eAlumno_askEdad();
int eAlumno_askSexo();
char* eAlumno_askNombre();
char* eAlumno_askLastNombre();
eAlumno* eAlumno_askInput();

/**************************** INICIALIZACIONES ***************************************************/
void eAlumno_initHardcode(ArrayList* this);
int eAlumno_init(ArrayList* this);

/**************************** BUSQUEDA ***********************************************************/
int eAlumno_listIsEmpty(ArrayList* this);
int eAlumno_listIsEmptyLegend(ArrayList* this);
eAlumno* eAlumno_getByLegajo(ArrayList* this, int id);
eAlumno* eAlumno_getByEdad(ArrayList* this, int edad);
eAlumno* eAlumno_getByAskLegajo(ArrayList* this);
eAlumno* eAlumno_getByAskEdad(ArrayList* this);

/**************************** LISTADO DE DATOS ***************************************************/
int eAlumno_printOne(void* this, char* mascara);
int eAlumno_printList(ArrayList* this, int pageSize);
int eAlumno_printListFromTo(ArrayList* this, int idFrom, int idTo, int pageSize);

/**************************** GESTION DE DATOS ***************************************************/
void eAlumno_delete(eAlumno* this);
void eAlumno_gestionParse(ArrayList* this);
void eAlumno_gestionListar(ArrayList* this);
void eAlumno_gestionListarDesdeHasta(ArrayList* this);
void eAlumno_gestionOrdenar(ArrayList* this);
int eAlumno_gestionCrearArchivo(ArrayList* this);
int eAlumno_gestionBaja(ArrayList* this);

/**************************** ORDENAMIENTO *******************************************************/
//int eAlumno_compareByNombre(void* pAlumnoA, void* pAlumnoB);
int eAlumno_compareByEdad(void* pAlumnoA, void* pAlumnoB);
int eAlumno_sortByEdad(ArrayList* this);
//int eAlumno_sortByNombre(ArrayList* this);
int funcionQueFiltra(void* item);
int eAlumno_gestionArrayFiltrado(ArrayList* alumnos, ArrayList* filtrado);
#endif // ALUMNO_H_INCLUDED
