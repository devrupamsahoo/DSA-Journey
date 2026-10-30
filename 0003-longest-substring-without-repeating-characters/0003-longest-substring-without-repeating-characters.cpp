class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>seen(256, -1);
        int left = 0;
        int maxLen = 0;

        for(int right = 0; right<s.length(); right++){
            char ch = s[right];

            if(seen[ch] >= left){
                left = seen[ch]+1;
            }

            maxLen = max(maxLen, right-left+1);
            seen[ch] = right;
        }

        return maxLen;
    }
};