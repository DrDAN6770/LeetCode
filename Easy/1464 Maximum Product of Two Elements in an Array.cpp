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

// O(n) O(1) Math
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1 = 0;
        int mx2 = 0;
        int n = nums.size();

        for (auto& num : nums) {
            if (num > mx1) {
                mx2 = mx1;
                mx1 = num;
            }
            else if (num > mx2)
                mx2 = num;
        }

        return (mx1 - 1) * (mx2 - 1);
    }
};

// O(nlogn) O(logn) sort
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        // expand = i*j - (i+j) + 1
        int n = nums.size();
        sort(nums.begin(), nums.end());

        return nums[n-1] * nums[n-2] - nums[n-1] - nums[n-2] + 1;
    }
};


int main() {
    vector<vector<int>> inputs = {
        {1,2,2,6,6,6,6,7,10}, {1,5,4,5}
    }; // 54 16

    Solution ans;
    for (auto& x : inputs) {
        int res = ans.maxProduct(x);
        print_res(res);
    }
    return 0;
}