#include <iostream>
#include <vector>
#include <string>
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

// math O(n)
class Solution1 {
public:
    bool isPalindrome(int x) {
        if ((x < 0) or (x > 0 and x % 10 == 0))
            return false;

        long newnum = 0, temp = x;

        while (x > 0) {
            newnum = newnum * 10 + x % 10;
            x = x / 10;
        }
        return (temp == newnum);
    }
};

// string
class Solution2 {
public:
    bool isPalindrome(int x) {
        if ((x < 0) or (x > 0 and x % 10 == 0))
            return false;

        string strx = to_string(x);
        string strx2 = string(strx.rbegin(), strx.rend());
        return strx == strx2;
    }
};

int main() {
    Solution1 ans1;
    Solution2 ans2;
    vector<int> inputs = {121, -121, 10}; // T, F, F

    for (auto x: inputs) {
        bool res = ans2.isPalindrome(x);
        print_res(res);
    } 

    return 0;
}