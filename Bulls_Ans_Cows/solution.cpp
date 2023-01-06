class Solution {
public:
    string getHint(string secret, string guess) {
        int c=0,b=0;
        unordered_map<int,int> m,m1;
        for(char i:secret)m[i]++;
        for(char i:guess)m1[i]++;
        for(int i=0;i<secret.size();i++)
        {

        c+=secret[i]==guess[i];
        if(secret[i]==guess[i]){
            m[secret[i]]?m[secret[i]]--:0;
            m1[guess[i]]?m1[guess[i]]--:0;
        }
        }
        for(auto [i,v]:m){
            if(m1[i]){
                b+=m[i]>m1[i]?m1[i]:m[i];
            }
        }
        return to_string(c)+"A"+to_string(b)+"B";
        

    }
};