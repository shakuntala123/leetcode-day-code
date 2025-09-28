// Minimum K Consecutive Bit Flips
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
      int n = arr.size();
      vector<int> isFlipped(n, 0);
      int flip = 0, count = 0;

      for (int i = 0; i < n; i++) {
        if (i >= k) flip ^= isFlipped[i - k]; // remove expired flip effect

        if ((arr[i] ^ flip) == 0) { // need to flip
            if (i + k > n) return -1;
            count++;
            flip ^= 1;
            isFlipped[i] = 1;
        }
    }
    return count;
}


};
int main() {
    // Example input
    vector<int> nums = {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1};
    int k=2;

    Solution obj;
    int result = obj.kBitFlips(nums,k);

    cout << " The minimum number of  operations required to make the entire array consist of only 1's : " << result << endl;

    return 0;
}