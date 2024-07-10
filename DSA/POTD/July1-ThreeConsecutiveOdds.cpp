#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }

        for (int i = 0; i <= arr.size() - 3; i++) {
            if (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Input vector
    vector<int> arr = {2, 6, 4, 1, 3, 5, 7};

    // Create an instance of Solution
    Solution solution;

    // Call threeConsecutiveOdds method
    bool result = solution.threeConsecutiveOdds(arr);

    // Output the result
    if (result) {
        cout << "The array contains three consecutive odd numbers." << endl;
    } else {
        cout << "The array does not contain three consecutive odd numbers." << endl;
    }

    return 0;
}
