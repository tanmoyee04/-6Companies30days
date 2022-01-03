/* Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. */

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        map<string,vector<string>> m; 
        for(int i=0;i<string_list.size();i++){ // iterate in the vector
            string s=string_list[i]; //pick up strings one at a time
            sort(s.begin(),s.end()); // sorting the strings. e.g act->act, cat->act, tac->act
            m[s].push_back(string_list[i]); // push the original element into the map
        }
        vector<vector<string>> ans(m.size()); // the ans which we need to return as a vector. size of the output vector will be same as that of map
        int ind=0; // for iterating in the ans
        for(auto x:m){
            auto v=x.second; // x: dgo-> god, dog x.first= dgo x.second=god, dog
            for(int i=0;i<v.size();i++){
                ans[ind].push_back(v[i]); // ans: 0-> dog, god 1-> act, cat, tac
            }
            ind++;
        }
        return ans;
    }
};
