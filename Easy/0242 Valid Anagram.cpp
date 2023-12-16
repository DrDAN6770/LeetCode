#include <iostream>
#include <vector>
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

    else if constexpr (is_same_v<T, vector<vector<int>>>) {
        for (auto x : input)
            for (auto y : x)
                cout << y << " ";
        cout << endl;
    }
}

// O(n) O(n) Array
class Solution0 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return 0;
        
        int cnt[26] = {0};

        for (char c : s)
            cnt[c - 'a']++;
        for (char c : t)
            cnt[c - 'a']--;

        for (const int x : cnt)
            if (x != 0)
                return false;

        return true;
    }
};

// O(n) O(n) Vector
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return 0;
        
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;
        for (char c : t)
            cnt[c - 'a']--;

        for (const int x : cnt)
            if (x != 0)
                return false;

        return true;
    }
};

// O(n) O(n) Hashmap
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> counter_s, counter_t;
        if (s.size() != t.size())
            return 0;
        
        for (char c : s)
            counter_s[c]++;
        for (char c : t)
            counter_t[c]++;

        return counter_s == counter_t;
    }
};


int main() {
    vector<pair<string, string>> inputs = {
        {"anagram","nagaram"}, {"rat","car"}
    };
    // true
    // false

    Solution0 ans;
    for (auto& [x, y] : inputs) {
        bool res = ans.isAnagram(x, y);
        print_res(res);
    }
    return 0;
}