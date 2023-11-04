#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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

// hash, math O(n) O(n)
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman {
            {'I', 1},  {'V', 5},  {'X', 10},  {'L', 50},  {'C', 100},  {'D', 500},  {'M', 1000}
        };

        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (roman[s[i]] >= roman[s[i + 1]])
                res += roman[s[i]];
            else
                res -= roman[s[i]];
        }
    return res;
    }
};

int main() {
    Solution ans;
    vector<string> inputs = {"III", "LVIII", "MCMXCIV"};    //3 58 1994

    for (auto x: inputs) {
        int res = ans.romanToInt(x);
        print_res(res);
    } 

    return 0;
}