/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    void insertAtTail(ListNode* &head, int val){
        ListNode* newnode = new ListNode(val);
        if(head == nullptr){
            head = newnode;
        }else{
            ListNode* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* res = nullptr;

        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int sum = carry;

            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }

            int digit = sum%10;
            carry = sum/10;

            insertAtTail(res, digit);
        }

        return res;
    }
};