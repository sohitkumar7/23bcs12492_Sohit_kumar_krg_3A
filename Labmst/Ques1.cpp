#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            int count = 0;

            for (int num : nums) {
                if (num & (1 << i)) {
                    count++;
                }
            }

            if (count % 3 != 0) {
                ans |= (1 << i);
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int result = obj.singleNumber(nums);

    cout << "Single Number: " << result << endl;

    return 0;
}