#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Se declara un puntero a char 'buff' y se reserva memoria para 100 caracteres.
    char *buff, **nombres;
    buff = (char *)malloc(100 * sizeof(char));

    // Se solicita al usuario que ingrese 5 nombres.
    printf("Ingrese 5 nombres:\n");

    // Se declara un puntero a puntero a char 'nombres' y se reserva memoria para 5 punteros a char.
    nombres = (char **)malloc(5 * sizeof(char *));

    // Se realiza un bucle para leer cada nombre.
    for (int i = 0; i < 5; i++)
    {
        // Se solicita al usuario que ingrese el nombre.
        printf("Nombre %d: ", i + 1);
        gets(buff);

        // Se reserva memoria para el nombre actual y se copia el nombre desde 'buff' a 'nombres[i]'.
        nombres[i] = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(nombres[i], buff);
    }

    // Se imprime cada nombre ingresado.
    printf("\nLos nombres ingresados son:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre %d: %s\n", i + 1, nombres[i]);

        // Se libera la memoria reservada para el nombre actual.
        free(nombres[i]);
    }

    // Se libera la memoria reservada para los punteros a los nombres y para 'buff'.
    free(nombres); 
    free(buff); 

    return 0;
}
