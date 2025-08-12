#include<iostream>
using namespace std;

template<typename T>
class Stack{
private:
    int curSize;
    int last;//insert coming element here
    T * arr;
    void expand(){
        T* newArr = new T[curSize*2];
        for(int i=0;i<last;i++){
            newArr[i]=arr[i];
        }
        curSize*=2;
        auto temp = arr;
        arr = newArr;
        delete(temp);
    }
    void shrink(){
        T* newArr = new T[curSize/2];
        for(int i=0;i<last;i++){
            newArr[i]=arr[i];
        }
        curSize/=2;
        auto temp = arr;
        arr = newArr;
        delete(temp);
    }
public:
    Stack<T>(){
        arr = new T[4];
        this->curSize = 4;
        this->last=0;
    }
    void push(T elem){
        arr[last++] = elem;
        if(last==curSize){
            expand();
        }
    }
    int pop(){
        int elem = arr[last-1];
        last--;
        if(last == curSize/4){
            shrink();
        }
        return elem;
    }
    int top(){
        return arr[last-1];
    }
    int size(){
        return last;
    }
    void print(){
        for(int i=0;i<last;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        cout<<last<<" "<<curSize<<"\n";
    }
    bool empty(){
        return last==0;
    }
};

int main(){
Stack<int>vec;
    vec.push(4);
    vec.push(3);
    vec.push(9);
    vec.push(4);
    vec.push(3);
    vec.push(9);
    vec.push(4);
    vec.push(3);
    vec.push(9);
    vec.push(4);
    vec.push(3);
    vec.push(9);
    vec.push(4);
    vec.push(3);
    vec.push(9);
    vec.pop();
    vec.pop();
    vec.pop();
    vec.pop();
    vec.pop();
    vec.pop();
    vec.pop();
    vec.pop();
    vec.pop();
    vec.pop();
    vec.pop();
    vec.pop();
    vec.pop();
    vec.print();
    return 0;
}