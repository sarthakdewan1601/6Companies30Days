class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
//         string result = "";
        int i,j,k,n = str1.size(),m = str2.size();
      
      
      //INITIAL APPROACH WITH I FAILED MISERABLY
      
      
      
//         if(n >= m)
//         {
//             j = 0;
//             //i = 0;
//             //int max_len = INT_MIN;
//             while(j < m)
//             {
//                 result.push_back(str2[j]);
//                 // cout<<result<<endl;
//                 for(i = 0 ; i < n ; i += result.size())
//                 {
//                     if(i+result.size()-1 >= n)
//                     {
//                         result.pop_back();
//                         return result;
//                     }
//                     // cout<<i + result.size()<<endl;
//                     string temp = str1.substr(i , result.size());
//                     // cout<<result<<" "<<temp<<endl;
//                     // cout<<str1.substr(1,2);
//                     if(temp == result)
//                     {
//                         continue;
//                     }
//                     else
//                     {
                        
//                     }
//                 }
//                 j++;
//             }
//             return result;
//         }
//         else
//         {
//             i = 0;
//             while(i < n)
//             {
//                 if(str1[i] == str2[i])
//                 {
//                     result.push_back(str1[i]);
//                     i++;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//         }
//         return result;
      
      //SIMPLE APPROACH AFTER WATCHING EDITORIAL ;(
        
        if(str1 + str2 != str2 + str1)
        {
            return "";
        }
        else
        {
            return str2.substr(0,__gcd(n,m));
        }
    }
};
