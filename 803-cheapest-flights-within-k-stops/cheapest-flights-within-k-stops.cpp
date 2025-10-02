class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
      vector<pair<int,int>>adj[n];
      for(auto it:flights){
        adj[it[0]].push_back({it[1],it[2]});
      }
      queue<pair<int,pair<int,int>>>q;
      vector<int>dist(n,1e9);
      q.push({0,{src,0}});
      dist[src]=0;
      while(q.size()>0){
        auto it=q.front();
        int stop=it.first;
        int node=it.second.first;
        int dis=it.second.second;
        q.pop();
        if(stop>k) continue;
        for(auto i:adj[node]){
            int nnode=i.first;
            int wt=i.second;
            if(dis+wt<dist[nnode] && stop<=k){
                dist[nnode]=wt+dis;
                q.push({stop+1,{nnode,dist[nnode]}});
            }
        }
      }
      if(dist[dst]==1e9) return -1;
      else return dist[dst];
    }
};