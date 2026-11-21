class Solution {
public:
    vector<int> answer;
    vector<vector<int>> adj;
    vector<int> newParent;
    vector<int> subtree;

    void findParent(int node, string &s, vector<int>& last) {
        int c = s[node] - 'a';

        int previous = last[c];

        if (node != 0) {
            newParent[node] = (previous == -1) ? newParent[node] : previous;
        }

        last[c] = node;

        for (int child : adj[node]) {
            findParent(child, s, last);
        }

        last[c] = previous;
    }

    int calculate(int node, vector<vector<int>>& newAdj) {
        int size = 1;

        for (int child : newAdj[node]) {
            size += calculate(child, newAdj);
        }

        answer[node] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.resize(n);
        newParent = parent;
        answer.resize(n);

        // Build original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // Find closest ancestor with same character
        vector<int> last(26, -1);
        findParent(0, s, last);

        // Build modified tree
        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        calculate(0, newAdj);

        return answer;
    }
};
