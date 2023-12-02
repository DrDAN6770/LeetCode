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

// insert O(n) O(n)
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> res = {nums.end() - k, nums.end()};
        res.insert(res.end(), nums.begin(), nums.end() - k);
        nums = res;

        for (auto& x:nums)
            cout << x << " ";
        cout << endl;
    }
};

// reverse O(n) O(n)
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.begin() + k);
    }
};

// reverse O(n) O(n)
class Solution3 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> tmp(n);

        for (int i = 0; i < n; i++)
           tmp[(i+k)%n] = nums[i];
        nums = tmp;
    }
};
// O(n) O(n)

int main() {
    vector<pair<vector<int>, int>> inputs = {
        {{1,2,3,4,5,6,7}, 3}, {{-1,-100,3,99}, 2}
    }; // 5 6 7 1 2 3 4, 3 99 -1 -100

    Solution1 ans;
    for (auto& x : inputs) {
        ans.rotate(x.first, x.second);
        // print_res(res);
    }
    
    return 0;
}