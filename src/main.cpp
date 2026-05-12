#include <iostream>
#include <fstream> //open files
#include <string>
#include <vector>
using namespace std;

const vector<string> files[] = {"transmission1.txt", "transmission2.txt", "mcode1.txt", "mcode2.txt", "mcode3.txt"};
//Use a function to read data and save it as a vector of strings

string caso(const string& user){ //recieve user input
    string path;
    switch(user){
        case  1:
            path = "data/caso1";
            cout << "caso 1" << endl;
        case 2:
            path = "data/caso2";
            cout << "caso 2" << endl;
        case 3:
            path = "data/caso3";
            cout << "caso 3" << endl;
        case 4:
            pah = "data/caso4";
            cout << "caso 4" << endl;
    }
    return path; //return the selected path
};

int main(){

    string user;
    cout << "select the case: (1/2/3/4)" << "\n" << endl;
    cin >> user;
    caso(user);

    //create a new vector for the path
    vector<string> path[] = {};
    for (int i = 0; i < files.length(); i++){
        path.push_back(user + path[i]);//concatenate new path
    }

    for (const string& filename : path){
        
        ifstream filename; //initialized variable
        
        //check file open
        if(!filename.is_open()){
            cout << "The file didn't open" << filename << endl;
            continue;
        }

        string content;
        
        //read file
        while(path >> content){
            cout << content << " " << endl;
        }

        cout << "\n" << "------- end of file: " << filename << "------\n" << endl;
    }

    return 0;
}
