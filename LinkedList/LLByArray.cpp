// #include<iostream>
// using namespace std;

// class LL{
//     public :
//     int free = -1;
//     int *freeList = new int[10];
//     int head = -1;
//     int *LinkedList = new int[10 * 3];
//     // prev | node | next;
    
//     LL(){
//         free = 0;
//         for(int i = 1; i <= 10; i++){
//             freeList[i-1] = i;
//             if(i == 10) freeList[i-1] = -1;
//         }

//     }

//     void insert(int data){
//         int target = free * 3 + 1; // to insert data at this position
//         // Update free pointer
//         free = freeList[free];
//         LinkedList[target] = data;
//         LinkedList[target-1] = head;
//         if(head != -1){
//             LinkedList[head+1] = target;
//         }
//         head = target;
//         LinkedList[target + 1] = -1;
//     }
// };

// int main(){
//     LL *obj = new LL();
//     obj->insert(1);
//     obj->insert(2);
//     obj->insert(3);
// }