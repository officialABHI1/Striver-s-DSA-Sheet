/*
  Brute force Approach :

  1. Write two seperate edge cases for n=1 & n=2 
  2. for n>2 take the help of space through a temproray vector and push the sum of all the adjacent memebers in temp starting from left 
  3. finally push it back in main ans vector of vector and clear the temp vector

Time Complexity: O(n^2)
Space Complexity: O(n^2)

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    
    vector<vector<int>>ans(numRows);

    vector<int>v1={1};
    vector<int>v2={1,1};

    if(numRows==1){
         ans[0]=(v1);
         return ans;
    }
    else if(numRows==2){
        ans[0]=(v1);
        ans[1]=(v2);
        return ans;
    }
    else
    {
        ans[0]=(v1);
        ans[1]=(v2);

        vector<int>temp;

        int k,sz;
    
        for(int i=2;i<numRows;i++){
            temp.push_back(1);
             
            sz = ans[i-1].size();
            
            for(int j=0;j<sz-1;j++){
                k= ans[i-1][j]+ans[i-1][j+1];
                temp.push_back(k);
            }
            temp.push_back(1);
            ans[i]=(temp);
            temp.clear();
        }
        return ans; 
        }
    }
};
