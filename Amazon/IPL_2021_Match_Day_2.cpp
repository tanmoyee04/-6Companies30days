/* Due to the rise of covid-19 cases in India, this year BCCI decided to organize knock-out matches in IPL rather than a league.

Today is matchday 2 and it is between the most loved team Chennai Super Kings and the most underrated team - Punjab Kings. Stephen Fleming, the head coach of CSK, analyzing the 
batting stats of Punjab. He has stats of runs scored by all N players in the previous season and he wants to find the maximum score for each and every contiguous sub-list of size 
K to strategize for the game. */


vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> v;
        deque<int> dq;
        
        for(int i=0;i<n;i++)
        {
            while(!dq.empty() && dq.front()<=i-k)
                  dq.pop_front();
                  
                  while(!dq.empty() && arr[dq.back()]<=arr[i] )
                     dq.pop_back();
                     
                     dq.push_back(i);
            
            
            if(i>=k-1)
            v.push_back(arr[dq.front()]);
            
        }
        
        
        return v;
    }
