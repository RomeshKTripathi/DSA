#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void build_min_heap(vector<int> &heap, int key){
    heap.push_back(key);

    // Heapify the heap
    int i = heap.size()-1;
    // check if it is less than its parent
    while(i > 1 && heap[i] < heap[(i-1)/2]){
        // if less then parent than swap with parent 
        swap(heap[i], heap[(i-1)/2]);
        // move pointer to its sparent .
        i = (i-1)/2;
    }
}
void min_heapify(vector<int> &heap, int i = 0){
    const int size = heap.size();
    int left = (2*i)+1;
    int right = (2*i)+2;
    if((left < size && right < size) && (heap[left] < heap[i] || heap[right] < heap[i]) ){
        if(heap[left] < heap[right]) {
            swap(heap[left], heap[i]);
            min_heapify(heap, left);
        }else{
            swap(heap[right], heap[i]);
            min_heapify(heap, right);
        }
    }else if(left < size && heap[left] < heap[i]){
        swap(heap[left], heap[i]);
        min_heapify(heap, left);
    }
}


int get_min(vector<int> &heap){
    int data = heap[0];
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    int i = 0;
    min_heapify(heap);
    return data;
}

void build_max_heap(vector<int> &heap, int key){
    heap.push_back(key);

    // Heapify the heap
    int i = heap.size()-1;
    while(i > 0 && heap[i] > heap[(i-1)/2]){
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void print_heap(vector<int> &heap, int i = 0){
    if(i >= heap.size()) return;

    cout << heap[i] << ' ';
    print_heap(heap, (2*i)+1);
    print_heap(heap, (2*i)+2);
}


void heap_level_order(vector<int> &heap){
    queue<int> q;
    const int size = heap.size();
    q.push(0);
    q.push(-1);
    while(!q.empty()){
        int i = q.front();
        if(i == -1){
            cout<< endl;
            q.pop();
            if(!q.empty())q.push(-1);
            continue;
        }
        q.pop();
        if((2*i)+1 < size){
            q.push((2*i)+1);
        }
        if((2*i)+2 < size){
            q.push((2*i)+2);
        }
        cout << heap[i] << "  "; 
    }
}

void buildHeapFromArray(vector<int> &heap){
    // heap.push_back(0);
    // // shift all elements from 0 index to 1 index to right
    // int i = heap.size()-1;
    // while(i > 0){
    //     heap[i] = heap[i-1];
    //     i--;
    // }

    // now heapify all elements from 1 to n;
    int n = heap.size()-1;
    for(int i = 0; i <= n; i++){
        int j = i;
        while(j > 0 && heap[j] < heap[(j-1)/2]){
            swap(heap[j], heap[(j-1)/2]);
            // move pointer to its sparent .
            j = (j-1)/2;
        }
    }


}
int main(){
    vector<int> vec = {9,8,7,6,5,4,3,2,1};
    int key = 1;
    buildHeapFromArray(vec);
    // while(true){
    //     cin >> key;
    //     if(key == -1) break;
    //     build_min_heap(vec, key);
    // }
    print_heap(vec);
    cout<< endl;
    heap_level_order(vec);
    cout << get_min(vec) << endl << " ------ " << endl;
    heap_level_order(vec);
    cout << get_min(vec) << endl << " ------ " << endl;
    heap_level_order(vec);
    cout << get_min(vec) << endl << " ------ " << endl;
    heap_level_order(vec);
}

//{1,5,2,3,8,9,4,5,6,7,8}