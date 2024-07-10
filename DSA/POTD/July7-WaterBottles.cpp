#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if (numExchange > numBottles) {
            return numBottles;
        }
        int sum = numBottles;
        while (numBottles >= numExchange) {
            int Emptybottles = numBottles / numExchange;
            sum += Emptybottles;
            numBottles = Emptybottles + (numBottles % numExchange);
        }
        return sum;
    }
};

int main() {
    int numBottles, numExchange;

    // Example input
    cout << "Enter the number of water bottles: ";
    cin >> numBottles;
    cout << "Enter the number of bottles needed to exchange for one full bottle: ";
    cin >> numExchange;

    // Create an instance of Solution
    Solution solution;

    // Call numWaterBottles method
    int result = solution.numWaterBottles(numBottles, numExchange);

    // Print the result
    cout << "The maximum number of water bottles that can be drunk: " << result << endl;

    return 0;
}
