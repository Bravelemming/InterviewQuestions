/**
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
 * such that adding up all the values along the path equals the given sum.
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
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        return path(root, sum, 0);
    }
    
    // time: 0n, space, 1
    // helper; depth first search.  recursive - tail recursion
    public boolean path(TreeNode node, int sum, int pathValue) {
        boolean isPath = false;
        pathValue += node.val;  // 9
        
        // if we hit a null, we are at the end of a path,
        if (node.left == null && node.right == null) {
            if (pathValue == sum) {
                isPath = true;
                return true; // winning
            }
            // reset our path value
             pathValue = 0;
        }
        
        // do we have s left node, do we have right
        if (node.left != null) {
            // recurse
            boolean walk = path(node.left, sum, pathValue);
            if (walk) isPath = true;
        }
        if (node.right != null) {
            // recurse
            boolean walk = path(node.right, sum, pathValue);
            if (walk) isPath = true;
        }
        
        return isPath;
    }

}


// notes
// no negatives, 1 - 10,000

