class Solution {
 public:
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode* p = nullptr;
    ListNode* q = nullptr;
    for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
      if (q != nullptr)
        q = q->next;
      if (--k == 0) {
        p = curr;
        q = head;
      }
    }
    swap(p->val, q->val);
    return head;
  }
};