#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class PriorityQueue{
    private:
        vector<int> heap;

    public:
        PriorityQueue(){}

        void insert(int key){
            heap.push_back(key);
            int i = heap.size()-1;
            while(i > 0 && heap[(i-1)/2] < heap[i]){
                swap(heap[i], heap[(i-1)/2]);
                i = (i-1)/2;
            }
        }

        void buildHeap(vector<int> &data){
            for(int val : data)
                insert(val);
        }

        void printHeap(){
           if(heap.size() == 0) return;
           cout<<heap[0] << endl;
            int i = 0;
           while(i < heap.size()){
            int size = (2*i) +2;
                for(int j = i+1; j<= size; j++) cout<<heap[j]<<"  ";
            cout << endl;
            i = size;
           }

        }
        int size(){
            return heap.size();
        }
        void heap_print(){
            for(int x : this->heap) cout << x << ' ';
        }
};

int main(){
    vector<int> data = {1,5,2,3,8,9,4,5,6,7,8};
    PriorityQueue *que = new PriorityQueue();
    que->buildHeap(data);
    cout << que->size() << endl;
    que->printHeap();
}