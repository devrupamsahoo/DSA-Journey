class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end-start)/2;
        vector<int> res;

        int ans=-1;

        while(start<=end){
            if(nums[mid]==target){
                ans=mid;
                end = mid-1;
            }
            else if(nums[mid]<target){
                start = mid+1;
            } else{
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        res.push_back(ans);

        if(ans==-1){
            return {-1, -1};
        }

        start = 0;
        end = nums.size()-1;
        mid = start + (end-start)/2;

        while(start<=end){
            if(nums[mid]==target){
                ans=mid;
                start = mid+1;
            }
            else if(nums[mid]<target){
                start = mid+1;
            } else{
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        res.push_back(ans);

        return res;
    }
};