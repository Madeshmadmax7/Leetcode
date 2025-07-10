#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
Node* head=NULL;
void createCycle(vector<int>arr,int pos){
    Node* newNode=new Node(arr[0]);
    Node* cycleNode=NULL;
    if(head==NULL){
        head=newNode;
    }
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        temp->next=new Node(arr[i]);
        temp=temp->next;
        if(i==pos){
            cycleNode=temp;
        }
    }
    if(pos==0){
        cycleNode=head;
    }
    if(pos!=-1){
        temp->next=cycleNode;
    }
}
bool isCycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }
    int pos;
    cin>>pos;
    createCycle(arr,pos);
    cout<<isCycle(head);
}