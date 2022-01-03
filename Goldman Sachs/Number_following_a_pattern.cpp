/*  Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat. */

string printMinNumberForPattern(string S){
        // we will be using stack. push a number starting with 1 and keep increasing n pushing untill u reach I
        // Keep popping and printing it
        stack<int> st;
        int num=1;
        for(int i=0;i<S.length();i++){
            char ch=S[i];
            if(ch=='D'){
                st.push(num);
                num++;
            }
            else{
                st.push(num);
                num++;
                while(st.size()>0){
                    cout<<st.top();
                    st.pop();
                }
            }
        }
        st.push(num);
        while(st.size()>0){
            cout<<st.top();
            st.pop();
        }
    }
