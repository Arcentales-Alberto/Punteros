#include <stdio.h>
#include <stdlib.h>

int duplicar (int);
int triplicar (int);
void cuadriplicar (int *);
void mostrar (char **, int);
char posterior (char **);
void listarDiez (int (*f)(int));

int main(void){

    // OPERACIONES BASICAS CON PUNTEROS

    int vInt;                    // vInt es un entero
    int *pInt;                   // pInt es un puntero a un entero

    vInt = 5;

    pInt = &vInt;                // & es el operador de referencia (devuelve la dirección de una variable)

    printf("1) %p\n", (void*)pInt);     // pInt contiene una dirección de memoria
    printf("   %p\n", (void*)&pInt);    // & es el operador de referencia (devuelve la dirección de una variable)
    printf("   %d\n", vInt);     // El dato (5)
    printf("   %d\n", *pInt);    // * es el operador de desreferencia o indirección (el dato apuntado)
    printf("\n");

    pInt = (int*) malloc(sizeof(int));  // Alocación de espacio para un entero y asignación de su dirección a pInt

    *pInt = 18;                  // *pInt (el dato apuntado) es el entero 18

    printf("2) %p\n", (void*)pInt);
    printf("   %p\n", (void*)&pInt);
    printf("   %d\n", vInt);
    printf("   %d\n", *pInt);
    printf("\n");

    free (pInt);                 // Liberación de la memoria del entero apuntado por pInt

    printf("3) %p\n", (void*)pInt);
    printf("   %d\n", *pInt);
    printf("\n");

    pInt = NULL;                 // Borrado de pInt

    printf("4) %p\n", (void*)pInt);
    //	printf("   %d", *pInt);  // NULL no puede desreferenciarse
    printf("\n");


    // RELACION ENTRE ARREGLOS Y PUNTEROS

    pInt = (int*) malloc((unsigned)vInt * sizeof(int)); // "Alocación" (Reserva) de espacio para un arreglo y asignación de su dirección a pInt

    int i;
    for (i = 0; i < vInt; i++) {
        pInt[i] = i * 2;              // Carga del arreglo
    }

    printf("5) ");
    for (i = 0; i < vInt; i++) {
        printf("%d ", pInt[i]);       // Acceso al contenido del arreglo mediante corchetes
    }
    printf("\n\n");

    printf("6) ");
    for (i = 0; i < vInt; i++) {
        printf("%d ", *(pInt + i));   // Acceso al contenido del arreglo mediante punteros
    }
    printf("\n\n");

    free (pInt);                      // Liberación de la memoria del arreglo apuntado por pInt

    char *cadena;

    cadena = (char*) malloc(4 * sizeof(char));// Alocación de espacio para un arreglo y asignación de su dirección a cadena

    *cadena = 'S';
    *(cadena+1) = 'O';
    *(cadena+2) = 'L';
    *(cadena+3) = '\0';

    printf("7) %s\n", cadena);
    printf("\n");

    free (cadena);                     // Liberación de la memoria del arreglo apuntado por cadena

    cadena = (char*) malloc(4 * sizeof(char)); // Alocación de espacio para un arreglo y asignación de su dirección a cadena

    cadena[0] = 'M';
    cadena[1] = 'A';
    cadena[2] = 'R';
    cadena[3] = '\0';

    printf("8) %s\n", cadena);
    printf("\n");

    free (cadena);                     // Liberación de la memoria del arreglo apuntado por cadena

    cadena = "FIN DE SEMANA";          // Alocación de espacio para un arreglo y asignación de su dirección a cadena

    printf("9) %s\n", cadena);
    printf("\n");


    //  PUNTEROS A ESTRUCTURAS

    struct punto {
        int x;
        int y;
    };                                // La declaración struct define un tipo

    struct punto p;                   // p es una variable de tipo struct punto

    p.x = 10;
    p.y = 15;

    printf("10) x=%d\n", p.x);         // Acceso a los campos de la estructura
    printf("    y=%d\n", p.y);
    printf("\n");

    struct punto *pPunto;             // pPunto es un puntero a un struct punto

    pPunto = &p;                      // Su contenido es la dirección de p

    printf("11) x=%d\n", (*pPunto).x); // Acceso a los campos de la estructura apuntada (paréntesis obligatorios)
    printf("    y=%d\n", (*pPunto).y);
    printf("\n");

    printf("12) x=%d\n", pPunto->x);   // Acceso a los campos de la estructura apuntada (con flecha)
    printf("    y=%d\n", pPunto->y);
    printf("\n");


    //  PUNTEROS A FUNCIONES

    int (*pFunc)(int);                // pFunc es un puntero a una función

    pFunc = &duplicar;                // A pFunc se le asigna la dirección de duplicar

    printf ("13) %d\n", (*pFunc)(3)); // Forma tradicional de invocar la función mediante el puntero
    printf ("    %d\n", pFunc(3));    // Forma moderna de invocar la función mediante el puntero
    printf("\n");

    pFunc = triplicar;                // A pFunc se le asigna la dirección de triplicar (& es redundante)

    printf ("14) %d\n", (*pFunc)(3)); // Forma tradicional de invocar la función mediante el puntero
    printf ("    %d\n", pFunc(3));    // Forma moderna de invocar la función mediante el puntero
    printf("\n");

    printf ("15)\n");
    listarDiez(&duplicar);            // Se pasa la dirección de duplicar
    printf("\n");
    listarDiez(triplicar);            // Se pasa la dirección de triplicar (& es redundante)
    printf("\n");

    //  PUNTEROS COMO PARAMETROS DE FUNCIONES

    printf ("16) %d\n", vInt);    // Se muestra un entero

    cuadriplicar (&vInt);         // Se pasa la dirección de la variable, no su valor

    printf ("    %d\n", vInt);    // Se muestra el entero modificado
    printf("\n");


    //  PUNTEROS A PUNTEROS

    char vChar;                   // Un char
    char *pChar;                  // Un puntero a un char

    vChar = 'R';
    pChar = &vChar;

    printf("17) %p\n", (void*)pChar);    // pChar contiene una dirección de memoria
    printf("    %c\n", *pChar);   // * es el operador de desreferencia o indirección (el dato apuntado)
    printf("\n");

    char **ppChar;                // Un puntero a un puntero a un char;
    ppChar = &pChar;

    printf("18) %p\n", (void*)ppChar);   // ppChar contiene una dirección de memoria
    printf("    %p\n", (void*)ppChar);  // * es el operador de desreferencia o indirección (el dato apuntado)
    printf("    %c\n", **ppChar); // Recién aquí se llega al char apuntado
    printf("\n");

    char **vecPChar = (char**) malloc((unsigned)vInt);  // Suficiente espacio para que alcance...

    *vecPChar = "Cero";            // Se carga el espacio recién reservado
    *(vecPChar+1) = "Uno";
    *(vecPChar+2) = "Dos";
    *(vecPChar+3) = "Tres";

    printf("19) %p\n", (void*)vecPChar);  // vecPChar contiene una dirección de memoria
    mostrar(vecPChar, 4);          // Se pasa la dirección contenida en la variable y la cantidad de elementos
    printf("\n");

    printf("20) %c\n", posterior(&pChar));  // El char que viene después de la R
    printf("\n");

    return 0;
}


int duplicar (int n){
    return n + n;
}

int triplicar (int n){
    return n + n + n;
}

void cuadriplicar (int *n){
    *n = *n + *n + *n + *n;
}

void mostrar (char **v, int n){
    int i;
    for (i = 0; i < n; i++) {
        printf("    %s\n", *(v+i));
    }
}

char posterior (char **c){
    return **c + 1;
}

void listarDiez (int (*f) (int)){
    int i;
    for (i = 0; i < 10; i++) {
        printf("    %d\n", (*f)(i));
    }
}
