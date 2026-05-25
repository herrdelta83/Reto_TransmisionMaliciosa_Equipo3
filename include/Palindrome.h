#ifndef PALINDROME_H
#define PALINDROME_H
#include <cstddef> //used for size_t
#include <string>
#include <utility>
#include <iostream>

class LPS {
    public:
        std::size_t Length(std::string S); //declared length func
        void LIS(std::size_t size, std::string Str); //declared LIS func to search through k > 1 in dp
};

#endif