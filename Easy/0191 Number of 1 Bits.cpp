#include <iostream>
#include <vector>
#include <cstdint>

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
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0) {
            n &= (n-1);
            res++;
        }
        return res;
    }
};


int main() {
    vector<uint32_t> inputs = {
        0b00000000000000000000000000001011, 0b00000000000000000000000010000000, 0b11111111111111111111111111111101
    }; // 3 1 31

    Solution ans;
    for (auto& x : inputs) {
        int res = ans.hammingWeight(x);
        print_res(res);
    }
    
    return 0;
}