/* An encoded string (s) is given, the task is to decode it. The pattern in which the strings were encoded were as follows
original string: abbbababbbababbbab 
encoded string : 3[a3[b]1[ab]] */

class Solution{
public:
    string decodedString(string s){
        // we will use 2 stacks. one will contain the nos and another will contain the alphabets
        // whenever we enclose a closing bracket, we will pop the stck element from the stack and repeate it num times
        stack <char> st;
        int i = 0;
        while(i<s.size()){
            if(s[i] == ']'){
                string res = "";
                while(st.top()!='['){
                    res = st.top() + res;
                    st.pop();
                }   
                st.pop();
                int n = 0;
                int x = 1;
                while(!st.empty() && st.top()>='0' && st.top()<='9'){
                    n = n + (st.top()-'0')*x;
                    x*=10;
                    st.pop();
                }
                for(int j = 1; j <= n; j++){
                    for(int x = 0; x < res.size();x++){
                        st.push(res[x]);
                    }
                }
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        string ans ="";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
