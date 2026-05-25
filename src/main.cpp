#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../include/Palindrome.h"
#include "../include/Scanner.h"
#include "../include/Similarity.h"

const std::vector<std::string> files = {"transmission1.txt", "transmission2.txt", "mcode1.txt", "mcode2.txt", "mcode3.txt"};

std::string getPath(int user) {
    switch (user) {
        case 1:
            return "data/caso1/";
        case 2:
            return "data/caso2/";
        case 3:
            return "data/caso3/";
        case 4:
            return "data/caso4/";
        default:
            return "";
    }
}

std::string normalizeContent(const std::string& input) {
    std::string output;
    output.reserve(input.size());
    for (char c : input) {
        if (c != '\r' && c != '\n') {
            output.push_back(c);
        }
    }
    return output;
}

int main() {
    int user;
    std::cout << "select the case: (1/2/3/4)" << "\n" << std::endl;
    std::cin >> user;
    std::string dir = getPath(user);

    LPS Len_Matrix;
    std::string transmission1;
    std::string transmission2;
    std::string mcode1;
    std::string mcode2;
    std::string mcode3;

    for (const std::string& filename : files) {
        std::string fullpath = dir + filename;
        std::ifstream fileStream(fullpath);

        if (!fileStream.is_open()) {
            std::cout << "The file " << filename << " didn't open" << std::endl;
            continue;
        }

        std::ostringstream buffer;
        buffer << fileStream.rdbuf();
        std::string content = normalizeContent(buffer.str());

        if (content.empty()) {
            std::cout << "File " << filename << " is empty or contains only newlines." << std::endl;
            continue;
        }

        std::size_t size = Len_Matrix.Length(content);
        std::cout << "Processing file: " << filename << std::endl;
        std::cout << "Content size: " << size << std::endl;
        Len_Matrix.LIS(size, content);

        if (filename == "transmission1.txt") {
            transmission1 = content;
        } else if (filename == "transmission2.txt") {
            transmission2 = content;
        } else if (filename == "mcode1.txt") {
            mcode1 = content;
        } else if (filename == "mcode2.txt") {
            mcode2 = content;
        } else if (filename == "mcode3.txt") {
            mcode3 = content;
        }

        std::cout << "------- end of file: " << filename << " ------" << std::endl;
        std::cout << std::endl;
    }

    std::vector<std::pair<std::string, std::string>> scanTargets = {
        {"transmission1", transmission1},
        {"transmission2", transmission2}
    };
    std::vector<std::pair<std::string, std::string>> mcodes = {
        {"mcode1", mcode1},
        {"mcode2", mcode2},
        {"mcode3", mcode3}
    };

    std::cout << "===== Scanner Results =====" << std::endl;
    for (const auto& [tname, ttext] : scanTargets) {
        for (const auto& [mname, mpattern] : mcodes) {
            if (ttext.empty() || mpattern.empty()) continue;
            auto [found, pos] = scanner(ttext, mpattern);
            if (found) {
                std::cout << mname << " found in " << tname << " at position " << pos << std::endl;
            } else {
                std::cout << mname << " not found in " << tname << std::endl;
            }
        }
    }
    std::cout << std::endl;

    if (!transmission1.empty() && !transmission2.empty()) {
        auto result = longestCommonSubstring(transmission1, transmission2);
        if (result.second > 0) {
            std::cout << "Longest common substring between transmission1 and transmission2:" << std::endl;
            std::cout << "Start position in transmission1: " << result.first << std::endl;
            std::cout << "Substring length: " << result.second << std::endl;
            std::cout << "Substring: '" << transmission1.substr(result.first - 1, result.second) << "'" << std::endl;
        } else {
            std::cout << "No common substring found between transmission1 and transmission2." << std::endl;
        }
    } else {
        std::cout << "Unable to compare transmissions because one or both files were not read." << std::endl;
    }

    return 0;
}
