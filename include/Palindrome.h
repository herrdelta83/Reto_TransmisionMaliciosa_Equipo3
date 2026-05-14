#ifndef PALINDROME_H
#define PALINDROME_H
#include <cstddef> //used for size_t
#include <string>
#include <utility>
#include <iostream>

//return a pair of {initialPosition, FInalPosition} (base 1)
//pair<int, int> findLongestPalindrome(const string& transmission);

class LPS {
    public:
        std::size_t Length(std::string S); //declared length func
};


#endif