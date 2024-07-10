#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i] == "./") {
                // Do nothing
            } else if (logs[i] == "../") {
                count--;
            } else {
                count++;
            }
            cout << count << " ";
            if (count < 0) {
                count = 0;
            }
        }
        return count;
    }
};

int main() {
    int n;
    cout << "Enter the number of log entries: ";
    cin >> n;

    vector<string> logs(n);
    cout << "Enter the log entries:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> logs[i];
    }

    // Create an instance of Solution
    Solution solution;

    // Call minOperations method
    int result = solution.minOperations(logs);

    // Print the result
    cout << "\nThe minimum operations needed to go back to the main folder: " << result << endl;

    return 0;
}
