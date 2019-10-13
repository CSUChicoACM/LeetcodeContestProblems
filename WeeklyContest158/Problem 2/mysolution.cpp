/*
 * Submission by Robert Powers
 *
 * This is longer messier than it needs to be but it should be easy to understand
 */
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int> > attackers(8, vector<int>(2, -1)); //There are eight directions the king can be attacked from
        for(int i = 0; i < queens.size(); i++) {
            if(queens[i][0] == king[0]) { //same row
                if(queens[i][1] > king[1]) { //right
                    if(attackers[0][0] == -1) {
                        attackers[0] = queens[i];
                    } else if(queens[i][1] < attackers[0][1]) {
                        attackers[0] = queens[i];
                    }
                } else { //left
                    if(attackers[1][0] == -1) {
                        attackers[1] = queens[i];
                    } else if(queens[i][1] > attackers[1][1]) {
                        attackers[1] = queens[i];
                    }
                }
            } else if(queens[i][1] == king[1]) { //same column
                if(queens[i][0] > king[0]) { //below
                    if(attackers[2][0] == -1) {
                        attackers[2] = queens[i];
                    } else if(queens[i][0] < attackers[2][0]) {
                        attackers[2] = queens[i];
                    }
                } else { //above
                    if(attackers[3][0] == -1) {
                        attackers[3] = queens[i];
                    } else if(queens[i][0] > attackers[3][0]) {
                        attackers[3] = queens[i];
                    }
                }
            } else if(queens[i][0]-queens[i][1] == king[0]-king[1]) { //left to right diagonal
                if(queens[i][0] > king[0]) { //below and to the right
                    if(attackers[4][0] == -1) {
                        attackers[4] = queens[i];
                    } else if(queens[i][0] < attackers[4][0]) {
                        attackers[4] = queens[i];
                    }
                } else { //above and to the left
                    if(attackers[5][0] == -1) {
                        attackers[5] = queens[i];
                     } else if(queens[i][0] > attackers[5][0]) {
                        attackers[5] = queens[i];
                    }
                }
            } else if(queens[i][0]+queens[i][1] == king[0]+king[1]) { //right to left diagonal
                if(queens[i][0] > king[0]) { //below to the left
                    if(attackers[6][0] == -1) {
                        attackers[6] = queens[i];
                    } else if(queens[i][0] < attackers[6][0]) {
                        attackers[6] = queens[i];
                    }
                } else { //above to the right
                    if(attackers[7][0] == -1) {
                        attackers[7] = queens[i];
                    } else if(queens[i][0] > attackers[7][0]) {
                        attackers[7] = queens[i];
                    }
                }
            }
        }
        vector<vector<int> > result;
        for(int i = 0; i < attackers.size(); i++) {
            if(attackers[i][0] != -1)
                result.push_back(attackers[i]);
        }
        return result;
    }
};
