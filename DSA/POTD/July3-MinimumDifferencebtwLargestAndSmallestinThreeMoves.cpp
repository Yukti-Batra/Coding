#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        if (nums[0] == nums.back()) {
            return 0;
        }
        return min({nums[n-4] - nums[0], nums[n-1] - nums[3], nums[n-3] - nums[1], nums[n-2] - nums[2]});
    }
};

int main() {
    // Input vector
    vector<int> nums = {6, 6, 0, 1, 1, 4, 6};

    // Create an instance of Solution
    Solution solution;

    // Call minDifference method
    int result = solution.minDifference(nums);

    // Output the result
    cout << "The minimum difference after modifying the array is: " << result << endl;

    return 0;
}
