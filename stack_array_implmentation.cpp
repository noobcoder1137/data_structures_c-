// Noobcoder.com
// Source code for video tutorial series found here
// https://www.youtube.com/playlist?list=PLvTjg4siRgU1QGp46uraEBq2pM0AibYmk

#include <iostream>

using namespace std;

class StackArrayImpl{
    private:
        int size;
        int *stackArr;
        int top;
        void resize(){
            int tempSize = size * 2;
            int *temp = new int[tempSize];
            for(int i = 0; i < size;i++)
                temp[i] = stackArr[i];
            delete [] stackArr;
            stackArr = temp;
            size = tempSize;
        }
    public:
        StackArrayImpl(int size){
            this->size = size;
            stackArr = new int[size];
            top = -1;
        }

        ~StackArrayImpl(){
            delete [] stackArr;
        }

        void push(int data){
            //if stack is full, resize array
            if(top == size - 1)
                resize();
            // add data to the top of the stack
            stackArr[++top] = data;
        }
        // pop data of the stack
        int pop(){
            // if stack is empty, nothing to pop
            if(top == -1)
                return -1;
            // remove and return data from the top of the stack
            return stackArr[top--];
        }

};


int main(){
    StackArrayImpl test(3);
    test.push(1);
    test.push(2);
    test.push(3);
    cout << test.pop() << endl;
}

