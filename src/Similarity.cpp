#include "../include/Similarity.h"
#include <algorithm>
#include <vector>

using namespace std;


// Complejidad: O(n*m) donde n y m son las longitudes de t1 y t2 respectivamente
// Función para encontrar el substring común más largo entre t1 y t2
std::pair<int, int> longestCommonSubstring(const std::string& t1, const std::string& t2) {
    int n = static_cast<int>(t1.size());
    int m = static_cast<int>(t2.size());

    if (n == 0 || m == 0) {
        return {-1, 0};
    }

    // dp[i][j] representa la longitud del substring común más largo que termina en t1[i-1] y t2[j-1]
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    int bestLength = 0;
    int bestEnd = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (t1[i - 1] == t2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > bestLength) {
                    bestLength = dp[i][j];
                    bestEnd = i;
                }
            }
        }
    }

    if (bestLength == 0) {
        return {-1, 0};
    }

    return {bestEnd - bestLength + 1, bestLength};
}
