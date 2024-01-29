/ * 
  Brute force(Naive Approach) 

 >>  Set Based Approach to first rememeber all the (i,j) where 0 exist then re-iterate on the matrix and check if matrix [i][j] =0 and if (i,j) exists in the set
 >>  Make that col and row = 0 accordingly 

*/

class Solution {
public:

    void makeZero(vector<vector<int>>& matrix, int i, int j,int n,int m){

        for(int p=0;p<m;p++){

          cout<<"p -> "<<p<<" "<<"j-> "<<j<<endl;
          if(p==i)
          continue;
          matrix[p][j]=0;
        }

        for(int q=0;q<n;q++){
          cout<<"i -> "<<i<<" "<<"q-> "<<q<<endl;
          if(q==j)
          continue;
          matrix[i][q]=0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();

        int n = matrix[0].size();

        set<pair<int,int>>st;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    st.insert({i,j});
                }
            }
        }

        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0){
                    
                    pair<int,int>p ={i,j};

                    if(st.find(p)!=st.end()){
                     //cout<<"i-> "<<i<<" "<<"j-> "<<j<<endl;
                     makeZero(matrix,i,j,n,m);
                     //st.clear(p);
                    }
                }
            }
        }

        
    }
};
