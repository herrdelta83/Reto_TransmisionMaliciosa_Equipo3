/*
 * Implementation of Longest Common Substring using DP.
 * Autores: [Nombre Apellido] - [Matricula]
 * Fecha: 2026-05-24
 */
#include <vector>
#include <string>
#include "../include/Similarity.h"

// Finds the longest contiguous substring shared by t1 and t2 using DP O(n*m).
// Param t1: first transmission string.
// Param t2: second transmission string.
// Returns: {1-based start position in t1, length} or {0, 0} if none found.
std::pair<int, int> longestCommonSubstring(const std::string& t1, const std::string& t2) {
    const size_t n = t1.size();
    const size_t m = t2.size();
    if (n == 0 || m == 0) {
        return {0, 0};
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    int maxLength = 0;
    int endPos = 0;

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            if (t1[i - 1] == t2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endPos = static_cast<int>(i);
                }
            }
        }
    }

    if (maxLength == 0) {
        return {0, 0};
    }
    return {endPos - maxLength + 1, maxLength};
}
