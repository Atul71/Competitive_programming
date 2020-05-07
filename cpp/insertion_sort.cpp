#include<iostream>
#include<vector>
using namespace std;
int main(){
    int i,j,n;
    int key;
    vector <int> a(100);
    cout<<"Enter the length of array ";
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    
    }

    for(i=1;i<n;i++){
        j = i-1;
        key = a[i];
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;

    }

    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
    
}