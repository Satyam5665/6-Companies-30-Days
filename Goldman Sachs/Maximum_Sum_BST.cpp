class NodeVal
{
public:
    int minnode, maxnode, size;

    NodeVal(int minnode, int maxnode, int size)
    {
        this->minnode = minnode;
        this->maxnode = maxnode;
        this->size = size;
    }
};
class Solution
{
public:
    int ans;
    NodeVal solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return NodeVal(INT_MAX, INT_MIN, 0);
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        if (left.maxnode < root->val && root->val < right.minnode)
        {
            ans = max(ans, left.size + right.size + root->val);
            return NodeVal(min(root->val, left.minnode), max(root->val, right.maxnode), left.size + right.size + root->val);
        }

        return NodeVal(INT_MIN, INT_MAX, max(left.size, right.size));
    }
    int maxSumBST(TreeNode *root)
    {
        ans = 0;
        int temp = solve(root).size;
        // cout<<temp<<endl;
        return ans;
    }
};