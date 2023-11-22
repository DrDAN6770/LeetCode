#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

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

// BFS O(m+n) O(m+n)
class Solution1 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        queue<pair<int, int>> q;
        int m = nums.size();

        q.push({0, 0});

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (col == 0 and row + 1 < m)
                q.push({row + 1, col});
            
            if (col + 1 < nums[row].size())
                q.push({row, col + 1});

            res.push_back(nums[row][col]);

        }

        return res;
    }
};

// vector O(mn) O(m+n)
class Solution2 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        int m = nums.size();
        int max_n = 0;

        for (int i = 0; i < m; i++) {
            int tmp = nums[i].size() - 1;
            max_n = max(max_n, tmp);
        }
            
        vector<vector<int>> diagonal_idxtable(max_n + m);

        for (int row = m - 1; row > -1; row--)
            for (int col = 0; col < nums[row].size(); col++)
                diagonal_idxtable[row + col].push_back(nums[row][col]);


        for (int i = 0; i < diagonal_idxtable.size(); i++)
            res.insert(res.end(), diagonal_idxtable[i].begin(), diagonal_idxtable[i].end());

        return res;
    }
};

// hash O(mn) O(m+n)
class Solution3 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        unordered_map<int, vector<int>> diagonal_idxtable;

        for (int row = nums.size() - 1; row > -1; row--) {
            for (int col = 0; col < nums[row].size(); col++) {
                diagonal_idxtable[row + col].push_back(nums[row][col]);
            }
        }

        for (int i = 0; i < diagonal_idxtable.size(); i++)
            res.insert(res.end(), diagonal_idxtable[i].begin(), diagonal_idxtable[i].end());

        return res;
    }
};

int main() {
    vector<vector<vector<int>>> inputs = {{
                                            {1,2,3,4,5},
                                            {6,7},
                                            {8},
                                            {9,10,11},
                                            {12,13,14,15,16} // 1 6 2 8 7 3 9 4 12 10 5 13 11 14 15 16
        }, {
            {1,2,3},
            {4,5,6},
            {7,8,9} // 1 4 2 7 5 3 8 6 9
        }
    };
    Solution1 ans;
    for (auto& x : inputs) {
        vector<int> res = ans.findDiagonalOrder(x);
        print_res(res);
    }
    
    return 0;
}