class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int end = piles.size() - 1;
        int n = (end + 1) / 2;
        int start = 0;
        int bob_stones = 0, alice_stones = 0;
        for (int i = 0; i <= (end + 1) / 2; i++) {
            if (piles[start] >= piles[end]) {
                alice_stones += piles[start];
                start++;

                if (piles[start] < piles[end]) {
                    bob_stones += piles[start];
                    start++;
                }
                else {
                    bob_stones += piles[end];
                    end--;
                }
            }

            else {
                alice_stones += piles[end];
                end--;

                if (piles[start] < piles[end]) {
                    bob_stones += piles[start];
                    start++;
                }
                else {
                    bob_stones += piles[end];
                    end--;
                }
            }
        }
        return (alice_stones > bob_stones);
    }
};