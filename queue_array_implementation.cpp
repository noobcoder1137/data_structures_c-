// NoobCoder.com
// Source code for video tutorial series found here
// https://www.youtube.com/playlist?list=PLvTjg4siRgU1bL3qJoaa6t5T_yUqqv-R9

#include <iostream>

using namespace std;

// array implementation of a queue
//////////////////////////////////
class QueueArrImpl{
    private:
        int front,rear,numOfElements,size;
        int *queueArr;

        void resize(){
            int tempSize = size * 2;
            int *tempArr = new int[tempSize];
            for(int i = 0; i < size; i++){
                tempArr[i] = queueArr[(front + i) % size];
            }

            delete [] queueArr;
            queueArr = tempArr;

            front = 0;
            rear = size - 1;

            size = tempSize;
        }


    public:
        QueueArrImpl(int size){
            front = rear = -1;
            this->size = size;
            queueArr = new int[size];
            numOfElements = 0;
        }
        ~QueueArrImpl(){
            delete [] queueArr;
        }
        // add data to the back of the queue
        void enqueue(int data){
            // means theres no more space
            if(numOfElements == size)
                resize();
            // means are queue is empty
            // set both front and rear equal to 0 for insertion
            if(front == -1 && rear == -1)
                front = rear = 0;
            // generate rear index to insert at
            else
                rear = (rear + 1) % size;
            // add data to the back of the queue
            queueArr[rear] = data;
            // increment number of elements since we added data to the queue
            numOfElements++;
        }
        // return and remove from the front of our queue
        int dequeue(){
            // nothing to remove, return -1 to symbolize queue is empty
            if(numOfElements == 0)
                return -1;
            else{
                int temp = queueArr[front];
                // if front is rear, that means only one element within
                // our queue. Set rear and front to -1 to symbolize
                // empty queue
                if(front == rear)
                    rear = front = -1;
                else
                // generate new front index
                    front = (front + 1) % size;
                // decrement number of elements within our queue
                numOfElements--;
                return temp;

            }
        }
};

int main(){
    QueueArrImpl queue(3);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;

}
