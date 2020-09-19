
/**
 * https://leetcode.com/problems/linked-list-cycle/
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
 * Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
     // cycle our list until we hit a repeat or null node
        // ArrayList <ListNode> seen = new ArrayList<ListNode>();
        HashSet<ListNode> seen = new HashSet<ListNode>();
        
        ListNode current = head;
        
        while(current != null){
            // check if we've already seen it 
            if (seen.contains(current)) {
                //return true if yes
                return true;
            }
            // push our object into our seen list
            seen.add(current);
            //iterate
            current = current.next;
        }
        return false;
    }
}
