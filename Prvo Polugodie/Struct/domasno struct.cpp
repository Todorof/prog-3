#include <iostream>
using namespace std;

struct Node{int val;Node*next;};
struct linkedList{Node*head;linkedList(){head=nullptr;}};

void insertNode(linkedList&,int);
void insertNodeSorted(linkedList&,int);
void removeNode(linkedList&,int,bool=false);
void outputList(linkedList&);
void mergeSortedLists(linkedList&,linkedList&,linkedList&);
void bubbleSort(linkedList&);
void insertionSort(linkedList&);

void insertNode(linkedList&l,int v){
    Node*n=new Node{v,nullptr};
    if(!l.head) {
        l.head=n;
        return;
    }
    Node*p=l.head;
    while(p->next)p=p->next;
    p->next=n;
}

void insertNodeSorted(linkedList&l,int v){
    Node*n=new Node{v,nullptr};
    if(!l.head||v<l.head->val) {
        n->next=l.head;l.head=n;
        return;
    }
    Node*p=l.head;
    while(p->next&&p->next->val<v)p=p->next;
    n->next=p->next;
    p->next=n;
}

void removeNode(linkedList&l,int v,bool all){
    while(l.head&&l.head->val==v){
        Node*t=l.head;
        l.head=l.head->next;
        delete t;
        if(!all) return;
    }
    Node*p=l.head;
    while(p&&p->next){
        if(p->next->val==v){
            Node*t=p->next;
            p->next=t->next;
            delete t;
            if(!all) return;
        }else p=p->next;
    }
}

void outputList(linkedList&l){
    Node*p=l.head;
    while(p) {
        cout<<p->val<<" ";p=p->next;
    }
    cout<<"\n";
}

void mergeSortedLists(linkedList&A,linkedList&B,linkedList&R){
    Node*a=A.head;
    Node*b=B.head;
    Node*t=nullptr;
    R.head=nullptr;
    while(a||b){
        int v;
        if(!b||(a&&a->val<b->val)) {
            v=a->val;a=a->next;
        }
        else if(!a||(b&&b->val<a->val)) {
            v=b->val;b=b->next;
        }
        else {
            v=a->val;a=a->next;b=b->next;
        }
        if(!R.head||t->val!=v){
            Node*n=new Node{v,nullptr};
            if(!R.head)R.head=n;
            else t->next=n;
            t=n;
        }
    }
}

void bubbleSort(linkedList&l){
    if(!l.head)return;
    bool s;
    do{
        s=false;
        Node*p=l.head;
        while(p->next){
            if(p->val>p->next->val){
                swap(p->val,p->next->val);
                s=true;
            }
            p=p->next;
        }
    }while(s);
}

void insertionSort(linkedList&l){
    Node*s=nullptr;Node*c=l.head;
    while(c){
        Node*n=c->next;
        if(!s||c->val<s->val) {
            c->next=s;s=c;
        }else{
            Node*p=s;
            while(p->next&&p->next->val<c->val)p=p->next;
            c->next=p->next;
            p->next=c;
        }
        c=n;
    }
    l.head=s;
}

struct DNode{int val;DNode*next;DNode*prev;};
struct doublyList{DNode*head;DNode*tail;doublyList(){head=tail=nullptr;}};

void addNode(doublyList&,int,int=-1);
void removeNode(doublyList&,int);
DNode*search(doublyList&,int);
void outputList(doublyList&);

void addNode(doublyList&l,int v,int pos){
    DNode*n=new DNode{v,nullptr,nullptr};
    if(!l.head) {
        l.head=l.tail=n;return;
    }
    if(pos<=0) {
        n->prev=l.tail;
        l.tail->next=n;
        l.tail=n;
        return;
    }
    DNode*p=l.head;
    int i=0;
    while(p->next&&i<pos-1) {
        p=p->next;i++;
    }
    n->next=p->next;
    n->prev=p;
    if(p->next)p->next->prev=n;
    else l.tail=n;
    p->next=n;
}

void removeNode(doublyList&l,int v){
    DNode*p=l.head;
    while(p){
        if(p->val==v){
            if(p->prev) p->prev->next=p->next;
            else l.head=p->next;
            if(p->next) p->next->prev=p->prev;
            else l.tail=p->prev;
            delete p;
            return;
        }
        p=p->next;
    }
}

DNode*search(doublyList&l,int v){
    DNode*p=l.head;
    while(p){
        if(p->val==v)return p;
        p=p->next;
    }
    return nullptr;
}

void outputList(doublyList&l){
    cout<<"Od pocetok: ";
    DNode*p=l.head;
    while(p) {
        cout<<p->val<<" ";p=p->next;
    }
    cout<<"\n";
    cout<<"Od kraj: ";
    p=l.tail;
    while(p) {
        cout<<p->val<<" ";
        p=p->prev;
    }
    cout<<"\n";
}

int main(){

    cout<<"Zadaca 1: Sortirano vnesuvanje \n";
    linkedList L;
    int x;
    cout<<"Vnesuvaj broevi (-1 za kraj): ";
    while(cin>>x&&x!=-1)
        insertNodeSorted(L,x);
    cout<<"Sortirana lista: ";
    outputList(L);

    cout<<"\n Zadaca 2: Spojuvanje na dve sortirani listi bez duplikati \n";
    linkedList L1,L2,M;
    insertNodeSorted(L1,1);
    insertNodeSorted(L1,3);
    insertNodeSorted(L1,5);
    insertNodeSorted(L2,2);
    insertNodeSorted(L2,3);
    insertNodeSorted(L2,4);
    cout<<"Lista 1: ";
    outputList(L1);
    cout<<"Lista 2: ";
    outputList(L2);
    mergeSortedLists(L1,L2,M);
    cout<<"Spoena lista: ";
    outputList(M);

    cout<<"\n Zadaca 3: Bubble i Insertion Sort na lista \n";
    linkedList L3;
    insertNode(L3,5);
    insertNode(L3,2);
    insertNode(L3,8);
    insertNode(L3,1);
    cout<<"Pocetna lista: ";
    outputList(L3);
    bubbleSort(L3);
    cout<<"Po Bubble sort: ";
    outputList(L3);
    insertNode(L3,4);
    insertNode(L3,7);
    insertionSort(L3);
    cout<<"Po Insertion sort: ";
    outputList(L3);

    cout<<"\n Zadaca 4: Dvojno povrzana lista (add, remove, search) \n";
    doublyList D;
    addNode(D,10);
    addNode(D,20);
    addNode(D,30);
    addNode(D,15,1);
    cout<<"Po dodavanje:\n";
    outputList(D);
    removeNode(D,20);
    cout<<"Po brisenje (20):\n";
    outputList(D);
    DNode*f=search(D,15);
    if(f) cout<<"Pronajden element: "<<f->val<<"\n";
    else cout<<"Element ne e pronajden\n";

    return 0;
}
