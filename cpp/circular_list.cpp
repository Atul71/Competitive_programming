#include<iostream>

using namespace std;

struct node{
    int data;
    node *link = NULL;

};
struct node *head = NULL;
struct node *last = NULL;
void append_list(int data){
    struct node *newnode = new node;
    newnode->data = data;
    if(head == NULL){
        head = newnode;
        newnode->link = newnode;
        last = newnode;
    }
    else{
        last->link = newnode;
        last = newnode;
        newnode->link = head;
    }

}
int list_length(){
    node *beg = head;
    int pos = 1;
    do{
        
        beg = beg->link;
        pos++;

    }while(beg!=head);
    
    return pos;
}
void split_list(){
    int l,p;
    p = 0;
    node *head1 = head;
    node *end2 = last;
    node *end1;
    node *head2;
    node *beg = head;
    l = list_length();
    while(p<(l/2)-1){
        beg = beg->link;
        p++;
    }
    end1 = beg;
    head2 = beg->link;
    end1->link = head1;
    last->link = head2;
    
    node *cur = head1;
    do{
        cout<<cur->data<<' ';
        cur = cur->link;


    }while(cur!=head1);
    cout<<"Second list is ";
    cur = head2;
    do{
        cout<<cur->data<<' ';
        cur = cur->link;


    }while(cur!=head2);
}
void display_list(){
    node *beg = head;
    do{
        cout<<beg->data<<' ';
        beg = beg->link;


    }while(beg!=head);
}
void delete_list(){
    node *beg = head;
    if(head == NULL){
        cout<<"Empty list";
    }
    else if(head == last){
        cout<<head->data;
        head = NULL;
        last = NULL;
    }
    else{
    do{
        beg = beg->link;
    }while(beg->link->link!=head);
    beg->link = head;
    last = beg->link;
    display_list();
    }
}
void check_list(){
    node *cur;
    node *adv;
    cur = head;
    do{
        if(cur==NULL)
            cout<<"Not circular list";
        cur = cur->link;
    }while(cur!=head);
    if(cur == head)
        cout<<"Circular list\n";        
}
void reverse_link(){
   
   node *temp;
   node *cur = head;
   node *next = head;
   node *prev = last;
   do{
       next = cur->link;
       cur->link = prev;
       prev = cur;
       cur = next;
   }while(cur!=head);
   temp = head;
   head = last;
   last = temp;
   display_list();
}
int main(){
    int i,j,ch;
    int d;
    char choice;
    do{
        cout<<"Enter your choice\n1.Add elements\n2.Display Elements\n3.Split into two\n4.length\n5.Delete\n6.Check circular \n7.Reverse link list";
        cin>>ch;
        if(ch==1){
            cout<<"Enter the data to be entered";
            cin>>d;
            append_list(d);
        }
        else if(ch==2){
            display_list();
        }
        else if(ch==3){
            split_list();
        }
        else if(ch==4){
            cout<<list_length();
        }
        else if(ch==5){
            delete_list();
        }
        else if(ch==6){
           check_list();
        }
        else if(ch==7){
            reverse_link();
        }
    cout<<"Do you want to continue";
    cin>>choice;
    }while(choice == 'y' || choice == 'Y');
}