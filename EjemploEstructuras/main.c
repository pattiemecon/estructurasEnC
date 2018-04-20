#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\Funciones\funciones.h"

#define TAM 5

typedef struct
{
    int legajo;
    int notaUno;
    int notaDos;
    float promedio;
    char nombre[50];
    int estado;
} sAlumno;

int buscarLugarLibre(sAlumno[], int);
int buscarAlumno(sAlumno[], int);
sAlumno pedirAlumno(void);
void mostrarListado(sAlumno[], int);
void ordenarPorPromedio(sAlumno[], int);
int insertarEnLista(sAlumno[], int);
void mostrarAlumno(sAlumno);

int main()
{
    sAlumno listadoAlumnos[TAM];
    int i;

    for(i = 0; i < TAM; i++)
    {
        listadoAlumnos[i].estado = 0;
    }

    listadoAlumnos[0] = pedirAlumno();
    mostrarAlumno(listadoAlumnos[0]);

    return 0;
}

sAlumno pedirAlumno(void)
{
    sAlumno alumno;

    do
    {
        alumno.legajo = pedirEnteroSinValidar("Ingrese legajo: ");
        if(alumno.legajo <= 0)
        {
            printf("Debe ingresar un numero de legajo positivo\n");
        }
    } while(alumno.legajo <= 0);

    alumno.notaUno = pedirEntero("Ingrese la nota uno: ", 1, 10);
    alumno.notaDos = pedirEntero("Ingrese la nota dos: ", 1, 10);
    alumno.promedio = (float)(alumno.notaUno + alumno.notaDos) / 2;
    do
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(alumno.nombre);
        if(strcmp(alumno.nombre, "") == 0)
        {
            printf("Debe ingresar un nombre\n");
        }
    } while(strcmp(alumno.nombre, "") == 0);
    alumno.estado = 1;

    return alumno;
}

void mostrarAlumno(sAlumno alumno)
{
    printf("\n%d", alumno.legajo);
    printf(";%s", alumno.nombre);
    printf(";%d", alumno.notaUno);
    printf(";%d", alumno.notaDos);
    printf(";%5.2f", alumno.promedio);
    printf("\n");
}

int buscarLugarLibre(sAlumno alumnos[], int cantidadElementos)
{
    int indiceLibre = -1;
    int i;

    for(i = 0; i < cantidadElementos; i++)
    {
        if(alumnos[i].estado == 0)
        {
            indiceLibre = i;
            break;
        }
    }

    return indiceLibre;
}
