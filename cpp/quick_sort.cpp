#include<iostream>
using namespace std;
int partition(int a[100], int left, int right){
    int ub,lb,temp,pivot;
    int up, down;
    pivot = a[left];
    down = left;
    up = right;
    while(down < up){
        while(a[down] <= pivot)
            down++;
        while(a[up] > pivot)
            up--;
        if(down < up){

            temp = a[down];
            a[down] = a[up];
            a[up] = temp;
        }

    }
    a[left] = a[up];
    a[up] = pivot; 
    return up;
    
}
int quicksort(int a[100], int left, int right){
    int index;
    if(left > right){
        return 1;
    }
    
    index = partition(a,left,right);
    quicksort(a,left,index-1);
    quicksort(a,index+1,right);
    return 1; 
}
int main(){
    int a[100], n, i;
    cout<<"Enter the length of the array";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}