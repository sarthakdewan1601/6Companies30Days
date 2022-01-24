template <typename T>
class Graph {
    map<T, list<T>> l;
public:
    void addEdge(T x , T y)
    {
        l[x].push_back(y);
    }

    vector<int> topological_sort()
    {
        map<T, int> indegree;
        for (auto i : l)
        {
            indegree[i.first] = 0;
        }
        for (auto i : l)
        {
            for (auto j : l[i.first])
            {
                if (j != -1)
                    indegree[j]++;
            }
        }
        vector<T> result;
        queue<T> s;
        for (auto i : l)
        {
            if (indegree[i.first] == 0)
            {
                s.push(i.first);
            }
        }
        while (!s.empty())
        {
            T node = s.front();
            s.pop();
            result.push_back(node);
            for (auto i : l[node])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    s.push(i);
                }
            }
        }
        if (result.size() != l.size())
        {
            vector<int> res;
            return res;
        }
        else
        {
            return result;
        }
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph<int> g;
        int i, j, k;
        if (prerequisites.size() == 0)
        {
            vector<int> res;
            for (i = 0; i < numCourses; i++)
            {
                res.push_back(i);
            }
            return res;
        }
        unordered_map<int, int> umap;
        for (i = 0; i < prerequisites.size(); i++)
        {
            umap[prerequisites[i][0]]++;
        }
        for (i = 0; i < numCourses; i++)
        {
            if (umap.find(i) == umap.end())
            {
                g.addEdge(i, -1);
            }
        }
        for (i = 0; i < prerequisites.size(); i++)
        {
            g.addEdge(prerequisites[i][1], prerequisites[i][0]);
        }
        return g.topological_sort();
    }
};