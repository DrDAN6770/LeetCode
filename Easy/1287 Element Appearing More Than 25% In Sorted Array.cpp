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

// O(n) O(1) Math
class Solution0 {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int threshold = n / 4;

        for (int i = 0; i < n - threshold; i++) {          
            if (arr[i] == arr[i + threshold])
                return arr[i];
        }

        return -1;
    }
};

// O(n) O(1)
class Solution1 {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int threshold = n / 4;
        int pre = arr[0];
        int cnt = 1;

        for (int i = 1; i < n; i++) {
            cnt = pre == arr[i] ? cnt+1 : 1;
            
            if (cnt > threshold)
                return arr[i];
            
            pre = arr[i];
        }

        return pre;
    }
};

// O(n) O(n)
class Solution2 {
public:
    int findSpecialInteger(vector<int>& arr) {
        int mxcnt = 0;
        unordered_map<int, int> ump;

        for (auto& num : arr) {
            mxcnt = max(mxcnt, ++ump[num]);
        }

        for (auto& [x, y] : ump) {
            if (y == mxcnt)
                return x;
        }

        return 0;
    }
};


int main() {
    vector<vector<int>> inputs = {
        {1,2,2,6,6,6,6,7,10}, {100}
    }; // 6 100

    Solution0 ans;
    for (auto& x : inputs) {
        int res = ans.findSpecialInteger(x);
        print_res(res);
    }
    return 0;
}