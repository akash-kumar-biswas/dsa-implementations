#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode():val(0), next(nullptr){}

    ListNode(int val):val(val), next(nullptr){}
};

void display(ListNode* head){
    ListNode* curr = head;

    while(curr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode* reverse(ListNode* head){
    if(!head || !head->next)
        return head;
    
    ListNode* newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return newHead;
}

int main(){
    ListNode* head = new ListNode(3);

    head->next = new ListNode(5);

    head->next->next = new ListNode(7);

    head->next->next->next = new ListNode(2);

    display(head);

    head = reverse(head);

    display(head);
}
