#include "../include/Scanner.h"

// Buscar si un patrón esta dentro del texto
// Complejidad: O(n*m), donde n es la longitud del texto y m la longitud del patrón
pair<bool,int> scanner(string texto, string patron) {
    for (int i = 0; i < texto.length(); i++) {
        bool encontrado = true; // se asume que el patrón se encuentra hasta que se demuestre lo contrario

        for (int j = 0; j < patron.length(); j++) { // compara el patrón con el texto a partir de la posición i
            if (i + j >= texto.length() || texto[i + j] != patron[j]) { // si se sale del texto o los caracteres no coinciden, el patrón no se encuentra
                encontrado = false;
                break;
            }
        }

        if (encontrado) {
            return {true, i + 1}; // si hay patrón devuelve true y la posicion en donde se encuentra el patrón en el texto
        }
    }

    return {false, -1}; // si el patrón no se encuentra, devuelve false y -1
}
