class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int low = 0;
        int high = tokens.size() - 1;
        int score = 0;
        int maxScore = 0;
        while(low <= high){
            if(tokens[low] > power){
                if(score > 0){
                    power += tokens[high--];
                    score--;
                }else{
                    break;
                }
            }else{
                
                power -= tokens[low++];
                score++;
                maxScore = max(score, maxScore);
            
            }
        }
        return maxScore;

    }
};