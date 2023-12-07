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
    string largestOddNumber(string num) {
        int n = num.size();
        if ((num[n-1] - '0') & 1)
          return num;
        
        for (int i = n-2; i >= 0; i--) {
          if ((num[i] - '0') & 1)
            return num.substr(0, i+1);
        }

        return "";
    }
};


int main() {
    vector<string> inputs = {
        "52","4206","35427"
    }; // "5" "" "35427"

    Solution ans;
    for (auto& x : inputs) {
        string res = ans.largestOddNumber(x);
        print_res(res);
    }
    return 0;
}