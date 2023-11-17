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

// O(n2) O(1)
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int res = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
                    res = max(res, nums[i] ^ nums[j]);
        return res;
    }
};
// or
// for (auto& num1 : nums)
//     for (auto& num2 : nums)
//         if (abs(num1 - num2) <= min(num1, num2))
//             res = max(res, num1 ^ num2);


int main() {
    vector<vector<int>> inputs = {{1,2,3,4,5}, {10,100}, {5,6,25,30}}; // 7 0 7
    Solution ans;
    for (auto& x : inputs) {
        int res = ans.maximumStrongPairXor(x);
        print_res(res);
    }
    
    return 0;
}