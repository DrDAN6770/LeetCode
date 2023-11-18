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

// sort, slide window O(nlogn) O(logn)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        long res = 0;
        long window_sum = 0;
        long window_size = 0;
        
        for (int r = 0; r < n; r++) {
            window_sum += nums[r];
            window_size = r - l + 1;
            while (nums[r] * window_size - window_sum > k) {
                window_sum -= nums[l++];
                window_size--;
            }
            res = max(res, window_size);
        }
        return res;            
    }
};


int main() {
    vector<pair<vector<int>, int>> inputs = {{{1,2,4}, 5}, {{1,4,8,13}, 5}, {{3,9,6}, 2}}; // 3 2 1
    Solution ans;
    for (auto& x : inputs) {
        int res = ans.maxFrequency(x.first, x.second);
        print_res(res);
    }
    
    return 0;
}