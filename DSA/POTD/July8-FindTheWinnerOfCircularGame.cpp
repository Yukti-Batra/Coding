#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            v.push_back(i + 1);
        }
        int index = 0;
        while (v.size() > 1) {
            index = (index + k - 1) % v.size();
            v.erase(v.begin() + index);
        }
        return v[0];
    }
};

int main() {
    int n, k;

    // Example input
    cout << "Enter the number of friends (n): ";
    cin >> n;
    cout << "Enter the step count (k): ";
    cin >> k;

    // Create an instance of Solution
    Solution solution;

    // Call findTheWinner method
    int result = solution.findTheWinner(n, k);

    // Print the result
    cout << "The winner is friend number: " << result << endl;

    return 0;
}
