// Noobcoder.com
// Source code for video tutorial series found here
// https://www.youtube.com/playlist?list=PLvTjg4siRgU197GA1yFNRWUgsPZnvjuyL

#include <iostream>

using namespace std;


class BinaryMinHeap {

    private:
      int *heap;
      int heapSize;
      int arraySize;

      int getLeftChild(int index) {
          return 2 * index + 1;
      }

      int getRightChild(int index) {
          return 2 * index + 2;
      }

      int getParent(int index) {
        return (index - 1) / 2;
      }

      bool hasRight(int index){
        return getRightChild(index) < heapSize;
      }

      bool hasLeft(int index){
        return getLeftChild(index) < heapSize;
      }

    public:
      BinaryMinHeap(int size) {
        heap = new int[size];
        heapSize = 0;
        arraySize = size;
      }

    // for insertion
    void heapifyUp(int index) {
        if (index != 0){
            // get parent of the current node we're at
            int parent = getParent(index);
            // if the parent is greater than the node we're at
            if (heap[parent] > heap[index]) {
                // swap between parent and child
                swap(parent,index);
                // go up our tree, to continue heapifying it
                heapifyUp(parent);
            }
        }
    }
    // helpper method, swaps between 2 indicies of our heap
    void swap(int i,int j){
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
    // inserts data within our heap
    void insert(int data) {
      // array is full, so we can't insert
      if (heapSize == arraySize)
        return;
      else {
        // increment heapSize since we're inserting data
        heapSize++;
        // insert the data at the right most position on the last
        // level of our tree
        heap[heapSize - 1] = data;
        // call our heapifyUp method to heapify our tree.
        heapifyUp(heapSize - 1);
      }
    }

    // removes and returns the root node
    int removeMin(){
        // empty heap, nothing to return
        if(heapSize == 0)
            return -1;
        else{
            // save data from node we're going to delete
            int root = heap[0];
            // replace our root node with right most node, on the last level
            // of our tree
            heap[0] = heap[heapSize - 1];
            // decrement the heapsize since, we've removed the node
            heapSize--;
            // if the heapsize is greater than 1, we need to heapify our tree
            if (heapSize > 1)
              heapifyDown(0);
            // return data from the node we just removed
            return root;
        }

    }
    // for deletion
    void heapifyDown(int index){
      // get left and right child indicies of current node
      int leftChild = getLeftChild(index);
      int rightChild = getRightChild(index);
      // We need to find out if the node we're currently at is in the right position
      // set the min to the current node we're at
      int min = index;
      // if the left child is smaller than the current node we're at, the left child becomes the min
      if(hasLeft(index) && heap[leftChild] < heap[min])
        min = leftChild;
      // if the right child is smaller than the current node we're at, the right child becomes the min
      if(hasRight(index) && heap[rightChild] < heap[min])
        min = rightChild;
      // Executes if either the left or right child is smaller than the node we're currently at
      if (min != index) {
        // swap between parent and child
        swap(index,min);
        // recursively go down our tree, continueing to heapify
        heapifyDown(min);
	  }
    }


};
int main(){
   BinaryMinHeap heap(5);
   heap.insert(12);
   heap.insert(20);
   heap.insert(9);
   heap.insert(5);
   heap.insert(20);
   cout << heap.removeMin() << endl;
}
