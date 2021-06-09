// Construct Binary Tree from Preorder and Inorder Traversal
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* head;
        head = new TreeNode();
        buildTrees(0, inorder.size(), preorder, inorder, head);
        return head;
    }
    
    void buildTrees(int low, int high, vector<int>& pre, vector<int>& ino, TreeNode* head) {
        if (low <= high) {
            for (int i = 0; i < pre.size(); i++) {
                for (int j = low; j <= high; j++) {
                    if (pre[i] == ino[j]) {
                        // cout << head << " ";
                        head->val = ino[j];
                        pre.erase(pre.begin() + i);
                        if (low <= j-1) {
                            head->left = new TreeNode();
                            buildTrees(low, j-1, pre, ino, head->left);
                        }
                        if (j+1 < high) {
                            head->right = new TreeNode();
                            buildTrees(j+1, high, pre, ino, head->right);   
                        }
                        break;
                    }
                }
            } 
        }
    }
};