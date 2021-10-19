#include<iostream>
using namespace std;

class stack{
    int arr[10000];
    int top_idx;

public:
    stack(){
        top_idx=-1;
    }

    void push(int val){
        if(top_idx+1 < 10000){
            ++top_idx;
            arr[top_idx]=val;
        }
        else{
            cout<<"Stack Overflow\n";
        }
    }

    void pop(){
        if(top_idx==-1){
            cout<<"Stack Underflow\n";
        }
        else{
            --top_idx;
        }
    }

    int top(){
        //It will give error if stack is empty
        return arr[top_idx];
    }

    int size(){
        return top_idx+1;
    }
};

int main(){
    stack st;
    st.push(11);
    cout<<"Stack size is "<<st.size()<<"\n";
    cout<<"Stack top element is "<<st.top()<<"\n";
    st.pop();
    cout<<"Stack size is "<<st.size()<<"\n";
    return 0;
}