#include <iostream>
#include <cstddef>
#include <algorithm> //use max() function
#include "C:/Users/52812/Documents/Work/Personal/Workplace/DSA/E1.cpp/include/Palindrome.h"

//function to return the length
std::size_t LPS::Length(std::string S){ std::size_t len = S.size(); return len;}

//LPS Algorithm
void LPS::LIS(std::size_t size, std::string Str){
    //std::vector<int> LIS(2); //compare nm boxes in dp 
    int dp[size][size] = {};//empty static matrix of size Len x Len
    int j = 0;
    int l1 = 0; //compare if L > 1 | L = 1
    int n, m, lis, inner;//temp var for LIS
    for(int k = 0; k <= size; k++){ //iterating in k for each diaginal k > 1
        for(int i = 0; i < size - k; i++){
            j = i + k;
            if(k == 0){
                dp[i][j] = 1;
            }
            else if(k == 1){ //k = 1
                if(Str[i] == Str[j]){
                    dp[i][j] = 2;
                }
                else{
                    dp[i][j] = 1;
                }
            }
            else if (k > 1){
                if(Str[i] == Str[j]){
                    l1 = 2;
                    n = dp[i][j - 1];
                    m = dp[i + 1][j];
                    inner = dp[i + 1][j - 1];
                    lis = std::max(n, m);
                    if(lis > inner){ //we avoid double checking n and m
                        dp[i][j] = l1 + inner;
                    }
                    else{
                        dp[i][j] = l1 + lis;
                    }
                }
                else{
                    l1 = 1;
                    n = dp[i][j - 1];
                    m = dp[i + 1][j];
                    lis = std::max(n, m);
                    dp[i][j] = lis;
                }
            }
        }
    }
    std::cout << "LPS: " << dp[0][size - 1] << std::endl;
}