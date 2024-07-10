#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int j = 0;
        int timetaken = 0;
        int waitTime = 0;
        int temp = customers[0][0];
        double sum = 0;

        for (int i = 0; i < customers.size(); i++) {
            timetaken = customers[i][j] + customers[i][j + 1]; // arrival time + prep time
            waitTime = timetaken - temp; // timetaken - arrival time

            if (waitTime > 0) {
                sum += waitTime;
            } else {
                sum += customers[i][j + 1];
            }

            cout << "Time Taken: " << timetaken << " ";
            cout << "Wait Time: " << waitTime << " ";
            cout << "Sum: " << sum << " ";
            cout << endl;

            if ((i + 1) < customers.size()) {
                temp = customers[i + 1][j];
            } else {
                break;
            }

            if (temp <= timetaken) {
                customers[i + 1][j] = timetaken;
            }
        }
        int n = customers.size();
        sum = sum / n;
        return sum;
    }
};

int main() {
    int n;
    cout << "Enter the number of customers: ";
    cin >> n;

    vector<vector<int>> customers(n, vector<int>(2));
    cout << "Enter arrival time and preparation time for each customer:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> customers[i][0] >> customers[i][1];
    }

    // Create an instance of Solution
    Solution solution;

    // Call averageWaitingTime method
    double result = solution.averageWaitingTime(customers);

    // Print the result
    cout << "The average waiting time is: " << result << endl;

    return 0;
}
