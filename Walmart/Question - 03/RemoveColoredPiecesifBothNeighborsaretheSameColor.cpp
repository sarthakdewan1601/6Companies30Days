class Solution {
public:
    bool winnerOfGame(string colors) {
        int i, j, k;
        int n = colors.size();
        int count_alice = 0;
        int count_bob = 0;

        for (i = 1; i < n - 1; i++)
        {
            if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i + 1] == 'A')
            {
                count_alice++;
            }
            else if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i + 1] == 'B')
            {
                count_bob++;
            }
        }
        if (count_alice > count_bob)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};