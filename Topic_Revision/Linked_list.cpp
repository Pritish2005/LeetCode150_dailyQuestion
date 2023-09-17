#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node(){
    this->data=0;
    this->next=NULL;
  }
  Node(int data){
    this->data=data;
    this->next=NULL;
  }
};

// Node* insert(){
//   // data creation and condition
//   int data;
//   cin>>data;
//   if(data==-1){
//     return NULL;
//   }
//   // node creation and recursion
//   Node*temp=new Node(data);
//   temp->next=insert();
//   return temp;
// }

void print(Node* head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}

void insertAthead(Node* &head,Node* &tail,int data){
  // Edge Cases
  if(head == NULL) {
    Node* newNode = new Node(data);
    head = newNode;
    tail= newNode;
    return;
  }

  Node* temp=new Node(data);
  temp->next=head;
  head=temp;
}

void insertAtTail(Node* &head,Node* &tail,int data){
  // Edge Cases
  if(head == NULL) {
    Node* newNode = new Node(data);
    head = newNode;
    tail= newNode;
    return;
  }

  Node* temp=new Node(data);
  tail->next=temp;
  tail=temp;
}

int findLength(Node* & head){
  Node* temp=head;
  int length=0;
  while(temp!=NULL){
    length++;
    temp=temp->next;
  }
  return length;
}

void insertAtPosition(Node* &head,Node* &tail,int postion,int data){
  // Find that postion(curr & prev mark)
  // Create node
  // newNode->next=curr
  // prev->next=newNode
  // optimistation
if(postion==0){
  insertAthead(head,tail,data);
  return;
}
if(postion>=findLength(head)){
  insertAtTail(head,tail,data);
}

  Node* prev=head;
  // Start i from 1
  int i=1;
  while(i<postion){
    prev=prev->next;
    i++;
  }
  Node* curr=prev->next;
  Node* newNode=new Node(data);
  newNode->next=curr;
  prev->next=newNode;
}

void deletion(Node* &head,int postion){
  Node* prev=head;
  // Start i from 1
  int i=1;
  while(i<postion){
    prev=prev->next;
    i++;
  }
  Node* curr=prev->next;
  prev->next=curr->next;
  curr->next=NULL;
  delete curr;
}

Node* reverseLinkedList(Node* prev, Node* curr) {
  // RECC
  // //base case
  // if(curr == NULL) 
  //   return prev;
  // Node* temp = curr ->next;
  // curr ->next = prev;
  // //recursion sambhal lega
  // return reverseLinkedList(curr, temp);

  // ITERATION
  while(curr!=NULL){
    Node* forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
  }
  return prev;
}

int findMid(Node* head){
  // BC
  if(head==NULL){
    cout<<"Enter valid data"<<endl;
  }
  if(head->next==NULL){
    return head->data;
  }
  Node* temp=head;
  Node* slow=head;
  // TO GET THE MIDDLE ELEMENT
  Node* fast=head->next;
  while(fast!=NULL && slow!=NULL){
    // CAUTION: MAKE SURE OF CONDITIONS
    fast=fast->next;
    if(fast!=NULL){
      fast=fast->next;
      slow=slow->next;
    }
  }
  return slow->data;
}

Node* reverseKGroup(Node* &head,int k){
  // k node reverse
  // head->next=recc ka ans
  // return prev
  if(head==NULL){
    cout<<"Linked List Empty"<<endl;
    return NULL;
  }
  int len=findLength(head);
  if(k>len){
    return head;
  }

  Node* prev=NULL;
  Node* curr=head;
  Node* forward=curr->next;
  int count=0;
  while(count<k && curr!=NULL){
    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
    count++;
  }

  if(forward!=NULL){
    // CAUTION: {WHAT KA} -> NEXT
    head->next=reverseKGroup(forward,k);
  }

  return prev;
}

Node* floydDetectionCycle(Node* &head){
  Node* slow=head;
  Node* fast=head;
  while(fast!=NULL){
      fast=fast->next;
      if(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
      }
      if(slow==fast){
        slow=head;
        break;            
      }
  }
  Node* prev=fast;

  while(slow!=fast){
    if(slow!=fast){
      prev=fast;
    }
    fast=fast->next;
    slow=slow->next;
  }
  prev->next=NULL;
  return slow;
}

int main() {
  // Node* head=insert(20);
  // Node* head=NULL;
  // Node* tail=NULL;
  // insertAthead(head,tail,10);
  // insertAtTail(head,tail,20);
  // insertAtTail(head,tail,30);
  // insertAtTail(head,tail,40);
  // insertAtTail(head,tail,50);
  // insertAtTail(head,tail,70);
  // insertAtTail(head,tail,75);
  // insertAtTail(head,tail,80);
  // insertAtPosition(head,tail,5,60);
  // deletion(head,7);
  // insertAtTail(head,tail,50);
  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(40);
  Node* fifth = new Node(50);
  Node* sixth = new Node(60);
  Node* seventh = new Node(70);
  Node* eighth = new Node(80);
  Node* ninth = new Node(90);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  sixth -> next = seventh;
  seventh -> next = eighth;
  eighth -> next = ninth;
  ninth -> next = fourth;



  // Before priniting
  // cout<<"Printing before: "<<endl;
  // print(head);
  // cout<<endl;

  // Reverse A Linked List
  // Node* prev=NULL;
  // Node* curr=head;
  // head=reverseLinkedList(prev,curr);


// Reverse K nodes
  // int k=0;
  // head=reverseKGroup(head,k);

  Node* ans=floydDetectionCycle(head);
  cout<<"Loop starts at: "<<ans->data<<endl;

  // after Printing
  cout<<"Printing after: "<<endl;
  print(head);
  cout<<endl;

  // int ans=findMid(head);
  // cout<<"Mid element is: "<<ans<<endl;

  return 0;
}