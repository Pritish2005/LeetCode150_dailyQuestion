// // Question Link -> https://leetcode.com/problems/add-two-numbers/


// class Solution {
// public:
//     ListNode* reverse(ListNode* head){
//         ListNode* curr = head;
//         ListNode* prev = nullptr;
//         while (curr != nullptr){
//             ListNode* next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return prev; // Return the new head of the reversed list
//     }

//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
//         // Reverse both linked lists
//         l1 = reverse(l1);
//         l2 = reverse(l2);

//         ListNode dummy(0); // Create a dummy node to simplify code
//         ListNode* current = &dummy;
//         int carry = 0;

//         while (l1 || l2 || carry) {
//             int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
//             carry = sum / 10;
//             current->next = new ListNode(sum % 10);

//             if (l1) l1 = l1->next;
//             if (l2) l2 = l2->next;
//             current = current->next;
//         }

//         // Reverse the result back
//         return reverse(dummy.next);
//     }
// };
