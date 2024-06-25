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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        // Calculate the length of the linked list
        int length = 0;
        while (curr) {
            length++;
            curr = curr->next;
        }
        
        curr = head;
        
        // Iterate over the list and reverse every k-group
        for (int i = 0; i < length / k; ++i) {
            for (int j = 1; j < k; ++j) {
                next = curr->next;
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            prev = curr;
            curr = prev->next;
        }
        
        return dummy.next;
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
    ListNode* result1 = solution.reverseKGroup(list1, 2);
    
    // Output the result
    printList(result1); // Expected output: 2 -> 1 -> 4 -> 3 -> 5
    
    // Example 2
    vector<int> vals2 = {1, 2, 3, 4, 5};
    ListNode* list2 = createList(vals2);
    
    ListNode* result2 = solution.reverseKGroup(list2, 3);
    
    // Output the result
    printList(result2); // Expected output: 3 -> 2 -> 1 -> 4 -> 5
    
    return 0;
}
