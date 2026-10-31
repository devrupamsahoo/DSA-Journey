class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for(int i = 0; i < nums.size(); i++){
            minHeap.push(nums[i]);
        }

        for(int i = 0; i < nums.size() - k; i++){
            minHeap.pop();
        }

        return minHeap.top();
    }
};