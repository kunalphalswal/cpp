#include<iostream>
using namespace std;
template <typename T>
class Vector{
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
    Vector<T>(int size=4){
        arr = new T[size];
        this->curSize = size;
        this->last=0;
    }
    void push_back(T elem){
        arr[last++] = elem;
        if(last==curSize){
            expand();
        }
    }
    int pop_back(){
        int elem = arr[last-1];
        last--;
        if(last == curSize/4){
            shrink();
        }
        return elem;
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
    int back(){
        return arr[last-1];
    }
};

int main(){
    Vector<int>vec;
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(9);
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.print();
    return 0;
}