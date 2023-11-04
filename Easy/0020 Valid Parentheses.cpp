#include <iostream>
#include <vector>
#include <stack>
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

// stack O(n) O(n)
class Solution {
public:
    bool isValid(string s) {
        // size is odd
        if (s.size() & 1)
            return false;
        
        stack<char> st;

        for (auto c : s) {
            if (c == '(' or c == '[' or c == '{')
                st.push(c);
            else {
                if (st.empty())
                    return false;
                if (c == ')' and st.top() == '(')
                    st.pop();
                else if (c == ']' and st.top() == '[')
                    st.pop();
                else if (c == '}' and st.top() == '{')
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty();
    }
};

int main() {
    Solution ans;
    vector<string> inputs = {"()[]{}","([}}])", "){"}; // T F F

    for (auto x: inputs) {
        bool res = ans.isValid(x);
        print_res(res);
    } 

    return 0;
}