#include<bits/stdc++.h>
#define ll long long

//Implementation Using array. 
template <typename T> 
class Stack
{
private:
    T *data; 
    int capacity;
    int top;
public:
    Stack(int size): capacity(size), top(-1) 
    {
        data = new T[capacity];
    }
    ~Stack() {
        delete[] data;
    }
    int push(T val) {
        try{ 
            top += 1;
            if(top >= capacity) {
                throw(std::out_of_range("Stack over flow."));
            }
            data[top] = val;
             
        }catch (const std::exception& e) {
            std::cerr << "Exception Caught: " << e.what() << std::endl;
            return 0;
        }
        return 1;
    }
    T pop(T val) {
        try {
            if(top == -1) {
                throw(std::out_of_range("Stack under flow.")); 
            } 
            top -= 1;
            return data[top];
        } catch (const std::exception& e) {
            std::cerr << "Exception Caught: " << e.what() << std::endl;
            return -1;
        }
    }
    int isEmpty () {
        return top == -1;
    }
    int isFull () {
        return top == capacity-1;
    }

};

//Implementation Using dynamic array and the array doubling technique. 
template <typename T> 
class DynArrayStack {
private:    
    T *data; 
    int top; 
    int capacity;
public:    
    DynArrayStack(): top(-1), capacity(2) {
        data = new T[capacity];
    }
    ~DynArrayStack() {
        delete[] data;
    }

    int push(T val) {
        if(top == capacity - 1) {
            capacity *= 2; 
            T *newData = new T[capacity]; 
            for(int i = 0; i <= top; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData; 
        }
        data[++top] = val;
        return data[top];  
    }
    T pop() {
        try {
            if(top == -1) {
                throw(std::out_of_range("Stack is Empty \n"));
            }
            top -= 1; 
        } catch (const std::exception& e) {
            std::cerr << "Exception Caught: " << e.what();
            return 0;
        }
        return data[top];
    }
    bool isEmpty () {
        return top == -1;
    }
    bool getSize() {
        return top + 1; 
    }
};



int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}