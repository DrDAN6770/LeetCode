#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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

// O(nk) O(n)
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> counts(26, 0);
        int res = 0;

        for (auto& c: chars)
            counts[c - 'a']++;
        
        for (auto& word : words) {
            bool good = true;
            for (auto& c : word) {
                if (count(word.begin(), word.end(), c) > counts[c - 'a']) {
                    good = false;
                    break;
                }
            }
            if (good)
                res += word.size();
        }

        return res;
    }
};

// O(nk) O(n) + hash
class Solution1 {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> counts;
        int res = 0;

        for (auto& c: chars)
            counts[c]++;
        
        for (auto& word : words) {
            bool good = true;
            for (auto& c : word) {
                if (count(word.begin(), word.end(), c) > counts[c]) {
                    good = false;
                    break;
                }
            }
            if (good)
                res += word.size();
        }

        return res;
    }
};

int main() {
    vector<pair<vector<string>, string>> inputs = {
        {{"cat","bt","hat","tree"}, "atach"}, {{"hello","world","leetcode"}, {"welldonehoneyr"}}
    }; // 6 10

    Solution ans;
    for (auto& x : inputs) {
        int res = ans.countCharacters(x.first, x.second);
        print_res(res);
    }
    
    return 0;
}