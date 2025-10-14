/*
🧩 Problem Restatement

We are given:

an integer array nums of length n

an integer k

We must check whether there exist two adjacent subarrays of length k that are strictly increasing.

Formally:

Subarray 1: nums[a .. a+k-1]

Subarray 2: nums[a+k .. a+2k-1]
(because adjacency means b = a + k)

We want to return True if both subarrays are strictly increasing for any valid a.


💡 Approach
......................

Define a helper function is_increasing(start, end)
→ checks if nums[start..end] is strictly increasing.
→ runs in O(k).

Loop a from 0 to n - 2k (inclusive).
For each a, check:

nums[a .. a+k-1] is increasing

nums[a+k .. a+2k-1] is increasing

Return True if both are, otherwise after loop, False.


................................

⏱️ Time Complexity

O(n * k) worst-case (fine since n ≤ 100)
*/
 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        auto isIncreasing = [&](int start) {
            for (int i = start; i < start + k - 1; ++i) {
                if (nums[i] >= nums[i + 1]) return false;
            }
            return true;
        };

        for (int a = 0; a <= n - 2 * k; ++a) {
            if (isIncreasing(a) && isIncreasing(a + k)) {
                return true;
            }
        }

        return false; 
    }
};
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        auto isIncreasing = [&](int start) {
            for (int i = start; i < start + k - 1; ++i) {
                if (nums[i] >= nums[i + 1]) return false;
            }
            return true;
        };

        for (int a = 0; a <= n - 2 * k; ++a) {
            if (isIncreasing(a) && isIncreasing(a + k)) {
                return true;
            }
        }

        return false; 
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = {2,5,7,8,9,2,3,4,3,1};
    int k1 = 3;
    cout << (sol.hasIncreasingSubarrays(nums1, k1) ? "true" : "false") << endl;
    // Output: true

    vector<int> nums2 = {1,2,3,4,4,4,4,5,6,7};
    int k2 = 5;
    cout << (sol.hasIncreasingSubarrays(nums2, k2) ? "true" : "false") << endl;
    // Output: false
}