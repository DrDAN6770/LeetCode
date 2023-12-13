#include <iostream>
#include <vector>
#include <algorithm>

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
class Solution0 {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> visited_x(m, 0), visited_y(n, 0);
        int res = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 1) {
                    visited_x[row]++;
                    visited_y[col]++;
                }
            }
        }

        for (int row = 0; row < m; row++)
            for (int col = 0; col < n; col++)
                if (mat[row][col] == 1 and visited_x[row] == 1 and visited_y[col] == 1)
                    res++;
        
        return res;
    }
};


int main() {
    vector<vector<vector<int>>> inputs = {
        {{1,0,0}, {0,1,0}, {0,0,1}}, {{1,0,0}, {0,0,1}, {1,0,0}}
    }; // 3 1

    Solution0 ans;
    for (auto& x : inputs) {
        int res = ans.numSpecial(x);
        print_res(res);
    }
    return 0;
}