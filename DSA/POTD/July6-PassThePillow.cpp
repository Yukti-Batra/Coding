#include <iostream>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int moves = n - 1;
        if (time == n) {
            return n - 1;
        }
        if (time < n) {
            return time + 1;
        }
        if (time > n) {
            int rem = time % moves;
            int side = time / moves;
            if (side % 2 == 0) {
                return 1 + rem;
            } else {
                return n - rem;
            }
        }
        return 0;
    }
};

int main() {
    int n, time;

    // Example input
    cout << "Enter the number of players (n): ";
    cin >> n;
    cout << "Enter the time: ";
    cin >> time;

    // Create an instance of Solution
    Solution solution;

    // Call passThePillow method
    int result = solution.passThePillow(n, time);

    // Print the result
    cout << "The player holding the pillow after " << time << " seconds is: " << result << endl;

    return 0;
}
