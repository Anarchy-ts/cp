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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; // Dummy head to simplify the code
        ListNode* tail = &dummy;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // If one of the lists is not empty, append it
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
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
    vector<int> vals1 = {1, 2, 4};
    vector<int> vals2 = {1, 3, 4};
    
    ListNode* list1 = createList(vals1);
    ListNode* list2 = createList(vals2);
    
    Solution solution;
    ListNode* result = solution.mergeTwoLists(list1, list2);
    
    // Output the result
    printList(result); // Expected output: 1 -> 1 -> 2 -> 3 -> 4 -> 4
    
    // Example 2
    list1 = nullptr;
    list2 = nullptr;
    
    result = solution.mergeTwoLists(list1, list2);
    
    // Output the result
    printList(result); // Expected output: (empty list)
    
    // Example 3
    list1 = nullptr;
    vector<int> vals3 = {0};
    list2 = createList(vals3);
    
    result = solution.mergeTwoLists(list1, list2);
    
    // Output the result
    printList(result); // Expected output: 0
    
    return 0;
}
