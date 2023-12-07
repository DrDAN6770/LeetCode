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

// O(n) O(1)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "";
        string b = "";
        for (auto& w : word1) {
          a += w;
        }

        for (auto& w : word2) {
          b += w;
        }
        return a == b;
    }
};


int main() {
    vector<pair<vector<string>, vector<string>>> inputs = {
        {{"a", "cb"}, {"ab", "c"}}, {{"abc", "d", "defg"}, {"abcddefg"}}
    }; // 0 1

    Solution ans;
    for (auto& x : inputs) {
        int res = ans.arrayStringsAreEqual(x.first, x.second);
        print_res(res);
    }
    return 0;
}