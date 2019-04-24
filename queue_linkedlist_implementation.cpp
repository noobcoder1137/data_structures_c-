// NoobCoder.com
// Source code for video tutorial series found here
// https://www.youtube.com/playlist?list=PLvTjg4siRgU1bL3qJoaa6t5T_yUqqv-R9

#include <iostream>

using namespace std;


// Helper class for linkedlist
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }

};

// Queue Implemented using a linked list
/////////////////////////////////////////////////
class QueueLinkedListImpl{
    private:
        Node *front;
        Node *rear;

    public:
        QueueLinkedListImpl(){
            front = rear = NULL;
        }
        ~QueueLinkedListImpl(){
            Node *next;
            while(front != NULL){
                next = front->next;
                delete front;
                front = next;
            }
        }
        // adds data to the back of our queue
        void enqueue(int data){
            // create node that we're going to add to the back of queue
            Node *n = new Node(data);
            // if rear is null, our queue is empty
            // both front and rear point to the node we just created
            if(rear == NULL)
                rear = front = n;
            // add n to the back of our queue
            else{
                rear->next = n;
                rear = n;
            }
        }
        // removes and returns data from the front of our queue
        int dequeue(){
            // Our queue is empty, return -1
            if(front == NULL)
                return -1;
            // create temporary pointer to the current front
            Node *temp = front;
            // save data from the current front, so we can return it
            int tempData = front->data;
            // Only 1 element within our queue
            if(front == rear)
                front = rear = NULL;
            // advance front to the next node in line
            else
                front = front->next;
            // delete the old first node
            delete temp;
            // return data from the node we just removed
            return tempData;
        }
};




int main(){
    QueueLinkedListImpl queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;

}
