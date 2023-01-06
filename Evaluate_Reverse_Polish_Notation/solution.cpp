
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        // cout<<to_string(345);
        cout<<tokens.size()<<',';
        for(auto i:tokens){
            long long a,b;
            if(i.size()>1){
                s.push(i);
            }
            else
            switch(i[0]){
                case '-':
                    a=atoi(s.top().c_str());
                    s.pop();
                    b=atoi(s.top().c_str());
                    s.pop();
                    s.push(to_string(b-a));
                    break;
                    
                case '+':
                    a=atoi(s.top().c_str());
                    s.pop();
                     b=atoi(s.top().c_str());
                    s.pop();
                    s.push(to_string(a+b));
                    break;
                    
                case '*':
                    a=atoi(s.top().c_str());
                    s.pop();
                     b=atoi(s.top().c_str());
                    s.pop();
                    s.push(to_string(a*b));
                    break;
                case '/':
                     a=atoi(s.top().c_str());
                    s.pop();
                     b=atoi(s.top().c_str());
                    s.pop();
                    s.push(to_string(b/a));
                    break;
                default:
                s.push(i);
                break;

            }
            
            cout<<i<<':'<<s.top()<<';';
        }
        return atoi(s.top().c_str());;
    }
};