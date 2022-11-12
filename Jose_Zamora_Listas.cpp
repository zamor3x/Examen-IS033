// Librerias de c
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
// Estructura de almacenamiento para los datos
struct espacio
{
    int dato;
    struct espacio *siguiente;
};
// Definicion del tipo de dato
typedef struct espacio Nodo;
// Metodos de calculos y sub procesos
void insertar_inicio(Nodo **puntero, int entrada);
void insertar_final(Nodo **puntero, int entrada);
void leer(Nodo *puntero);
void par(Nodo*);
void impar(Nodo*);
void menu();
// Asignacion de NULL al puntero
Nodo *puntero = NULL;
// Metodo principal
int main()
{
    // Llamado al metodo de menu
    menu();
}
// Metodo menu
void menu()
{
    // Declaracion de la seleccion del menu y el numero a ejecutar
    int seleccion, numero,sub_seleccion;
    do
    {
        // Estructura del menu tomado del ejemplo realizado en clase
        printf("\n\n\t\t\tM E N U\n\n");
        printf("\n\t\t1: Insertar elementos");
        printf("\n\t\t2: Imprimir puntero");
        printf("\n\t\t3: Calculos");
        printf("\n\t\t4: Salir\n\n");
        printf("\t\tDigite su opcion: ");
        scanf("%d", &seleccion);
        switch (seleccion)
        {
        case 1:// Submenu para elegir la posicion al momento de ubicar el elemento
            printf("\n\n\t\t\tS U B   M E N U\n\n");
            printf("\n\t\t1: Insertar al inicio");
            printf("\n\t\t2: Insertar al final");
            printf("\n\t\tDigite su opcion: ");
            scanf("%d",&sub_seleccion);
            if(sub_seleccion == 1){
                printf("\n\tDigite un número entero: ");
                scanf("%d", &numero);
                // Llamado al metodo de insertar inicio
                insertar_inicio(&puntero, numero);
            }
            if(sub_seleccion == 2){
                printf("\n\tDigite un número entero: ");
                scanf("%d", &numero);
                // Llamado al metodo de insertar final
                insertar_final(&puntero, numero);
            }
            break;
        case 2:// Lectura de todos los nodos
            if (puntero != NULL)
                // Llamado al metodo de lectura
                leer(puntero);
            else
                printf("\n\t\t\tpuntero vacia");// Mensaje de error
            break;

        case 3:// Submenu para elegir si calcular los numeros pares o impares
            printf("\n\n\t\t\tS U B   M E N U\n\n");
            printf("\n\t\t1: Calcular e imprimir la suma de los valores que sean pares y su promedio");
            printf("\n\t\t2: Calcular e imprimir la suma de los valores que sean impares y su promedio");
            printf("\n\t\tDigite su opcion: ");
            scanf("%d",&sub_seleccion);
            if (sub_seleccion == 1){
                par(puntero);
            }
            if (sub_seleccion == 2){
                impar(puntero);
            }
            break;
        }
        getch();
    } while (seleccion != 4);
}

void insertar_inicio(Nodo **puntero, int numero)
{
    Nodo *nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = numero;
    nuevo->siguiente = NULL;

    if (*puntero == NULL) // si no hay nodos
        *puntero = nuevo;
    else
    {
        nuevo->siguiente = *puntero; // si hay nodos lo conecto al primero
        *puntero = nuevo;
    }
    printf("\tElemento %d insertado al inicio de la puntero !", numero);
}

void insertar_final(Nodo **puntero, int numero)
{
    Nodo *nuevo;
    int dato_variable;

    nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = numero;
    nuevo->siguiente = NULL;

    if (*puntero == NULL)
        *puntero = nuevo;
    else
    {
        Nodo *p;
        p = *puntero;
        // ciclo para llegar al final de la puntero
        while (p->siguiente != NULL)
        {
            p = p->siguiente;
        }
        p->siguiente = nuevo; // conecto el último nodo al nuevo
    }
    printf("\tElemento %d insertado al final de la puntero !", numero);
}

void leer(Nodo *puntero)
{
    int dato_variable;
    printf("\n\t\t puntero \n");

    Nodo *p = puntero;
    // ciclo para llegar al final de la puntero
    while (p != NULL)
    {
        printf("\t%d ", p->dato);
        p = p->siguiente;
    }

    printf("\n\n");
}

void par(Nodo *puntero)
{
    int suma_par = 0;
    int contadorPar = 0;
    float promedio_par = 0;
    while (puntero != NULL)
    {
        if (puntero->dato % 2 == 0)
        {
            contadorPar = contadorPar + 1;
            suma_par = suma_par + puntero->dato;
            puntero = puntero->siguiente;
        }
        else
        {
            puntero = puntero->siguiente;
        }

    }
    promedio_par = suma_par;
    promedio_par = (promedio_par / contadorPar);
    cout << "\n\t\tEl valor de suma es " << suma_par;
    cout << "\n\t\tY su promedio es " << promedio_par;
}

void impar(Nodo *puntero)
{
    int suma_impar = 0;
    int contador_impar = 0;
    float promedio_impar = 0;
    while (puntero != NULL)
    {
        if (puntero->dato % 2 != 0)
        {
            contador_impar = contador_impar + 1;
            suma_impar = suma_impar + puntero->dato;
            puntero = puntero->siguiente;
        }
        else
        {
            puntero = puntero->siguiente;
        }

    }
    promedio_impar = suma_impar;
    promedio_impar = (promedio_impar / contador_impar);
    cout << "\n\t\tEl valor de suma es " << suma_impar;
    cout << "\n\t\tY su promedio es " << promedio_impar;
}