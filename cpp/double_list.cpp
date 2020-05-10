#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next = NULL;
    node *prev = NULL;
};
struct node *head = NULL;
struct node *cur = NULL;
void append_list(int data){
    node *newnode = new node;
    //struct node *newnode;
    newnode->data = data;

    if(head == NULL){
        head = newnode;
        cur = newnode;
    }   
    else{
        cur->next = newnode;
        newnode->prev = cur;
        cur = newnode;
    } 
}
void display_list(){
    node *beg = head;
    while(beg!=NULL){
        cout<<beg->data<<" ";
        beg = beg->next;

    }
    if(head==NULL){
        cout<<"Empty list here";
    }
}
void reverse(){
    
    node *beg = cur;
    while(beg!=NULL){
        cout<<beg->data<<" ";
        beg = beg->prev;
    }
}
int link_length(){
    node *beg = head;
    int pos = 0;
    while(beg!=NULL){
        pos++;
        beg = beg->next;
    }
    return pos;
}

void del_pos(int pos){
    int count = 0,l;
    l =link_length();
    node *beg = head;
    if(pos == 1){
        head = head->next;
        if(head !=NULL){
        head->prev = NULL;
        }
        display_list();
    }
    else if(pos > l){
        cout<<"Invalid choice";
    }
    else{
        while(beg != NULL){
            count++;
            if(count == pos){
                beg->prev->next = beg->next;
                if(beg->next!=NULL)
                    beg->next->prev = beg->prev;
                free(beg);
                break;
            }
            beg = beg->next;
        }
    display_list();    
    }
}

void del(){
    int ch;
    cout<<"Where do you want to delete \n1.Front\n2.Back";
    cin>>ch;
    if(ch==1){
        head = head->next;
    }
    else if(ch == 2){
        node *beg = head;
        if(head->next==NULL){
            head = NULL;
            free(head);
        }
        else{
        while(beg->next!=NULL){
            beg = beg->next;
        }
        beg = beg->prev;
        beg->next = NULL;
        }
    }
    display_list();
}
void delete_dup(){
    unordered_set <int> seen;
    
    node *beg = head;
    while(beg!=NULL){
        if(seen.find(beg->data)!=seen.end()){
            
            if(beg->next!=NULL)
                beg->next->prev = beg->prev;
            if(beg->prev!=NULL)
                beg->prev->next = beg->next;
        }
        else{
            seen.insert(beg->data);
        }
        beg = beg->next;
    }
    display_list();
}
int main(){
    unordered_set <int> seen;
    int ch,i,j;
    char choice;
    int data;
    do{
        cout<<"Enter your choice \n1.Add \n2.display\n3.Reverse and display\n4.Delete\n5.Delete at a pos\n6.Delete Duplicates";
        cin>>ch;
        if(ch==1){
            cout<<"Enter the data: ";
            cin>>data;
            append_list(data);
        }
        else if(ch==2){
            display_list();
        }
        else if(ch==3){
            reverse();
        }
        else if(ch==4){
            del();
        }
        else if(ch==5){
            cout<<"Enter position you wnat to delete: ";
            cin>>i;
            del_pos(i);
        }
        else if(ch==6){
            delete_dup();
        }
        cout<<"\nDo you want to continue";
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');
    return 1;
}