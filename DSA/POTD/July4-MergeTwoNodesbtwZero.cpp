#include <iostream>
#include<vector>
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* sum = new ListNode(0);  // Temporary node for summing values

        while (fast != nullptr && fast->next != nullptr) {
            if (fast->val != 0) {
                sum->val = sum->val + fast->val;
                fast = fast->next;
            } else {
                slow->val = sum->val;
                slow = slow->next;
                sum->val = 0;
                fast = fast->next;
            }
        }
        slow->val = sum->val;
        slow->next = nullptr;
        delete sum;
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
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
    vector<int> values = {0, 3, 1, 0, 4, 5, 2, 0}; // Example input

    // Create the linked list
    ListNode* head = createList(values);

    // Create an instance of Solution
    Solution solution;

    // Call mergeNodes method
    ListNode* result = solution.mergeNodes(head);

    // Print the result
    cout << "Merged nodes list: ";
    printList(result);

    // Clean up the allocated memory
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
