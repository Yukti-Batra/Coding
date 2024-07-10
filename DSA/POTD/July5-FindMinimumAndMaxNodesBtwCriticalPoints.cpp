#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        int count = 1;
        vector<int> Freq;
        while (fast && fast->next) {
            if ((fast->val < slow->val && fast->next->val > fast->val) || 
                (fast->val > slow->val && fast->next->val < fast->val)) {
                Freq.push_back(count);
            }
            count++;
            slow = slow->next;
            fast = fast->next;
        }
        if (Freq.size() < 2) {
            return {-1, -1};
        }
        int maximum = Freq.back() - Freq[0];
        int minimum = Freq[1] - Freq[0];
        for (int i = 1; i < Freq.size() - 1; i++) {
            int diff = Freq[i + 1] - Freq[i];
            minimum = min(diff, minimum);
        }
        return {minimum, maximum};
    }
};

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Input list
    vector<int> values = {2, 3, 1, 5, 4, 6, 3}; // Example input

    // Create the linked list
    ListNode* head = createList(values);

    // Create an instance of Solution
    Solution solution;

    // Call nodesBetweenCriticalPoints method
    vector<int> result = solution.nodesBetweenCriticalPoints(head);

    // Print the result
    cout << "Nodes between critical points: ";
    printVector(result);

    // Clean up the allocated memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
