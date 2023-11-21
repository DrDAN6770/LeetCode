#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

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

// O(n) O(n) hash
class Solution1 {
public:
    int rev(int num) {
        int res = 0;
        while (num != 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        int res = 0;
        int modulo = pow(10, 9) + 7;
        unordered_map<int, int> freq;

        for (auto& num : nums) {
            int tmp = num - rev(num);
            res = (res + freq[tmp]++) % modulo;
        }

        return res;
    }
};


// O(n) O(n) hash + arr
class Solution2 {
public:
    int rev(int num) {
        int res = 0;
        while (num != 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int modulo = pow(10, 9) + 7;
        int arr[n];
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++)
            arr[i] = nums[i] - rev(nums[i]);
   
        for (auto& val : arr) {
            res = (res + freq[val]++) % modulo;
        }

        return res;
    }
};

int main() {
    vector<vector<int>> inputs = {{42,11,1,97}, {13,10,35,24,76}}; // 2 4
    Solution1 ans;
    for (auto& x : inputs) {
        int res = ans.countNicePairs(x);
        print_res(res);
    }
    
    return 0;
}