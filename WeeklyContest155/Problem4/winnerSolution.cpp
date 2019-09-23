/*
 * This is the solution submitted by the winner of Weekly Contest 155
 * This code will not compile in its current state
 * https://leetcode.com/neal_wu
 */

vector<int> topological_sort(vector<int> vertices, map<int, vector<int>> &adj) {
    map<int, int> in_degree;
    vector<int> order;

    for (int v : vertices)
        for (int neighbor : adj[v])
            in_degree[neighbor]++;

    for (int v : vertices)
        if (in_degree[v] == 0)
            order.push_back(v);

    int current = 0;

    while (current < (int) order.size()) {
        int node = order[current++];

        for (int neighbor : adj[node])
            if (--in_degree[neighbor] == 0)
                order.push_back(neighbor);
    }

    return order;
}

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; i++)
            if (group[i] < 0)
                group[i] = m++;

        vector<vector<int>> group_vertices(m, vector<int>());

        for (int i = 0; i < n; i++)
            group_vertices[group[i]].push_back(i);

        vector<vector<pair<int, int>>> within_group_edges(m, vector<pair<int, int>>());
        vector<pair<int, int>> group_edges;

        for (int i = 0; i < n; i++)
            for (int before : beforeItems[i])
                if (group[before] == group[i])
                    within_group_edges[group[i]].emplace_back(before, i);
                else
                    group_edges.emplace_back(group[before], group[i]);

        vector<vector<int>> within_group_ordering(m, vector<int>());

        for (int g = 0; g < m; g++) {
            map<int, vector<int>> adj;

            for (pair<int, int> &edge : within_group_edges[g])
                adj[edge.first].push_back(edge.second);

            within_group_ordering[g] = topological_sort(group_vertices[g], adj);

            if (within_group_ordering[g].size() < group_vertices[g].size())
                return {};
        }

        vector<int> groups;

        for (int i = 0; i < m; i++)
            groups.push_back(i);

        map<int, vector<int>> adj;

        for (pair<int, int> &edge : group_edges)
            adj[edge.first].push_back(edge.second);

        vector<int> group_ordering = topological_sort(groups, adj);

        if (group_ordering.size() < groups.size())
            return {};

        vector<int> answer;

        for (int g : group_ordering)
            for (int x : within_group_ordering[g])
                answer.push_back(x);

        return answer;
    }
};
