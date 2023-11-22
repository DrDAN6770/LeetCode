#include <iostream>
#include <vector>
#include <unordered_map>


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
}

// vector O(mn) O(m+n)
class Solution1 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        vector<vector<int>> diagonal_sum_idx(m+n-1);

        for (int row = 0; row < m; row++)
            for (int col = 0; col < mat[row].size(); col++)
                diagonal_sum_idx[row + col].push_back(mat[row][col]);

        for (int i = 0; i < m+n-1; i++) {
            if (i & 1)
                res.insert(res.end(), diagonal_sum_idx[i].begin(), diagonal_sum_idx[i].end());
            else
                res.insert(res.end(), diagonal_sum_idx[i].rbegin(), diagonal_sum_idx[i].rend());
        }

        return res;
    }
};

// hash O(mn) O(m+n)
class Solution2 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        vector<int> res;
        unordered_map<int, vector<int>> diagonal_sum_idx;

        for (int row = 0; row < m; row++)
            for (int col = 0; col < mat[row].size(); col++)
                diagonal_sum_idx[row + col].push_back(mat[row][col]);

        for (int i = 0; i < diagonal_sum_idx.size(); i++) {
            if (i & 1)
                res.insert(res.end(), diagonal_sum_idx[i].begin(), diagonal_sum_idx[i].end());
            else
                res.insert(res.end(), diagonal_sum_idx[i].rbegin(), diagonal_sum_idx[i].rend());
        }

        return res;
    }
};

int main() {
    vector<vector<vector<int>>> inputs = {{{1,2,3}, {4, 5, 6}, {7, 8, 9}}}; // 1 2 4 7 5 3 6 8 9
    Solution1 ans;
    for (auto& x : inputs) {
        vector<int> res = ans.findDiagonalOrder(x);
        print_res(res);
    }
    
    return 0;
}