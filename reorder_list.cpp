struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

class Solution {
public:
    ListNode * reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* current_node = head;

        while(current_node != nullptr){
            ListNode* next_node = current_node->next;
            current_node->next = prev;
            prev = current_node;
            current_node = next_node;
        }
        return prev;
    }

    void merge(ListNode* l1, ListNode* l2){
        while (l1 != nullptr){
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;

            l1->next = l2;

            if(l1_next == nullptr) break;

            l2->next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }
    }

    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return;

        ListNode* left = head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode* right = reverse(slow);
        merge(left, right);
    }
};