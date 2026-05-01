#ifndef SCANNER_H
#define SCANNER_H
#include <string>
#include <iostream>
using namespace std;


struct SearchResult {
    bool found;
    int position;
};

//Search for malicious code
SearchResult checkMaliciousCode(const string& transmission, const string& mcode);

#endif