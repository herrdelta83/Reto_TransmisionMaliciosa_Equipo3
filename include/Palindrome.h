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
        void matrix(std::size_t size); //declared matrix func and uses Length as function parameter with a pointer and its argument (string)
};


#endif