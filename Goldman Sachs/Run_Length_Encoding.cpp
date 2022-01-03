/* Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
You are required to complete the function encode that takes only one argument the string which is to be encoded and returns the encoded string. */

string encode(string src)
{     
  int len = src.size();
  for(int i=0;i<len;i++){
      int count=1;
      while(i<(len-1) && src[i]==src[i+1]){
          count++;
          i++;
      }
      cout<<src[i]<<count;
  }
}
