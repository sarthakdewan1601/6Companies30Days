class Solution{
//recursive function    
string decode(string &s, int &i)
{
    string result;
    while(i < s.length() && s[i] != ']')
    {
        if(isdigit(s[i])) //if the character is the digit
        {
            int k = 0;
            while(i < s.length() && isdigit(s[i])) //we have to compute the number
            {
                k = k * 10 + (s[i] - '0');
                i++;
            }
            i++; //skip the opening braces
            string r = decode(s,i); //get the decoded string without number and with repetitions
            while(k > 0) //add the string k(given number computed) times
            {
                result += r;
                k--;
            }
            i++; //closing braces
        }
        else
        {
            result.push_back(s[i++]); //if it's not a digit then push in the result as it is
        }
    }
    return result;
}

public:
    string decodedString(string s){
        // code here
        int i = 0;
        return decode(s,i);
    }
};
