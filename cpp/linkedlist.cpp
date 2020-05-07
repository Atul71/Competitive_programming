#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *link = NULL;
    

};
struct node *head = NULL;
struct node *cur =NULL;
int link_append(int data){
    node *new_node = new node;
    new_node->data = data;
    
    if(head == NULL){
        new_node->link = NULL;
        head = new_node;
        cur = new_node;
        
    }
    else{
        cur->link = new_node;
        new_node->link = NULL;
        cur = new_node;
        
    }
    return 1;

}
int len_link(){
    int count = 0;
    node *beg = head;
    while(beg!=NULL){
        count+=1;
    }
    return count;
}
void del_pos(int pos){
    int len;
    len = len_link();
    if(pos>len){
        cout<<"Invalid position ";
    }
    else if(len == 0){
        cout<<"Linked list size is empty";
    }
    int count = 0;
    node *beg = head;
    node *prev = NULL;
    while(beg!=NULL){
        count+=1;
        
        if(count == pos){
            prev->link = beg->link;
        }
        prev = beg;
        beg = beg->link;
    }
}
int link_display(){
    struct node *disp = head;
    while(disp!=NULL){
        cout<<disp->data<<"-> ";
        disp = disp->link;
    }
    return 1;

}
void del_key(int d){

    node *beg = head;
    node *prev = NULL;
    while(beg!=NULL){
        if(beg->data == d){
            prev->link = beg->link;
        }
        prev = beg;
        beg = beg->link;
    }
}
void reverse(){
    struct node *curr = head;
    struct node *next = NULL;
    struct node *prev = NULL;
    while(curr!=NULL){
        
        next = curr->link;
        
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    
    struct node *disp = prev;
    while(disp!=NULL){
        cout<<disp->data<<"-> ";
        disp = disp->link;
    }
}
int palindrome(){
    stack <int> s;
    node *cur = head;
    while(cur!=NULL){
        s.push(cur->data);
        cur = cur->link;
    }
    int i;
    cur = head;
    while(cur!=NULL){
        i = s.top();
        if(i!=cur->data){
            return 0;
        
        }
        s.pop();
        cur = cur->link;
        
    }
    return 1;
}
void rem_dup_sort(){
    cout<<"function wont work without sorted list\n";
    node *cur = head;
    node *prev = NULL;
    int prev_data = 0;
    while(cur!=NULL){
        if(cur->data==prev_data and prev!=NULL){
            prev->link = cur->link;
            
        }
        else{
            prev = cur;
        }
        prev_data = prev->data;
        
        cur = cur->link;
    }
    link_display();
}
void rem_unsort(){
    unordered_set<int> seen;
    node *cur = head;
    node *prev = NULL;
    while(cur!=NULL){
        if(seen.find(cur->data)!=seen.end()){
            prev->link = cur->link;
            //free(cur);
        }
        else{
            seen.insert(cur->data);
            prev = cur;
        }
        
        cur = cur->link;
        

    }
    link_display();
}
int main(){
    int ch, i, d, pos_no;
    char choice;
    do{
    cout<<"\n1.add at the end \n2.display the linkedlist \n3. Delete with key\n4. Delete a position\n5.Display reverse Loop\n6.Palindrome\n";
    cout<<"7.Remove duplicates from sorted list(enter sorted list)\n8.Remove duplicates from unsorted list";
    cin>>ch;
    
    if(ch==1){
        cout<<"Enter the data you want to enter";
        cin>>d;
        link_append(d);
    }
    else if(ch==2){
        link_display();
    }
    else if(ch==3){
        cout<<"Enter the data you want to delete:";
        cin>>d;
        del_key(d);
    }
    else if(ch==4){
        cout<<"Enter the position number";
        cin>>pos_no;
        del_pos(pos_no);
    }
    else if(ch==5){
        reverse();
    }
    else if(ch==6){
        if(palindrome()){
            cout<<"The linked list is a palindrome";
        }
        else{
            cout<<"Linked list is not a palindrome";
        }
    }
    else if(ch==7){
        rem_dup_sort();
    }
    else if(ch==8){
        rem_unsort();
    }
    cout<<"Do you want to continue Y or N: ";
    cin>>choice;
    }while(choice=='y' || choice=='Y');
    return 1;

}