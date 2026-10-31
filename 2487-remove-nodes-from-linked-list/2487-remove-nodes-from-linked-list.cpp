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
    ListNode* solve(ListNode* &head){
        // base case
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        // process the right side
        head->next = solve(head->next);

        // remove current node if a greater value exists on its right
        if(head->val < head->next->val) {
            return head->next;
        }

        return head;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        return solve(head);
    }
};