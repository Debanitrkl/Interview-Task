#include<bits/stdc++.h>
using namespace std;
 
struct Node {
  int val;
  Node *next;
  Node() : val(0), next(nullptr) {}
  Node(int x) : val(x), next(nullptr) {}
  Node(int x, Node *next) : val(x), next(next) {}
};
 
 
Node* reverseBetween(Node* head, int left, int right)
{
       Node *dummy = new Node(0), *pre = dummy, *cur;
       dummy -> next = head;
       for (int i = 0; i < left - 1; i++) {
           pre = pre -> next;
       }
       cur = pre -> next;
       // reversing using pointers
       for (int i = 0; i < right - left; i++) {
           Node* temp = pre -> next;
           pre -> next = cur -> next;
           cur -> next = cur -> next -> next;
           pre -> next -> next = temp;
       }
 
       // to prevent memory leak
       Node* temp = dummy -> next;
       delete dummy;
       return temp;
}
 
void push(Node** head_ref, int new_val)
{
    Node* new_node = new Node;
    new_node->val = new_val;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
// printing the linked list
void show(Node* head)
{
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    printf("\n");
}
 
 
 
int main() {
 
    Node* head = NULL;
    for(int i=1; i<10; i++)
        push(&head, i*10);
 
    cout << "Before reversing in the interval:\n";
    show(head);
 
    int left, right;
    // taking input from std
    cin >> left >> right;
 
    reverseBetween(head, left, right);
    show(head);
 
    // outputs for different inputs:
    // (4, 7) : 90 80 70 30 40 50 60 20 10 
 
    // (2, 3) : 90 70 80 60 50 40 30 20 10 
 
    // (8, 9) : 90 80 70 60 50 40 30 10 20  
 
 
 
 
return 0;
}