#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode():val(0), next(nullptr){}

    ListNode(int val):val(val), next(nullptr){}
};

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head, *fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main(){
    ListNode* head = new ListNode(3);

    head->next = new ListNode(5);

    head->next->next = new ListNode(7);

    head->next->next->next = new ListNode(2);

    cout << middleNode(head)->val << " ";
}