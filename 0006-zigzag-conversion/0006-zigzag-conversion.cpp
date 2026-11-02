class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.length();

        if(numRows == 1 || numRows >= size){
            return s;
        }

        vector<string> res(numRows);
        int direction  = 1;
        int i = 0;
        int curr = 0;

        while(i<size){
            if(curr == numRows-1){
                direction = -1;
            }

            if(curr == 0){
                direction = 1;
            }

            res[curr] += s[i];

            curr += direction;
            i++;
        }

        string ans = "";

        for(int j = 0; j<res.size(); j++){
            ans+=res[j];
        }

        return ans;
    }
};