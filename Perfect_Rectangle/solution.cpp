class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& r) {
        // unordered_map<pair<int,int>,bool> m;
        int minx=r[0][0],miny=r[0][1],maxx=r[0][2],maxy=r[0][3],area=0;

        for(int i=0;i<r.size();i++){
            if(minx>r[i][0])minx=r[i][0];
            if(miny>r[i][1])miny=r[i][1];
            if(maxx<r[i][2])maxx=r[i][2];
            if(maxy<r[i][3])maxy=r[i][3];
        }
        map<vector<int>,bool>m;
        for(auto i:r){
            if(m[i])return 0;
            m[i]=1;
        }
        int ans=0;
        map<int,map<int,int>> dp;
        for(auto i:r){
            dp[i[0]][i[1]]++;
            dp[i[2]][i[1]]++;
            dp[i[2]][i[3]]++;
            dp[i[0]][i[3]]++;
            area+=abs((i[3]-i[1])*(i[2]-i[0]));
        }
        vector<vector<int>> cor;
        for(int i=minx;i<=maxx+1;i++){
            for(int j=miny;j<=maxy+1;j++){
                if(dp[i][j]==1){
                    cor.push_back({i,j});
                ans++;
                }
            }
        }
        int f=0;
        
        for(auto i:cor){
            if((i[0]==minx&&i[1]==miny)||(i[0]==maxx&&i[1]==maxy)||(i[0]==minx&&i[1]==maxy)||i[0]==maxx&&i[1]==miny)f++;
            else return 0;
        // cout<<i[0]<<','<<i[1]<<';';
        }
        // cout<<minx<<','<<maxx<<','<<miny<<','<<maxy<<':';
        return ans==4&&f==4&&area==(maxx-minx)*(maxy-miny);
    }
};