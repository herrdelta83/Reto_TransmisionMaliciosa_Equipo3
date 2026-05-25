#include <iostream>
#include <cstddef>
#include <algorithm> //use max() function
#include "C:/Users/52812/Documents/Work/Personal/Workplace/DSA/E1.cpp/include/Palindrome.h"

//function to return the length
std::size_t LPS::Length(std::string S){ std::size_t len = S.size(); return len;}


//LPS Algorithm
void LPS::LIS(std::size_t size, std::string Str){
    //LPS
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
    std::cout << "LPS: " << "(" << dp[0][size - 1] << ")" << '\n' << std::endl;
    //Backtracking the DP in look for LPS String
    int lps_len = dp[0][size - 1];

    //create an empty string of LPS length, filled with spaces
    std::string lps_str(lps_len, ' ');

    //Matrix Trackers
    int I = 0; int J = size - 1;

    //string placement trackers
    int left_idx = 0; int right_idx = lps_len - 1;

    //Cell trackers
    int N = dp[I][J - 1]; 
    int M = dp[I + 1][J]; 
    int INNER = dp[I + 1][J - 1];

    //backtracking the footprints backward
    while(I <= J){
        if(Str[I] == Str[J]){
            //Footprint 1: the characters matched! They belong in our palindrome.
            //placing them in current outer edges of result string
            lps_str[left_idx] = Str[I];
            lps_str[right_idx] = Str[J];

            //Move inward on both matrix and result string
            left_idx++;
            right_idx--;
            I++;
            J--;
        }
        else if(N > M){
            //Footprint 2: The max value came from the left. Move left.
            J--;
        }
        else{
            //Footprint 3: The max value came from the right. Move Down
            I++;
        }
    }
    std::cout << "LPS String is: " << lps_str << "\n" << std::endl;
}