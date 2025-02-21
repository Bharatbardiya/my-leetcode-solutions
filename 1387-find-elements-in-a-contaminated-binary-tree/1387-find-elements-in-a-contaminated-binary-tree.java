/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
// import java.util.*;

class FindElements {
    private HashSet<Integer> st = new HashSet<Integer>();

    private void dfs(TreeNode root){
        if(root==null) return;
        
        Integer val = root.val;
        st.add(val);
        if(root.left != null){
            root.left.val = 2*val+1;
            dfs(root.left);
        }
        if(root.right != null){
            root.right.val = 2*val+2;
            dfs(root.right);
        }
    }

    public FindElements(TreeNode root) {
        root.val = 0;
        dfs(root);
    }
    
    public boolean find(int target) {
        return st.contains(target);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */