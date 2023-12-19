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

// O(mn) O(mn)
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                int sum = 0;
                int count = 0;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        int dx = row + i;
                        int dy = col + j;
                        if (dx >= 0 and dx < m and dy >= 0 and dy < n) {
                            sum += img[dx][dy];
                            count++;
                        }
                    }
                }
                res[row][col] = sum / count;
            }
        }

        return res;
    }
};

int main() {
    vector<vector<vector<int>>> inputs = {
        {{100,200,100}, {200,50,200}, {100,200,100}}
    };
    // 137 141 137
    // 141 138 141
    // 137 141 137

    Solution ans;
    for (auto& x : inputs) {
        vector<vector<int>> res = ans.imageSmoother(x);
        print_res(res);
    }
    return 0;
}