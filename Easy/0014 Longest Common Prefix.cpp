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

// max, min O(n) O(n)
class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string mn = *std::min_element(strs.begin(), strs.end());
        string mx = *std::max_element(strs.begin(), strs.end());
        string res = "";

        for (int i = 0; i < mn.size(); i++) {
            if (mn[i] == mx[i])
                res += mn[i];
            else
                return res;
        }
        return res;
    }
};


// sort O(nlogn) O(n)
class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string mn = strs[0], mx = strs[n-1], res = "";

        for (int i = 0; i < mn.size(); i++) {
            if (mn[i] == mx[i])
                res += mn[i];
            else
                return res;
        }
        return res;
    }
};

int main() {
    Solution1 ans;
    vector<vector<string>> inputs = {{"flower", "flow", "flight"}, {"dog", "racecar", "car"}}; // "fl", ""

    for (auto x: inputs) {
        string res = ans.longestCommonPrefix(x);
        print_res(res);
    } 

    return 0;
}