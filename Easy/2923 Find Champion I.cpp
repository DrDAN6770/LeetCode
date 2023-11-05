#include <iostream>
#include <vector>
#include <numeric>
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

// O(n2) O(1)
class Solution1 {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            bool winner = true;
            for (int j = 0; j < n; j++) {
                if (i != j and grid[i][j] == 0) {
                    winner = false;
                    break;
                }
            }
            if (winner)
                return i;
        }
        return -1;
    }
};

// O(n2) O(1)
class Solution2 {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        int mx = accumulate(grid[0].begin(), grid[0].end(), 0);
        int winner = 0;
        
        for (int i = 1; i < n; i++) {
            int tmp = accumulate(grid[i].begin(), grid[i].end(), 0);

            if (tmp > mx) {
                mx = tmp;
                winner = i;
            }
        }
        return winner;
    }
};

int main() {
    vector<vector<vector<int>>> inputs = {{{{0,1},{0,0}}}, {{0,0,1},{1,0,1},{0,0,0}}}; // 0 1
    Solution1 ans;
    for (auto x : inputs) {
        int res = ans.findChampion(x);
        print_res(res);
    }
    
    return 0;
}