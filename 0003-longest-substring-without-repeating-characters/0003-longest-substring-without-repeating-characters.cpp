class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        vector<int>seen(256, -1);

        int maxLen = 0;

        for(int right = 0; right<s.length(); right++){
            char c = s[right];

            if(seen[c] >= left){
                left = seen[c] + 1;
            }

            seen[c] = right;

            maxLen = max(maxLen, right-left+1);
        }

        

        return maxLen;
    }
};