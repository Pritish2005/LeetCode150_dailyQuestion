#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
    int size;
    int *arr;
    int top;
    Stack(int size){
        this->size=size;
        arr=new int[size];
        this->top=-1;
    }

    void push(int data){
        // size-top -> gives if valid insertion
        // WARNING :CONDITION AND ORDER OF CODE
        if((size-top) > 1){
            top++;
            arr[top]=data;
        }
        else{
            // Bahar nikal jaye
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop(){
        if(top==-1){
            // Deep
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top--;
        }
    }
    int getTop(){
        if(top==-1){
            cout<<"No element remaining"<<endl;
            }
        else{
            return arr[top];
            }
    }
    int getSize(){
        // DUE TO 0 BASED INDEXING
        return top+1;
    }
    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

void print(stack<char>s){
    char temp=s.top();

    while(!s.empty()){
        temp=s.top();
        s.pop();
        cout<<temp<<" ";
    }
    cout<<endl;
}

void findMid(stack<char>&s,int size){
    // BC
    // Yes, s.size() exists
    if(s.size()==size/2+1){
        cout<<s.top()<<endl;
        return;
    }
    auto temp=s.top();
    s.pop();
    findMid(s,size);
    // BackTracking
    s.push(temp);

}

// void print(Stack s){
//     int temp=s.getTop();
//     while(!s.isempty()){
//         cout<<temp<<" ";
//         s.pop();
//         temp=s.getTop();
//     }
//     cout<<endl;
// }

int main()
{
    // Stack basic operations
    // Implement stack on own - push,pull,top,size,empty
    // 2 stack push simuntaneously
    // Reverse String (Try LL)
    // Mid Element

    // stack<int>s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // s.push(60);
    // s.push(70);
    // s.pop();
    
    // if(!s.empty()){
    //     cout<<"Not Empty"<<endl;
    // }

    // Stack s(10);
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.push(6);
    // // s.pop();
    // print(s);

    // 2 stack sim push -> push one at begin and one at end, top1++ & top2--, when top2-top1=1 -> stop

    stack<char>s;
    s.push('p');
    s.push('r');
    s.push('i');
    s.push('t');
    s.push('i');
    s.push('s');
    s.push('h');
    print(s);

    findMid(s,7);

    return 0;
}