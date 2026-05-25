#include <iostream>
#include <cstddef> //for size_t
#include <fstream> //open files
#include <string>
#include <vector>

#include "C:/Users/52812/Documents/Work/Personal/Workplace/DSA/E1.cpp/include/Palindrome.h"
using namespace std;

const vector<string> files = {"transmission1.txt", "transmission2.txt", "mcode1.txt", "mcode2.txt", "mcode3.txt"};
//Use a function to read data and save it as a vector of strings

string getPath(const int& user){ //recieve user input
    switch(user){
        case 1:
            cout << "caso 1" << endl;
            return "C:\\Users\\52812\\Documents\\Work\\Personal\\Workplace\\DSA\\E1.cpp\\data\\caso1\\";
        case 2:
            cout << "caso 2" << endl;
            return "C:\\Users\\52812\\Documents\\Work\\Personal\\Workplace\\DSA\\E1.cpp\\data\\caso2\\";
        case 3:
            cout << "caso 3" << endl;
            return "C:\\Users\\52812\\Documents\\Work\\Personal\\Workplace\\DSA\\E1.cpp\\data\\caso3\\";
        case 4:
            cout << "caso 4" << endl;
            return "C:\\Users\\52812\\Documents\\Work\\Personal\\Workplace\\DSA\\E1.cpp\\data\\caso4\\";
        default:
            return "no selected or wrong path chosen";
    }
};

int main(){
    int user;
    cout << "select the case: (1/2/3/4)" << "\n" << endl;
    cin >> user;
    string dir = getPath(user);

    //Palindrome Class
    LPS Len_Matrix;

    for (const string& filename : files){
        //Concatenate selected path to case
        string fullpath = dir + filename;
        
        ifstream fileStream(fullpath); //initialized variable
        
        //check file open
        if(!fileStream.is_open()){
            cout << "The file " << filename << " didn't open" << endl;
            continue;
        }
        
        string content;
        size_t size;
        
        //read file
        while(fileStream >> content){
            
            size = Len_Matrix.Length(content); //size of the matrix for dp[][]
            cout << "the dp[][] size: " << size << " x " << size << endl;
            Len_Matrix.LIS(size, content);

            cout << content << " " << endl;
        }
        
        cout << "\n" << "------- end of file: " << filename << "------\n" << endl;
        
    }

    return 0;
}
