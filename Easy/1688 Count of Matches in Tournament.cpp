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

// O(1) O(1)
class Solution1 {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};

// iterative O(logn) O(1)
class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while (n > 1) {
            res += n/2;
            n = (n-1) / 2 + 1;
        }
        return res;
    }
};

// recursion O(logn) O(logn)
class Solution {
public:
    int numberOfMatches(int n) {
        if (n == 1)
            return 0;
        return n/2 + numberOfMatches((n+1) / 2);
    }
};


int main() {
    vector<int> inputs = {
        7, 6, 1
    }; // 6,5,0

    Solution1 ans;
    for (auto& x : inputs) {
        int res = ans.numberOfMatches(x);
        print_res(res);
    }
    return 0;
}