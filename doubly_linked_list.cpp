// NoobCoder.com
// source code for video tutorial series found here
// https://www.youtube.com/playlist?list=PLvTjg4siRgU02UgV08owYouXQSZO1a5W3

#include <iostream>

using namespace std;

class Node{
    public :
        int data;
        Node *next;
        Node *prev;
        Node(int data){
            this->data = data;
            next = NULL;
            prev = NULL;
        }
};

class LinkedList{
    private :
        Node *header;
        Node *tail;
        int size;

    public :
        LinkedList(){
            header = NULL;
            tail = NULL;
            size = 0;
        }

        ~LinkedList(){
            Node *next;
            while(header != NULL){
                next = header->next;
                delete header;
                header = next;
            }
        }

        void append(int data){
            // Create node to be inserted
            Node *n = new Node(data);
            // Case 1: check if list is empty
            if(header == NULL){
                header = n;
                tail = n;
            }
            // Case 2: check if list is not empty
            else{
                tail->next = n;
                n->prev = tail;
                tail = n;


            }
            size++;
        }

        void prepend(int data){
            // create node to be inserted
            Node *n = new Node(data);
            // case 1: check if list is empty
            if(header == NULL){
                header = n;
                tail = n;
            }
            // case 2: check if list is not empty
            else{
                header->prev = n;
                n->next = header;
                header = n;
            }
            // increment the size
            size++;
        }

        int getSize(){
            return size;
        }

        void removeLast(){
            // Case 1: check if list has 1 node
            if(header->next == NULL){
                // delete the node
                delete header;
                // set header and tail to NULL
                header = NULL;
                tail = NULL;
                size--;
            }
            // Case 2: check if list has more than 1 node
            else if(header != NULL){
                // advance tail pointer to previous node before it
                tail = tail->prev;
                // delete the previous last node
                delete tail->next;
                // set the current last node next pointer to NULL
                tail->next = NULL;
                // decrement the size
                size--;
            }
        }

        void removeAt(int pos){
            //Case 1: check if position is a valid position
            if(pos < 1 || pos > size)
                return;
            //Case 2: check if position is first node
            else if(pos == 1)
                removeFirst();
            //Case 3: check if position is last node
            else if(pos == size)
                removeLast();
            //Case 4: check if position is between first and last node
            else if(header != NULL){
                Node *cur = header;
                for(int i = 1; i < pos; i++)
                    cur = cur->next;
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
                size--;

                    
            }











        }

        void toString(){
            // Create a temp pointer 
            // that points to first Node
            Node *temp = header;
            // Create Loop That stops when pointer is NULL
            while(temp != NULL){
                // Print data
                cout << temp->data << " ";
                // Advance Pointer to next node
                temp = temp->next;
            }
            cout << endl;
                
        }

        void toStringReverse(){
            // Create a temp pointer that points to the tail
            Node *n = tail;
            // Create a loop that keeps executing till pointer is NULL
            while(n != NULL){
                // print data
                cout << n->data << " ";
                // advance pointer to next node
                n = n->prev;
            }
            cout << endl;
        }

        void removeFirst(){
            // check if only one node within list
            if(header->next == NULL){
                delete header;
                header = NULL;
                tail = NULL;
                size--;
            }
            // check if more than one node within list
            else if(header != NULL){
                header = header->next;
                delete header->prev;
                header->prev = NULL;
                size--;
                

            }
        }
        // insert node at a certain position
        void insertAt(int pos,int data){
            // Case 1: Check to see if valid position
            if(pos < 1 || pos > size + 1)
                return;
            // Case 2: Check if insertion is in the beginning of the list
            else if(pos == 1)
                prepend(data);
            // Case 3: Check if insertion is at the end of the list
            else if(pos == size + 1)
                append(data);
            // Case 4: If position is between the beginning and end of the list
            else if(header != NULL){
                Node *n = new Node(data);
                Node *cur = header;
                for(int i = 1; i < pos; i++)
                    cur = cur->next;
                
                cur->prev->next = n;
                n->prev = cur->prev;

                n->next = cur;
                cur->prev = n;

                size++;
            }
             














        }
};

int main(){
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.insertAt(3,20);
    list.toString();
}
