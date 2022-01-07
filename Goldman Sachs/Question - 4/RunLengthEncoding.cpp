/*You are required to complete this function */

string encode(string src)
{     
  //Your code here
  int i,j,k;
  int n = src.size();
  string result = "";
  char prev = src[0];
  int count = 0;
  for(i = 0; i < n ; i++)
  {
    //   cout<<src[i]<<endl;
      if(src[i] != prev)
      {
          prev = src[i];
          result.push_back(src[i-1]);
          string number = to_string(count);
          result += number;
          count = 1;
      }
      else
      {
        count++;
      }
  }
  result.push_back(src[n-1]);
  string number = to_string(count);
  result += number;
  return result;
}
