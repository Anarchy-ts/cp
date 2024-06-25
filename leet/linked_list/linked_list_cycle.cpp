#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return false;

        ListNode* slow=head;
        ListNode* fast=head->next->next;

        while(slow!=fast){
            if(fast==nullptr || fast->next==nullptr) return false;
            slow=slow->next;
            fast=fast->next->next;
        }
        return true;
    }
};

int main() {
    // Example 1: [3, 2, 0, -4], pos = 1
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // create cycle

    std::cout << "Example 1: " << (Solution().hasCycle(head) ? "True" : "False") << std::endl;

    // Example 2: [1, 2], pos = 0
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = head2; // create cycle

    std::cout << "Example 2: " << (Solution().hasCycle(head2) ? "True" : "False") << std::endl;

    // Example 3: [1], pos = -1
    ListNode *head3 = new ListNode(1);
    std::cout << "Example 3: " << (Solution().hasCycle(head3) ? "True" : "False") << std::endl;

    // Clean up memory to prevent leaks (not necessary for the example, but good practice)
    delete head->next->next->next; // -4
    delete head->next->next; // 0
    delete head->next; // 2
    delete head; // 3

    delete head2->next; // 2
    delete head2; // 1

    delete head3; // 1

    return 0;
}