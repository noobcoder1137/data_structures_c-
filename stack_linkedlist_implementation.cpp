// Noobcoder.com
// Source code for video tutorial series found here
// https://www.youtube.com/playlist?list=PLvTjg4siRgU1QGp46uraEBq2pM0AibYmk

#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }

};

class StackLinkedListImpl{
    private:
        Node *top;
    public:
        StackLinkedListImpl(){
            top = NULL;
        }

        ~StackLinkedListImpl(){
            // pointer which always points to the next node within our list
            Node *next;
            // keep going until top does not equal NULL
            while(top != NULL){
                // advance to pointer to point to next node
                next = top->next;
                // delete node that top is pointing to
                delete top;
                // advance top to point to the next node
                top = next;
            }
        }
        // pushes data on top of the stack
        void push(int data){
            // Creates node with the data being passed in
            Node *n = new Node(data);
            // if stack is empty, top points to our newly created node
            if(top == NULL)
                top = n;
            // if stack is not empty
            else{
                n->next = top;
                top = n;
            }
        }

        // removes node on top of the stack, and returns the data
        int pop(){
            // Its an empty stack, return -1
            if(top == NULL)
                return -1;
            // Not an empty stack
            else{
                int tempData = top->data;
                Node *temp = top;
                top = top->next;
                delete temp;
                return tempData;
            }
        }

};

int main(){
    StackLinkedListImpl test;
    test.push(1);
    test.push(2);
    test.push(3);
    cout << test.pop() << endl;

}