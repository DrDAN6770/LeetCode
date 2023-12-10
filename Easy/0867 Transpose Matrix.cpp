#include <iostream>
#include <vector>
#include <stack>

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

// O(mn) O(mn)
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));

        for (int col = 0; col < n; col++) {
            for (int row = 0; row < m; row++) {
                res[col][row] = matrix[row][col];
            }
        }
        
        return res;
    }
};


int main() {
    vector<vector<vector<int>>> inputs = {
        {{1,2,3}, {4,5,6}, {7,8,9}}, {{1,2,3},{4,5,6}}
    };
    // [1,4,7] [2,5,8] [3,6,9]
    // [1,4] [2,5] [3,6]

    Solution ans;
    for (auto& x : inputs) {
        vector<vector<int>> res = ans.transpose(x);
        print_res(res);
    }
    return 0;
}