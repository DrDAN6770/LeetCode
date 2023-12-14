#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_res(const T& input) {
    if constexpr (is_same_v<T, int> || is_same_v<T, long> || is_same_v<T, long long> ||
                  is_same_v<T, bool> || is_same_v<T, float> || is_same_v<T, double> || is_same_v<T, string>)
        cout << input << endl;

    else if constexpr (is_same_v<T, vector<int>>) {
        for (auto x : input)
            cout << x << " ";
        cout << endl;
    }

    else if constexpr (is_same_v<T, vector<vector<int>>>) {
        for (auto x : input)
            for (auto y : x)
                cout << y << " ";
        cout << endl;
    }
}

// O(mn) O(m+n) Math
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> onesRow(m, 0), onesCol(n, 0);
        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                // only 1 or 0
                onesRow[row] += grid[row][col];
                onesCol[col] += grid[row][col];
            }
        }

        // onesRowi + onesColj - zerosRowi - zerosColj
        // = onesRowi + onesColj - (m - onesRowi) - (n - onesColj)
        // = 2 * onesRowi + 2 * onesColj - m -n
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                res[row][col] = 2 * onesRow[row] + 2 * onesCol[col] - m - n;
            }
        }

        return res;
    }
};


int main() {
    vector<vector<vector<int>>> inputs = {
        {{0,1,1}, {1,0,1}, {0,0,1}}, {{1,1,1}, {1,1,1}}
    };
    //  0  0  4     5 5 5
    //  0  0  4     5 5 5
    // -2 -2  2

    Solution ans;
    for (auto& x : inputs) {
        vector<vector<int>> res = ans.onesMinusZeros(x);
        print_res(res);
    }
    return 0;
}