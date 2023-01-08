class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int is=0,sum=0;
        for(auto i:nums){
            sum+=i;
        }
        for(int i=0;i<nums.size();i++){
            is+=i*nums[i];
        }
        int ans=is;
        for(int i=0;i<nums.size();i++){
            is=is-(sum-nums[i])+nums[i]*(nums.size()-1);
            if(ans<is)ans=is;
        }
        return ans;
    }
};
