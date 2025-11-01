/*
 * @lc app=leetcode id=1817661973 lang=cpp
 *
 * DeleteNodesFromLinkedListPresentInArray
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> mpp(nums.begin(), nums.end());

        while (head && mpp.count(head->val))
            head = head->next;

        ListNode* curr = head;
        while (curr && curr->next) {
            while (curr->next && mpp.count(curr->next->val)) {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return head;
    }
};