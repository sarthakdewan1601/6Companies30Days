template <typename T>
class Graph {
    map<T, list<T>> l;
public:
    void addEdge(T x , T y)
    {
        l[x].push_back(y);
    }

    bool topological_sort()
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
                // if (j != "NULL")
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
        // cout<<result.size()<<endl;
        if (result.size() != l.size())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph<int> g;
        if (prerequisites.size() == 1) return true;
        int i, j, k;
        for (i = 0; i < prerequisites.size(); i++)
        {
            //for(j=0;j<2;j++)
            g.addEdge(prerequisites[i][0], prerequisites[i][1]);
        }
        return g.topological_sort();
    }
};