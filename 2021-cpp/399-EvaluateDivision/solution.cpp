class Solution {
    
public:
    
    /* 
        We can represent this problem with a weighted, directed graph, where nodes
        are connected when an equation exists between. The weight between nodes
        is the factor given by <values> to reach the other node.
        
            eg.
            A / B = k
            will be represented with two paths:
            A -> k   -> B
            B -> 1/k -> A
            
        We can obtain the desired outcome by traversing the populating graph
        and multiplying the weights if the connection isn't direct.
     */
    
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        
        // Populate the <nodes> using <equations> and <values>.
        unordered_map<string, vector<pair<string, double>>> nodes;
        for (int i = 0; i < equations.size(); i++) {
            // Insert or update the path A -> B with weight 1/k
            if (nodes.find(equations[i][0]) == nodes.end()) {
                vector<pair<string, double>> empty;
                nodes.insert(make_pair(equations[i][0], empty));
            }
            nodes[equations[i][0]].push_back(make_pair(equations[i][1],
                                                       values[i]));
            // Do the same for the path B -> A with weight k
            if (nodes.find(equations[i][1]) == nodes.end()) {
                vector<pair<string, double>> empty;
                nodes.insert(make_pair(equations[i][1], empty));
            }
            nodes[equations[i][1]].push_back(make_pair(equations[i][0],
                                                       1 / values[i]));
        }
        
        // Determine if path exists and fill <res> accordingly.
        vector<double> res;
        for (auto query : queries) {
            if (nodes.find(query[0]) == nodes.end() ||
                nodes.find(query[1]) == nodes.end()) {
                res.push_back(-1);  // Answer DNE: missing equation.
            } else if (query[0] == query[1]) {
                res.push_back(1);   // Division by oneself.
            } else {
                visited.clear();
                res.push_back(bfs(query[0], query[1], nodes));
            }
        }
        return res;
    }
    
private:
    
    unordered_set<string> visited;  // Avoid stack overflow.
    double bfs(const string &start, const string &finish,
               const unordered_map<string,
                                   vector<pair<string, double>>> &nodes) {
        if (visited.find(start) == visited.end()) {
            visited.insert(start);  
            // We know it exists because of previous checks.
            // Check if it's a direct connection.
            auto node_it = nodes.find(start);
            for (auto weighted_path_pair : (*node_it).second) {
                if (finish == weighted_path_pair.first) {
                    return weighted_path_pair.second;
                }
            }
            // It wasn't a direct connection, so recurse until we find it.
            for (auto weighted_path_pair : (*node_it).second) {
                double val = bfs(weighted_path_pair.first, finish, nodes);
                if (val > 0) {
                    // We need to update the weight.
                    return weighted_path_pair.second * val;
                }
            }
        }
        return -1;  // No paths found.
    }
    
};