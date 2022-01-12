#include<iostream>
using namespace std;
class circular_dll{
struct node{
int data;
node*next;
node*prev;
};
node*last;
node*start;
public:
    circular_dll(){
    last=NULL;
    start=NULL;
    }
    void insertatfirst(int data){
    node*n=new node;
    n->data=data;
    if(last==NULL){
        n->next=n;
        n->prev=n;
        last=n;
    }
    else{
            node*t=last->next;
        n->next=last->next;
        t->prev=n;
        last->next=n;
        n->prev=last;
    }
    }
    void insertatlast(int data){
    node*n=new node;
    n->data=data;
    if(last==NULL){
        n->prev=n;
        n->next=n;
        start=n;
        last=n;
    }else{
        node*t=last->next;
    n->next=last->next;
    t->prev=n;
    last->next=n;
    n->prev=last;
    last=n;
    }
    }
void display(){
node*t=start;
do{
    cout<<t->data;
    t=t->next;
}while(t!=start);

}
void reverse(){
node*cur=start;
node*t=NULL;
do{
    t=cur->next;
    cur->next=cur->prev;
    cur->prev=t;
    cur=cur->prev;
}while(cur!=start);
//nextnode->next=last;
swap(start,last);
}
};
int main(){
circular_dll obj;
obj.insertatlast(1);
obj.insertatlast(2);
obj.insertatlast(3);
obj.insertatlast(4);
obj.reverse();
obj.display();


return 0;
}
