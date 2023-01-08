class Solution {
    int gcd(int a,int b){
        if(b==0)return a;
        else return gcd(b,a%b);
    }
    int lcm(int a,int b){
        return a*b/gcd(a,b);
    }
public:
    void disp(vector<int> a){
        // for(int i=0;i<a.size();i++){
            for(int j=0;j<a.size();j++)cout<<a[j]<<' ';
            cout<<"\n";
        
        // cout<<"\n";
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<set<int>> memo(nums.size());
        sort(nums.begin(),nums.end());
        memo[0].insert(nums[0]);
        vector<int> ans;
        int max=1,ind=0;
        for(int i=1;i<nums.size();i++){
            memo[i].insert(nums[i]);
            int j=i-1,c=i;
            for(;j>=0;j--){
                if(nums[i]%nums[j]==0&&(dp[j]>=dp[c])){
                    c=j;
                }
            }
            if(i!=c){
            dp[i]+=dp[c];
            // cout<<i<<','<<c<<';';
            if(dp[i]>=max){
                max=dp[i];
                ind=i;
                
            }
            memo[i].insert(nums[c]);
            for(auto k:memo[c])memo[i].insert(k);
            }
            // disp(dp);
        }
        return vector<int>(memo[ind].begin(),memo[ind].end());
    }
};