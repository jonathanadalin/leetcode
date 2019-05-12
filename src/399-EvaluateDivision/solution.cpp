class Solution {
    
private:
    
    double dfs() {
        return -1;
    }
    
public:
    
    /* 
        We can represent this problem with a weighted, directed graph, where nodes
        are connected when an equation exists between. The weight between nodes
        is the factor given by <values> to reach the other node.
        
            eg.
            A / B = k
            will be represented with two paths:
            A -> 1/k -> B
            B ->  k  -> A
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
                                                       1 / values[i]));
            // Do the same for the path B -> A with weight k
            if (nodes.find(equations[i][1]) == nodes.end()) {
                vector<pair<string, double>> empty;
                nodes.insert(make_pair(equations[i][1], empty));
            }
            nodes[equations[i][1]].push_back(make_pair(equations[i][0],
                                                       values[i]));
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
                res.push_back(0);   // TODO
            }
        }
        return res;
    }
};