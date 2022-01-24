/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper(vector<vector<int>>& grid, int row_start, int row_end, int col_start, int col_end, int size)
    {
        int sum = 0;
        for (int i = row_start; i < row_end; i++)
        {
            for (int j = col_start ; j < col_end; j++)
            {
                sum += grid[i][j];
            }
        }
        Node *ans;
        if (sum == 0)
        {
            ans = new Node(false, true);
        }
        else if (sum == size * size)
        {
            ans = new Node(true, true);
        }
        else
        {
            ans = new Node(false, false);
            size = size / 2;
            ans->topLeft = helper(grid, row_start, row_start + size, col_start, col_start + size, size);
            ans->topRight = helper(grid, row_start, row_start + size, col_start + size, col_end, size);
            ans->bottomLeft = helper(grid, row_start + size, row_end, col_start, col_start + size, size);
            ans->bottomRight = helper(grid, row_start + size, row_end, col_start + size, col_end, size);
        }
        return ans;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        Node * ans = helper(grid, 0, n, 0, n, n);
        return ans;
    }
};