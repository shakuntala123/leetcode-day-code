#include <bits/stdc++.h>
using namespace std;

int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // length is the distance between i and j
    for (int length = 2; length < n; ++length) {   // need at least 3 vertices
        for (int i = 0; i + length < n; ++i) {
            int j = i + length;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = min(dp[i][j],
                               dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    vector<int> values1 = {1, 2, 3};
    cout << minScoreTriangulation(values1) << "\n";  // Output: 6

    vector<int> values2 = {3, 7, 4, 5};
    cout << minScoreTriangulation(values2) << "\n";  // Output: 144

    vector<int> values3 = {1, 3, 1, 4, 1, 5};
    cout << minScoreTriangulation(values3) << "\n";  // Output: 13

    return 0;
}
