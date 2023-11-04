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

// sliding winodw O(m+n) O(1)
class Solution1 {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        int i = 0, j = 0;

        while (i < n) {
            if (haystack[i] == needle[j])
                j++;

            else {
                i -= j;
                j = 0;
            }

            if (j == m)
                return i - j + 1;

            i++;
        }
        return -1;
    }
};

// 2pointer O(m*n) O(1)
class Solution2 {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size(), n = needle.size();
        for (int i = 0; i <= h-n; i++) {
            int j = 0;
            for (j; j < n; j++) {
                if (needle[j] != haystack[i+j])
                    break;
            }
            if (j == n)
                return i;
        }
        return -1;
    }
};

// substr, O(m*n) O(n)
class Solution3 {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size(), n = needle.size();
        for (int i = 0; i <= h-n; i++) {
            string s = haystack.substr(i, n);
            if (s == needle)
                return i;
        }
        return -1;
    }
};

// find(), O(m*n) O(1)
class Solution4 {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main() {
    vector<pair<string, string>> inputs = {{"sadbutsad", "sad"}, {"leetcode", "leeto"}, {"abcaadaaac", "aaa"}}; // 0 -1 6
    Solution1 ans;
    for (auto x : inputs) {
        int res = ans.strStr(x.first, x.second);
        print_res(res);
    }
    
    return 0;
}