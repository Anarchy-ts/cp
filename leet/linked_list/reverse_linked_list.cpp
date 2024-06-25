#include <bits/stdc++.h>
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        
        while (current != nullptr) {
            ListNode* next = current->next; // Save next
            current->next = prev;           // Reverse current node's pointer
            prev = current;                 // Move prev to this node
            current = next;                 // Move to next node
        }
        
        return prev;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& vals) {
    ListNode dummy;
    ListNode* curr = &dummy;
    for (int val : vals) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return dummy.next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        head = head->next;
        if (head != nullptr) {
            cout << " -> ";
        }
    }
    cout << endl;
}

int main() {
    // Example 1
    vector<int> vals1 = {1, 2, 3, 4, 5};
    ListNode* list1 = createList(vals1);
    
    Solution solution;
    ListNode* result1 = solution.reverseList(list1);
    
    // Output the result
    printList(result1); // Expected output: 5 -> 4 -> 3 -> 2 -> 1
    
    // Example 2
    vector<int> vals2 = {1, 2};
    ListNode* list2 = createList(vals2);
    
    ListNode* result2 = solution.reverseList(list2);
    
    // Output the result
    printList(result2); // Expected output: 2 -> 1
    
    // Example 3
    vector<int> vals3 = {};
    ListNode* list3 = createList(vals3);
    
    ListNode* result3 = solution.reverseList(list3);
    
    // Output the result
    printList(result3); // Expected output: (empty list)
    
    return 0;
}
