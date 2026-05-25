/*
 * Brute-force pattern search: checks each position in texto for patron.
 * Autores: [Nombre Apellido] - [Matricula]
 * Fecha: 2026-05-24
 */
#include "../include/Scanner.h"

// Searches for patron inside texto using brute-force O(n*m).
// Param texto: the string to search in.
// Param patron: the pattern to search for.
// Returns: {true, 1-based position} if found, {false, -1} otherwise.
std::pair<bool, int> scanner(std::string texto, std::string patron) {
    for (int i = 0; i < (int)texto.length(); i++) {
        bool encontrado = true;

        for (int j = 0; j < (int)patron.length() && encontrado; j++) {
            if (i + j >= (int)texto.length() || texto[i + j] != patron[j]) {
                encontrado = false;
            }
        }

        if (encontrado) {
            return {true, i + 1};
        }
    }

    return {false, -1};
}
