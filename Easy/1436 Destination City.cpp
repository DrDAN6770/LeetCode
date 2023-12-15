#include <iostream>
#include <vector>
#include <unordered_set>
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

// O(n) O(n) set
class Solution0 {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_set<string> ust;

        for (int i = 0; i < n; i++)
            ust.insert(paths[i][0]);

        for (int i = 0; i < n; i++) {
            string res = paths[i][1];
            if (ust.find(res) == ust.end())
                return res;
        }
        return "";
    }
};

// O(n) O(n) hash
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_map<string, string> ump;

        for (int i = 0; i < n; i++)
            ump[paths[i][0]] = paths[i][1];

        for (auto& [key, val] : ump) {
            if (ump.count(val) <= 0)
                return val;
        }
        return "";
    }
};

int main() {
    vector<vector<vector<string>>> inputs = {
        {{"London","New York"}, {"New York","Lima"}, {"Lima","Sao Paulo"}},
        {{"B","C"}, {"D","B"}, {"C","A"}}
    };
    // Sao Paulo
    // A

    Solution0 ans;
    for (auto& x : inputs) {
        string res = ans.destCity(x);
        print_res(res);
    }
    return 0;
}