class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> dict;
        for(string s: wordList)
            dict.insert(s);
        queue<string> q;
        q.push(beginWord);
        map<string, int> dist;
        dist[beginWord]=1;
        dict.erase(beginWord);
        while(!q.empty())
        {
            string node = q.front();
            if(node==endWord)
            {
                return dist[node];
            }
            for(int i=0; i<node.size(); i++)
            {
                string s = node;
                for(int j='a'; j<='z'; j++)
                {
                    s[i]=j;
                    if(dict.find(s)!=dict.end())
                    {
                        
                        dist[s]=dist[node]+1;
                        q.push(s);
                        dict.erase(s);
                    }
                }
            }
            q.pop();
        }
        return 0;
    }
};