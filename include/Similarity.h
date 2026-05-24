#ifndef SIMILARITY_H
#define SIMILARITY_H

#include <string>
#include <utility>

// Return 1-based start position and length of the longest common substring
// between t1 and t2. If there is no common substring, returns {-1, 0}.
std::pair<int, int> longestCommonSubstring(const std::string& t1, const std::string& t2);

#endif