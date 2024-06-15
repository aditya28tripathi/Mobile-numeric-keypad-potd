lass Solution {
public:
    long long getCount(int n) {
        if (n == 1) return 10;

        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(10, 0));

        // Define the adjacency list for each digit
        std::vector<std::vector<int>> moves = {
            {0, 8},     // 0
            {1, 2, 4},  // 1
            {2, 1, 3, 5}, // 2
            {3, 2, 6},  // 3
            {4, 1, 5, 7}, // 4
            {5, 2, 4, 6, 8}, // 5
            {6, 3, 5, 9}, // 6
            {7, 4, 8},  // 7
            {8, 0, 5, 7, 9}, // 8
            {9, 6, 8}   // 9
        };

        // Initialize base case
        for (int j = 0; j <= 9; ++j) {
            dp[1][j] = 1;
        }

        // Fill the dp table
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= 9; ++j) {
                dp[i][j] = 0;
                for (int k : moves[j]) {
                    dp[i][j] += dp[i-1][k];
                }
            }
        }

        // Sum up all counts of length n
        long long result = 0;
        for (int j = 0; j <= 9; ++j) {
            result += dp[n][j];
        }

        return result;
    }
};
