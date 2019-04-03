/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode(0);
        ListNode node = result;
        int mod = 0;
        while (l1 != null && l2 != null) {
            int sum = l1.val + l2.val + mod;
            node.next = new ListNode(sum % 10);
            mod = sum / 10;
            l1 = l1.next;
            l2 = l2.next;
            node = node.next;
        }
        while (l1 != null) {
            int sum = l1.val + mod;
            node.next = new ListNode(sum % 10);
            mod = sum / 10;
            l1 = l1.next;
            node = node.next;
        }
        while (l2 != null) {
            int sum = l2.val + mod;
            node.next = new ListNode(sum % 10);
            mod = sum / 10;
            l2 = l2.next;
            node = node.next;
        }
        if (mod != 0) {
            node.next = new ListNode(mod);
        }
        return result.next;
    }
}