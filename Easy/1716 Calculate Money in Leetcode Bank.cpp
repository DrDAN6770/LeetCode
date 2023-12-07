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
class Solution {
public:
    int totalMoney(int n) {
        int count = n / 7;
        int weekmore = 7 * count * (count - 1) / 2;
        int total = 28 * count + weekmore;

        n %= 7;
        
        while (n > 0)
          total += (n-- + count);

        return total;
    }
};


int main() {
    vector<int> inputs = {
        4, 10, 21, 100
    }; // 10 37 105 1060

    Solution ans;
    for (auto& x : inputs) {
        int res = ans.totalMoney(x);
        print_res(res);
    }
    return 0;
}