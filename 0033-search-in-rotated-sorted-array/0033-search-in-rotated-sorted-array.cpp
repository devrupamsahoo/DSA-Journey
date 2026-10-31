class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end- start)/2;

        while(start<end){
            if(nums[mid]>=nums[0]){
                start = mid+1;
            }
            else{
                end = mid;
            }
            mid = start + (end - start)/2;
        }

        int s1=0, e1=start-1;
        int s2=start, e2=nums.size()-1;

        int m1 = s1+(e1-s1)/2;
        while(s1<=e1){
            if(nums[m1]==target){
                return m1;
            }
            else if(nums[m1]>target){
                e1 = m1 - 1;
            }
            else{
                s1 = m1 + 1;
            }
            m1 = s1+(e1-s1)/2;
        }

        int m2 = s2+(e2-s2)/2;
        while(s2<=e2){
            if(nums[m2]==target){
                return m2;
            }
            else if(nums[m2]>target){
                e2 = m2 - 1;
            }
            else{
                s2 = m2 + 1;
            }
            m2 = s2+(e2-s2)/2;
        }
        return -1;
    }
};