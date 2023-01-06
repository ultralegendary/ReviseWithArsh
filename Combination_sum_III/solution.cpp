class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int>k,int ind,int n,int sum,int o){
        if(n==sum&&k.size()==o){
            ans.push_back(k);
            return;
        }
        else if(n<sum)return ;
        for(int i=ind+1;i<10;i++){
            ;
            k.push_back(i);
            solve(ans,k,i,n,sum+i,o);
            k.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        solve(ans,vector<int>(),0,n,0,k);
        return ans;
    }
};