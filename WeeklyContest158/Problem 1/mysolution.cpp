/*
 * Submission by Robert Powers
 */
class Solution {
public:
    int balancedStringSplit(string s) {
        int numL = 0;
        int numR = 0;
        int splits = 0;
        for(int i = 0; i < s.size(); i++) {
            s[i]=='L' ? numL++ : numR++;
            if(numL==numR) {
                splits++;
                numL = 0;
                numR = 0;
            }
        }
        return splits;
    }
};
