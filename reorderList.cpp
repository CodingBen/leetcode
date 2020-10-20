#include <iostream>
#include <vector>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        std::vector<ListNode *> vec;
        ListNode *node = head;
        while (node != nullptr) {
            vec.emplace_back(node);
            node = node->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i == j) {
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};


int main() {
    ListNode *head = new ListNode();
    ListNode *list = head;
    for (int i = 1; i < 11; i ++){
        if (head->next == nullptr){
            head->next = new ListNode(i);
            head = head->next;
            printf("var: %d\n", head->val);
        }
    }
    Solution::reorderList(list);
    while (head->next != nullptr){
        printf("var: %d\n", head->val);
        head = head->next;
    }
    return 0;
}


