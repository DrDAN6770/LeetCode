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
}

// O(n*k) O(1) k : longest string + hash
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char, int> ump;
        int garbage_cnt = 0;
        int n = garbage.size();
        int res = 0;


        for (int i = 0; i < n; i++) {
            for (auto& c : garbage[i]) {
                ump[c] = i;
                garbage_cnt++;
            }
        }

        for (int i = 1; i < travel.size(); i++)
            travel[i] += travel[i-1];
        
        res += ump['M'] == 0 ? 0 : travel[ump['M']-1];
        res += ump['P'] == 0 ? 0 : travel[ump['P']-1];
        res += ump['G'] == 0 ? 0 : travel[ump['G']-1];
        res += garbage_cnt;

        return res;
    }
};

int main() {
    vector<pair<vector<string>, vector<int>>> inputs = {{{"G","P","GP","GG"}, {2,4,3}}, {{"MMM","PGM","GP"}, {3,10}}}; // 21 37
    Solution ans;
    for (auto& x : inputs) {
        int res = ans.garbageCollection(x.first, x.second);
        print_res(res);
    }
    
    return 0;
}