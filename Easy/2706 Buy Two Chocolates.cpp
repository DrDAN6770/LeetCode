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

// O(n) O(1) greedy
class Solution0 {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mn1 = INT_MAX, mn2 = INT_MAX;

        for (auto& price : prices) {
            if (price < mn1) {
                mn2 = mn1;
                mn1 = price;
            }
            else if (price < mn2) {
                mn2 = price;
            }
        }

        if (mn1 + mn2 <= money)
            return money - mn1 - mn2;
        return money;
    }
};

// O(nlogn) O(logn) sort
class Solution1 {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());

        if (prices[0] >= money)
            return money;

        int mincost = prices[0] + prices[1];

        if (money >= mincost)
            return money - mincost;
        return money;
    }
};

int main() {
    vector<pair<vector<int>, int>> inputs = {
        {{3,2,3}, 3}, {{10,40,20,55,4,77}, 20}
    };
    // 3 6

    Solution0 ans;
    for (auto& [x, y] : inputs) {
        int res = ans.buyChoco(x, y);
        print_res(res);
    }
    return 0;
}