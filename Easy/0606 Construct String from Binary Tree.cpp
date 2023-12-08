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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// iter O(n) O(n)
class Solution {
public:
    string tree2str(TreeNode* root) {
        string res = "";

        if(!root)
            return res;

        stack<TreeNode*> st;
        res += to_string(root->val);
        
        if(!root->left && root->right)
            res += "()";

        if(root->right)
            st.push(root->right);
        if(root->left)
            st.push(root->left);

        while (!st.empty()) {
            root = st.top();
            st.pop();

            if (root) {
                res += "(" + to_string(root->val);
                if(!root->left && root->right)
                    res += "()";

                st.push(NULL);

                if(root->right)
                    st.push(root->right);

                if(root->left)
                    st.push(root->left);
            }
            else
                res += ")";
        }
        return res;
    }
};


// recur O(n) O(n)
class Solution {
public:
    void preorder(TreeNode* root, string& res) {
        if (!root)
            return;
        res += to_string(root->val);
        if (root->left or root->right) {
            res += '(';
            preorder(root->left, res);
            res += ')';
        }

        if (root->right) {
            res += '(';
            preorder(root->right, res);
            res += ')';
        }
    }
    string tree2str(TreeNode* root) {
        string res = "";
        preorder(root, res);
        return res;
    }
};

// recur O(n) O(n)
class Solution {
public:
    string tree2str(TreeNode* root) {
        string res = "";
        if (!root)
            return res;

        res += to_string(root->val);
        if (root->left and !root->right) {
            res += "(" + tree2str(root->left) + ")";
        }
        if (root->right){
            res += "(" + tree2str(root->left) + ")";
            res += "(" + tree2str(root->right) + ")";
        }
           
        return res;
    }
};

int main() {
    // vector<int> inputs = {
    //     4, 10, 21, 100
    // }; // 10 37 105 1060

    // Solution ans;
    // for (auto& x : inputs) {
    //     int res = ans.tree2str(x);
    //     print_res(res);
    // }
    return 0;
}