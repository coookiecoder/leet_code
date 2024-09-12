#include <iostream>

using namespace std;

typedef struct listNode {
	int val;
	struct listNode* next;
} ListNode;

int list_size(ListNode* list) {
    int size = 0;

    while(list) {
        list = list->next;
        size++;
    }

    return (size);
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int result_buffer = 0;
        int carry = 0;

        ListNode* result = nullptr;
        ListNode* tail = nullptr;

        cout << "l1 size : " << list_size(l1) << endl;
        cout << "l2 size : " << list_size(l2) << endl;

        int max_size = max(list_size(l1), list_size(l2));

        for (int i = 0; i < max_size; ++i) {
            ListNode* new_node = new ListNode();
            if (!result) {
                result = new_node;
                tail = result;
            } else {
                tail->next = new_node;
                tail = tail->next;
            }
        }

        if (tail) {
            tail->next = nullptr;
        }

        tail = result;

        cout << "result size : " << list_size(result) << endl;

        while (l1 && l2) {
            result_buffer = l1->val + l2->val + carry;
            if (result_buffer > 9) {
                carry = 1;
                result_buffer -= 10;
            } else {
                carry = 0;
            }

            cout << "result buffer : " << result_buffer << endl;

            tail->val = result_buffer;

            l1 = l1->next;
            l2 = l2->next;
            if (tail->next) {
                tail = tail->next;
            }
        }

        if (l1) {
            while(l1) {
                result_buffer = l1->val + carry;
                if (result_buffer > 9) {
                    carry = 1;
                    result_buffer -= 10;
                } else {
                    carry = 0;
                }

                cout << "result buffer : " << result_buffer << endl;

                tail->val = result_buffer;

                l1 = l1->next;
                if (tail->next) {
                    tail = tail->next;
                }
            }
        }

        if (l2) {
            while(l2) {
                result_buffer = l2->val + carry;
                if (result_buffer > 9) {
                    carry = 1;
                    result_buffer -= 10;
                } else {
                    carry = 0;
                }

                cout << "result buffer : " << result_buffer << endl;

                tail->val = result_buffer;

                l2 = l2->next;
                if (tail->next) {
                    tail = tail->next;
                }
            }
        }

        if (carry == 1) {
            ListNode* new_node = new ListNode();
            tail->next = new_node;
            tail->next->val = 1;
            tail->next->next = NULL;
        }

        return result;
    }

    int list_size(ListNode* node) {
        int size = 0;
        while (node) {
            ++size;
            node = node->next;
        }
        return size;
    }
};


int main() {
	ListNode* L1 = new ListNode[7];
	ListNode* L2 = new ListNode[4];

	L1[0].next = L1 + 1;
	L1[1].next = L1 + 2;
	L1[2].next = L1 + 3;
	L1[3].next = L1 + 4;
	L1[4].next = L1 + 5;
	L1[5].next = L1 + 6;
	L1[6].next = NULL;

	L1[0].val = 9;
	L1[1].val = 9;
	L1[2].val = 9;
	L1[3].val = 9;
	L1[4].val = 9;
	L1[5].val = 9;
	L1[6].val = 9;

	L2[0].next = L2 + 1;
	L2[1].next = L2 + 2;
	L2[2].next = L2 + 3;
	L2[3].next = NULL;

	L2[0].val = 9;
	L2[1].val = 9;
	L2[2].val = 9;
	L2[3].val = 9;

	Solution solution;
			
	ListNode* result = solution.addTwoNumbers(L1, L2);

	cout << "result : ";

	while (result) {
		cout << result->val;
		result = result->next;
	}

	cout << endl;
}
