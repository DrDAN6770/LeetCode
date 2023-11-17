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

// O(n) O(n)
class Solution1 {
public:
    int minPairSum(vector<int>& nums) {
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        int res = INT_MIN;
        vector<int> count_table(100001, 0);
        // or unordered_map<int, int> count_table;

        // find max & min & count table
        for (auto& num : nums) {
            count_table[num]++;
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }

        int l = min_val, r = max_val;
        while (l <= r) {
            if (count_table[l] == 0)
                l++;
            else if (count_table[r] == 0)
                r--;
            else {
                res = max(res, l + r);
                count_table[l]--;
                count_table[r]--;
            }
        }
        return res;
    }
};

// O(nlogn) O(1)
class Solution2 {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int res = INT_MIN;
        while (l < r) {
            res = max(res, nums[l++] + nums[r--]);
        }
        return res;
    }
};


int main() {
    vector<vector<int>> inputs = {{3,5,2,3}, {3,5,4,2,4,6}}; // 7 8
    Solution1 ans;
    for (auto& x : inputs) {
        int res = ans.minPairSum(x);
        print_res(res);
    }
    
    return 0;
}