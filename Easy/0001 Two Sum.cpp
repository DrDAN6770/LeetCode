#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// hash, O(n) O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> res;

        for(int i = 0; i < nums.size(); i++) {
            int c = target - nums[i];
            if (res.count(c))
                return {res[c], i};
            res[nums[i]] = i;
        }
        return {};
    }
};

template <typename T>
void print_res(const T& input) {
    if constexpr (is_same_v<T, int> || is_same_v<T, long> || is_same_v<T, long long> ||
                  is_same_v<T, bool> || is_same_v<T, float> || is_same_v<T, double>)
        cout << input << endl;

    else if constexpr (is_same_v<T, vector<int>>) {
        for (auto x : input)
            cout << x << " ";
        cout << endl;
    }
}

int main() {
    Solution ans;

    vector<int> nums1 = {2,7,11,15};
    vector<int> nums2 = {3,2,4};
    int target1 = 9;
    int target2 = 6;

    vector<int> res1 = ans.twoSum(nums1, target1); // 0 1
    vector<int> res2 = ans.twoSum(nums2, target2); // 1 2
    print_res(res1);
    print_res(res2);
    return 0;
}