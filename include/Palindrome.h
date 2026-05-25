/*
 * Longest Palindromic Subsequence (LPS) using dynamic programming.
 * Autores: [Nombre Apellido] - [Matricula]
 * Fecha: 2026-05-24
 */
#ifndef PALINDROME_H
#define PALINDROME_H
#include <cstddef>
#include <string>

class LPS {
    public:
        std::size_t length(std::string s);
        void findLps(std::size_t size, std::string str);
};

#endif
