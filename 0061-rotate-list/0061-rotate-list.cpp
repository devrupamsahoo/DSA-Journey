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
    ListNode* findNthLastNode(ListNode* head, int n){
        int count = 1;

        while(head != nullptr){
            if(count == n){
                return head;

            }

            count++;
            head = head->next;
        }

        return head;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0){
            return head;
        }

        ListNode* tail = head;
        int len = 1;

        while(tail->next != nullptr){
            len++;
            tail = tail->next;
        }

        int rotate = k%len;

        if(k%len == 0){
            return head;
        }

        k %= len;

        tail->next = head;

        ListNode* newLastNode = findNthLastNode(head, len-k);

        head = newLastNode->next;
        newLastNode->next = nullptr;

        return head;
    }

};