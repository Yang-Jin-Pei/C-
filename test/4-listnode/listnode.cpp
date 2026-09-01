#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);          // 哑节点，简化头节点处理
        ListNode* tail = &dummy;    // 尾指针，用于构建新链表
        int carry = 0;              // 进位

        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;               // 计算进位
            tail->next = new ListNode(sum % 10); // 创建新节点
            tail = tail->next;
        }
        return dummy.next;  // 返回真正的头节点
    }
};

// 辅助函数：创建链表（用于测试）
ListNode* createList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// 测试主函数
int main() {
    Solution sol;
    // 示例：342 + 465 = 807，链表逆序表示：2->4->3 和 5->6->4
    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});
    ListNode* result = sol.addTwoNumbers(l1, l2);
    cout << "结果（逆序）：";
    printList(result);  // 输出 7 -> 0 -> 8

    // 释放内存（为简洁省略，实际项目中需注意）
    return 0;
}