/* Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.  */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> dq(k);
        vector<int> ans;
        int i;
        for(i=0;i<k;i++){
            // For every element, the previous smaller elements are useless so 
		// remove them from dq
            while((!dq.empty()) && nums[i]>=nums[dq.back()]){
                dq.pop_back(); // Remove from rear 
            }
            dq.push_back(i); // Add new element at rear of queue 
        }
        for(;i<nums.size();i++){
            // The element at the front of the queue is the largest element of 
		// previous window, so print it 
            ans.push_back(nums[dq.front()]);
            // Remove the elements which are out of this window 
		    while ((!dq.empty()) && dq.front() <= i - k) 
			    dq.pop_front(); // Remove from front of queue 

		    // Remove all elements smaller than the currently 
		    // being added element (remove useless elements) 
		    while ((!dq.empty()) && nums[i] >= nums[dq.back()]) 
			    dq.pop_back(); 

		// Add current element at the rear of Qi 
		    dq.push_back(i); 
        }
        // Print the maximum element of last window 
	    ans.push_back(nums[dq.front()]); 
        return ans;
    }
};
