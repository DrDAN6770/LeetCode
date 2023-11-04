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

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast = 1;
        while (fast < nums.size()) {
            if (nums[slow] != nums[fast]) {
                nums[++slow] = nums[fast]; 
            }
            fast++;
        }
        return slow + 1;
    }
};

int main() {
    vector<vector<int>> inputs = {{1,1,2}, {0,0,1,1,1,2,2,3,3,4}}; // 2 5
    Solution ans;
    for (auto x : inputs) {
        int res = ans.removeDuplicates(x);
        print_res(res);
    }
    
    return 0;
}