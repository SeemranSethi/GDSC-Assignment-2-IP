class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.size();
        string ans="";
        unordered_map<char,int> Count;
        unordered_map<char,bool> visited;
        stack<int> ans_s;
        for(auto ch:s)
        {
            if(Count.find(ch)==Count.end())
                Count[ch]=1;
            else
                Count[ch]++;
        }

        for(auto it=Count.begin();it!=Count.end();it++)
        {
            visited[it->first]=false;
        }

        for(int i=0;i<len;i++)
        {
            Count[s[i]]--;
            if(visited[s[i]])
                continue;
            
            while(!ans_s.empty() && s[i]<s[ans_s.top()] && Count[s[ans_s.top()]]>0)
            {
                visited[s[ans_s.top()]]=false;
                ans_s.pop();
            }
            ans_s.push(i);
            visited[s[i]]=true;
        }

        while(!ans_s.empty())
        {
            ans=s[ans_s.top()]+ans;
            ans_s.pop();
        }

        return ans;
    }
};
