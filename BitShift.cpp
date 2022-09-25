#include<iostream>
using namespace std;
int swapBitGame(long long N){
        long long right = 1;
        long long left = 1;
        cout<<"right : "<<right<<endl;
        cout<<"left  : "<<left<<endl;
        // placing the right 1 to its correct position
        // i.e. 100000.... and left 1 to its correct position 
        // i.e. .....000001
        int curr = right<<1;
        while(curr > 1){
            right = curr;
            curr = curr<<1;
            //one bit will be shifted to right in each iteration.
        }
        
        cout<<"right : "<<right<<endl;

        
        // now use two pointer approach.
        // find 0 from left and 1 from right while(right > left) and swap them 
        // to make integer strictly smaller than N
        cout<<"right : "<<right<<endl;
        cout<<"left  : "<<left<<endl;


        while(right>left){
            // find right 1 bit
            while(!right&N and right>left){
                right = right>>1;
            }
            //find leftmost 0
            while(left&N and right>N){
                left = left<<1;
            }
            
            //make 'right' positioned bit 0
            //0100000000 => right
            //0101101101 => N -> right^N;
            //0001101101
            //Now make 'left' positioned bit 1;
            //left   => 0000000010
            //N      => 0001101101
            //n^left => 0001101111;
        
            
            N = N^right;
            N = N^left;
            
        }
        return N;
    }

    int main(){
        cout<<swapBitGame(8);
    }