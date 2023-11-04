#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2pointer O(n) O(1)
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        // not find
        if (find(nums.begin(), nums.end(), val) == nums.end())
            return nums.size();

        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (val != nums[i])
                nums[k++] = nums[i];
        }
                    
        return k;
    }
};

// erase remove O(n2) O(1)
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        // not find
        if (find(nums.begin(), nums.end(), val) == nums.end())
            return nums.size();

        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
                    
        return nums.size();
    }
};

int main() {
    Solution1 ans1;
    Solution2 ans2;

    vector<int> nums1 = {3,2,2,3};
    vector<int> nums2 = {3,2,2,3};
    int val = 3;

    int res1 = ans1.removeElement(nums1, val);
    int res2 = ans2.removeElement(nums2, val);

    cout << res1 << endl;
    cout << res2 << endl;

    return 0;
}