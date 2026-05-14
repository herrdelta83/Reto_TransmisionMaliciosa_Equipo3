#include <iostream>
#include <cstddef>
#include "C:/Users/52812/Documents/Work/Personal/Workplace/DSA/E1.cpp/include/Palindrome.h"

//function to return the length
std::size_t LPS::Length(std::string S){ std::size_t len = S.size(); return len;}
//function to display matrix
void LPS::matrix(std::size_t size){
    char M[size][size] = {};//empty static matrix of size Len x Len
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            M[i][j] = '1';
            std::cout << M[i][j] << " ";
        }
    }
}