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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        
        while (head) {
            // Check if the current node is a duplicate
            if (head->next && head->val == head->next->val) {
                // Skip all nodes with the same value
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                // Skip the last duplicate node
                prev->next = head->next;
            } else {
                // No duplicate, move prev
                prev = prev->next;
            }
            head = head->next;
        }
        
        return dummy.next;
    }
    ListNode* deleteRepeats(ListNode* head) {
        if (!head) return nullptr;
        
        ListNode* current = head;
        
        while (current && current->next) {
            if (current->val == current->next->val) {
                // Skip the next node since it's a duplicate
                current->next = current->next->next;
            } else {
                // Move to the next node
                current = current->next;
            }
        }
        
        return head;
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
    vector<int> vals1 = {1, 2, 3, 3, 4, 4, 5};
    ListNode* list1 = createList(vals1);
    
    Solution solution;
    ListNode* result1 = solution.deleteDuplicates(list1);
    
    // Output the result
    printList(result1); // Expected output: 1 -> 2 -> 5
    
    // Example 2
    vector<int> vals2 = {1, 1, 1, 2, 3};
    ListNode* list2 = createList(vals2);
    
    ListNode* result2 = solution.deleteDuplicates(list2);
    
    // Output the result
    printList(result2); // Expected output: 2 -> 3
    
    return 0;
}