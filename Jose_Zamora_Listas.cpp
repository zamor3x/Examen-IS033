// Librerias de c
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
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
        printf("\n\t\t2: Imprimir lista");
        printf("\n\t\t3: Calculos");
        printf("\n\t\t4: Salir\n\n");
        printf("\t\tDigite su opcion: ");
        scanf("%d", &seleccion);
        switch (seleccion)
        {
        case 1:
            printf("\n\n\t\t\tS U B   M E N U\n\n");
            printf("\n\t\t1: Insertar al inicio");
            printf("\n\t\t2: Insertar al final");
            scanf("%d",&sub_seleccion);
            if(sub_seleccion == 1){
                printf("\n\tDigite un número entero: ");
                scanf("%d", &numero);
                insertar_inicio(&puntero, numero);
            }
            if(sub_seleccion == 2){
                printf("\n\tDigite un número entero: ");
                scanf("%d", &numero);
                insertar_final(&puntero, numero);
            }
            else{
                printf("\n\t\t\tOpcion desconocida");
            }
            break;
        case 2:
            if (puntero != NULL)
                leer(puntero);
            else
                printf("\n\t\t\tLista vacia");
            break;

        case 3:
            printf("\n\n\t\t\tS U B   M E N U\n\n");
            printf("\n\t\t1: Calcular e imprimir la suma de los valores que sean pares y su promedio");
            printf("\n\t\t2: Calcular e imprimir la suma de los valores que sean impares y su promedio");
            scanf("%d",&sub_seleccion);
            if (sub_seleccion == 1){
                
            }
            if (sub_seleccion == 2){

            }
            else{
                
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
    printf("\tElemento %d insertado al inicio de la lista !", numero);
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
        // ciclo para llegar al final de la lista
        while (p->siguiente != NULL)
        {
            p = p->siguiente;
        }
        p->siguiente = nuevo; // conecto el último nodo al nuevo
    }
    printf("\tElemento %d insertado al final de la lista !", numero);
}

void leer(Nodo *puntero)
{
    int dato_variable;
    printf("\n\t\t LISTA \n");

    Nodo *p = puntero;
    // ciclo para llegar al final de la lista
    while (p != NULL)
    {
        printf("\t%d ", p->dato);
        p = p->siguiente;
    }

    printf("\n\n");
}