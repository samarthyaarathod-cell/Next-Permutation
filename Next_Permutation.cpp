#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find first decreasing element
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // Step 2: If found, find just larger element
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the remaining part
    reverse(nums.begin() + i + 1, nums.end());
}

// Driver code
int main() {
    vector<int> nums1 = {1,2,3};
    nextPermutation(nums1);

    cout << "Output: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {3,2,1};
    nextPermutation(nums2);

    cout << "Output: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;

    vector<int> nums3 = {1,1,5};
    nextPermutation(nums3);

    cout << "Output: ";
    for (int x : nums3) cout << x << " ";
    cout << endl;

    return 0;
}