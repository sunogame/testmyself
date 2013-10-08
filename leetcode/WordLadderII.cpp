class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

	// label all string.
        vector<string> all;
        map<string, int> ref;
        all.push_back(start);
        all.push_back(end);
        for(unordered_set<string>::iterator it = dict.begin(); it!= dict.end(); it++)
        {
            all.push_back(*it);
        }
        for(int i=0;i<all.size();i++)
        {
            ref[all[i]] = i;
        }

	//BFS got shortest path
        vector< vector<int> > pre(all.size(), vector<int>());
        vector<int> sh(all.size(), 0);
        queue<int> que;
        int b = ref[start];
        int e = ref[end];
        que.push(b);
        sh[b] = 1;
        while(!que.empty())
        {
            int id = que.front(); que.pop();
            if(sh[e] != 0 && sh[id] > sh[e])
                break;
            string tmp = all[id];
            for(int i=0;i<tmp.size();i++)
            {
                for(int j='a';j<='z';j++)if(j != all[id][i])
                {
                    tmp[i] = j;
                    if(dict.find(tmp) != dict.end()) // hot spot. Got TLE if use set instead of unordered_set.
                    {
                        int v = ref[tmp];
                        if(sh[v] == 0 || sh[v] == sh[id] + 1)
                        {
                            pre[v].push_back(id);
                            if(sh[v] == 0)
                            {
                                sh[v] = sh[id] + 1;
                                que.push(v);
                            }
                        }
                    }
                }
                tmp[i] = all[id][i];
            }
        }

	// cover label to string
        vector< vector<int> > ans;
        vector<int> tmp;
        tmp.push_back(e);
        ans.push_back(tmp);
        while(ans[0].size() < sh[e])
        {
            int n = ans.size();
            for(int i=0;i<n;i++)
            {
                int id = ans[i][ans[i].size()-1];
                if(pre[id].size() > 1)
                {
                    for(int j=1;j<pre[id].size();j++)
                    {
                        vector<int> tmp = ans[i];
                        tmp.push_back(pre[id][j]);
                        ans.push_back(tmp);
                    }
                }
                ans[i].push_back(pre[id][0]);
            }
        }
        vector< vector<string> > res;
        if(sh[e] == 0)
            return res;
        for(int i=0;i<ans.size();i++)
        {
            vector<string> tmp;
            for(int j=ans[i].size()-1;j>=0;j--)
                tmp.push_back(all[ans[i][j]]);
            res.push_back(tmp);
        }
        return res;
    }
};

