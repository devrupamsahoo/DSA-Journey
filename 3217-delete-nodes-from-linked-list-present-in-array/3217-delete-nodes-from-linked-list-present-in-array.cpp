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
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>s;

        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;

        while(curr->next != nullptr){
            if(s.find(curr->next->val) != s.end()){
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};