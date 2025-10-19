class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adj;
    for (int i = 0; i < equations.size(); ++i) {
        const string& u = equations[i][0];
        const string& v = equations[i][1];
        double val = values[i];
        adj[u][v] = val;
        adj[v][u] = 1.0 / val;
    }

    vector<double> results;

    function<double(const string&, const string&, unordered_set<string>&)> dfs =
        [&](const string& src, const string& dst, unordered_set<string>& visited) -> double {
        if (src == dst) {
            return 1.0;
        }
        visited.insert(src);
        if (adj.count(src)) {
            for (auto const& [neighbor, weight] : adj[src]) {
                if (visited.find(neighbor) == visited.end()) {
                    double path_val = dfs(neighbor, dst, visited);
                    if (path_val != -1.0) {
                        return weight * path_val;
                    }
                }
            }
        }
        return -1.0;
    };

    for (const auto& query : queries) {
        const string& src = query[0];
        const string& dst = query[1];
        if (adj.find(src) == adj.end() || adj.find(dst) == adj.end()) {
            results.push_back(-1.0);
        } else {
            unordered_set<string> visited;
            results.push_back(dfs(src, dst, visited));
        }
    }
    
    return results;
    
    }
};