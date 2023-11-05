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
}

// O(n) O(n)
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> loser(n, 1);
        int count_winner = 0;
        int winner = 0;

        for (const auto& e : edges)
            loser[e[1]] = 0;

        for (int i = 0; i < n; i++) {
            if (loser[i] == 1) {
                count_winner++;
                winner = i;
            }
            if (count_winner >= 2)
                return -1;
        }
        return winner;
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> inputs = {{3, {{0,1},{1,2}}}, {4, {{0,2},{1,3},{1,2}}}}; // 0 -1
    Solution ans;
    for (auto x : inputs) {
        int res = ans.findChampion(x.first, x.second);
        print_res(res);
    }
    
    return 0;
}