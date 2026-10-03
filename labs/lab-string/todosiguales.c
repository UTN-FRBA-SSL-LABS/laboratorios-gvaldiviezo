#include <stdio.h>
#include "String.h"

/*
 * todosiguales — imprime 1 si todos los argumentos son iguales, 0 si no.
 *
 * Uso: ./todosiguales hola hola hola  →  1
 *      ./todosiguales hola mundo      →  0
 *
 * Pista: compara cada argumento contra argv[1] usando AreEqual.
 *        Iterá con puntero (char **arg), no con indice entero.
 */


int main(int argc, char *argv[]) {
    (void)argc;

    /* Si no se pasaron argumentos, se considera trivialmente verdadero */
    if (argv[1] == NULL) {
        printf("1\n");
        return 0;
    }

    const char *referencia = argv[1];

    /* Compara desde el segundo argumento (argv + 2) hasta el centinela NULL */
    for (char **arg = argv + 2; *arg != NULL; arg++) {
        if (!AreEqual(referencia, *arg)) {
            printf("0\n");
            return 0;
        }
    }

    printf("1\n");
    return 0;
}