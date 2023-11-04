#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// create linked-list
ListNode* create(const vector<int>& input) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;

    for (int val : input) {
        current->next = new ListNode(val);
        current = current->next;
    }

    return dummy->next;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr = new ListNode();
        ListNode* res = curr;

        while (list1 and list2) {
            if (list1->val < list2->val) {
                curr->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else {
                curr->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // 剩餘尚未排列的
        if (list1)
            curr->next = list1;
        if (list2)
            curr->next = list2;

        return res->next;
    }
};

int main() {
    Solution ans;
    vector<int> nums1 = {1,2,4};
    vector<int> nums2 = {1,3,5,6,7,8,9};
    ListNode* list1 = create(nums1);
    ListNode* list2 = create(nums2);

    ListNode* res = ans.mergeTwoLists(list1, list2); // 1 1 2 3 4 5 6 7 8 9
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}