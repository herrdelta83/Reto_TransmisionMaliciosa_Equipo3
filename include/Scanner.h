/*
 * Pattern matching scanner using brute-force substring search.
 * Autores: Silvanna Farias A01178494
 * Fecha: 2026-05-24
 */
#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <utility>

std::pair<bool, int> scanner(std::string texto, std::string patron);

#endif
