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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        // Move `prev` to the node just before the left-th node
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // `start` will point to the left-th node, which will be the tail after reversing
        ListNode* start = prev->next;
        ListNode* then = start->next;

        // Reverse the sublist from left to right
        for (int i = 0; i < right - left; ++i) {
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
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
    ListNode* result1 = solution.reverseBetween(list1, 2, 4);
    
    // Output the result
    printList(result1); // Expected output: 1 -> 4 -> 3 -> 2 -> 5
    
    // Example 2
    vector<int> vals2 = {5};
    ListNode* list2 = createList(vals2);
    
    ListNode* result2 = solution.reverseBetween(list2, 1, 1);
    
    // Output the result
    printList(result2); // Expected output: 5
    
    return 0;
}
