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
}

// O(n) O(1)
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;

        for (int i = 1; i < points.size(); i++) {
            int cur_x = points[i][0], cur_y = points[i][1];
            int prev_x = points[i-1][0], prev_y = points[i-1][1];
            int diff_x = abs(cur_x - prev_x), diff_y = abs(cur_y - prev_y);

            res += max(diff_x, diff_y);
        }
        
        return res;
    }
};

int main() {
    vector<vector<vector<int>>> inputs = {
        {{1,1}, {3,4}, {-1,0}}, {{3,2}, {-2,2}}
    }; // 7 5

    Solution ans;
    for (auto& x : inputs) {
        int res = ans.minTimeToVisitAllPoints(x);
        print_res(res);
    }
    
    return 0;
}