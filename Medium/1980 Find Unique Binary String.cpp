#include <iostream>
#include <vector>
#include <unordered_set>
#include <bitset>
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

class Solution1 {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> seen;
        int n = nums.size();

        for (auto& num : nums)
            seen.insert(stoi(num, 0, 2));

        int res = stoi(nums[0], 0, 2);
        while (seen.find(res) != seen.end())
           res = rand() % (int)(pow(2, n) - 1);

        
        bitset<16> bit_str(res);
        string ans = bit_str.to_string();
        return ans.substr(16-n);
    }
};

class Solution2 {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> seen;
        int n = nums.size();

        for (auto& num : nums)
            seen.insert(stoi(num, 0, 2));

        for (int i = 0; i <= n; i++) {
            if (seen.find(i) == seen.end()) {
                bitset<16> bit_str(i);
                string res = bit_str.to_string();
                return res.substr(16-n);
            }
        }
        return "";
    }
};

int main() {
    vector<vector<string>> inputs = {{"01", "10"}, {"0000", "1111", "0110", "1100"}}; // 00 0011
    Solution1 ans;
    for (auto& x : inputs) {
        string res = ans.findDifferentBinaryString(x);
        print_res(res);
    }
    
    return 0;
}