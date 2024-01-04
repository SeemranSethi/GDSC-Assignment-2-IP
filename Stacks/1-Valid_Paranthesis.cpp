class Solution {
public:
    bool isValid(string s) {
        stack<int> s1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                s1.push(s[i]);
            }
            else
            {
                if(s1.empty() && (s[i]==')' || s[i]=='}' || s[i]==']'))
                    return false;
                if(s[i]==')' && s1.top()!='(')
                    return false;
                if(s[i]=='}' && s1.top()!='{')
                    return false;
                if(s[i]==']' && s1.top()!='[')
                    return false;

                s1.pop();
            }
        }

        if(s1.empty())
            return true;
        else
            return false;
    }
};
