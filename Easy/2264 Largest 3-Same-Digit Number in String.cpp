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
    string largestGoodInteger(string num) {
        string res = "";
        for (int i = 0; i < num.size() - 2; i++) {
            if (num[i] == num[i+1] and num[i] == num[i+2]) {
                string tmp = string(1, num[i]) + num[i+1] + num[i+2];
                res = max(res, tmp);
            }
        }

        return res;
    }
};

int main() {
    vector<string> inputs = {
        {"6777133339"}, {"42352338"}
    }; // "777", ""

    Solution ans;
    for (auto& x : inputs) {
        string res = ans.largestGoodInteger(x);
        print_res(res);
    }
    
    return 0;
}