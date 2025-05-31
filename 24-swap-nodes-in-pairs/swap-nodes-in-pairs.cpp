class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }   
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while (head != NULL && head->next != NULL) {
            ListNode* node1 = head;
            ListNode* node2 = head->next;
            prev->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            prev = node1;
            head = node1->next;
        }
        
        return dummy->next;
    }
};
