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

// O(n) O(1) Greedy
class Solution0 {
public:
    int maxProductDifference(vector<int>& nums) {
        int mx1 = INT_MIN, mx2 = INT_MIN;
        int mn1 = INT_MAX, mn2 = INT_MAX;

        for (auto& num : nums) {
            if (num > mx1) {
                mx2 = mx1;
                mx1 = num;
            }
            else if (num > mx2) {
                mx2 = num;
            }

            if (num < mn1) {
                mn2 = mn1;
                mn1 = num;
            }
            else if (num < mn2) {
                mn2 = num;
            }
        }
        
        return mx1 * mx2 - mn1 * mn2;
    }
};

// O(nlogn) O(logn) sort
class Solution1 {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-1] * nums[n-2] - nums[0] * nums[1];
    }
};


int main() {
    vector<vector<int>> inputs = {
        {5,6,2,7,4}, {4,2,5,9,7,4,8}
    };
    // 36
    // 64

    Solution0 ans;
    for (auto& x : inputs) {
        int res = ans.maxProductDifference(x);
        print_res(res);
    }
    return 0;
}