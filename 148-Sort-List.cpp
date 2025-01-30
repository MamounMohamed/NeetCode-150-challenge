/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void mergeSort(ListNode*& head, int sz) {
        if (sz <= 1) {
            return;
        }

        int md = sz / 2;
        ListNode* current = head;
        for (int i = 1; i < md; i++) {
            current = current->next;
        }

        ListNode* tmp = current->next;
        current->next = nullptr;

        ListNode *first = head, *second = tmp;

        mergeSort(first, md);
        mergeSort(second, sz - md);

        head = merge(first, second);
    }

    ListNode* merge(ListNode* a, ListNode* b) {
        if (!a)
            return b;
        if (!b)
            return a;

        ListNode* ans = new ListNode(0);
        ListNode* ret = ans;

        while (a && b) {
            if (a->val <= b->val) {
                ret->next = a;
                a = a->next;
            } else {
                ret->next = b;
                b = b->next;
            }
            ret = ret->next;
        }

        if (a)
            ret->next = a;
        if (b)
            ret->next = b;
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        int sz = 0;
        ListNode* temp = head;
        while (temp) {
            sz++;
            temp = temp->next;
        }

        mergeSort(head, sz);
        return head;
    }
};
