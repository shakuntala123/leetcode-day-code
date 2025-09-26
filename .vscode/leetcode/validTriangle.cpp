#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 2; i < n; i++) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    ans += r - l; // all pairs between l and r-1 work
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};

int main() {
    // Example input
    vector<int> nums = {2, 2, 3, 4};

    Solution obj;
    int result = obj.triangleNumber(nums);

    cout << "Number of valid triangles: " << result << endl;

    return 0;
}
