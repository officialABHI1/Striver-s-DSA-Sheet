/*

   The time & complexity of this code is also again O(n^2) because of the vector or vector ( ans) to store the pascal's triangle 

   >> However we have made some modification in this by getting rid of the of temporary vector Temp which significantly improves the TC & SC

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

        int k,sz;
    
        for(int i=2;i<numRows;i++){

            //vector<int>temp;
             
            sz = ans[i-1].size();

            ans[i].resize(sz+1);

            ans[i][0]=ans[i][sz]=1;
            
            for(int j=0,k=1;j<sz-1;j++,k++){
                ans[i][k]= ans[i-1][j]+ans[i-1][j+1];
                //temp.push_back(k);
            }
          //  temp.clear();
        }
        return ans; 
        }
    }
};
