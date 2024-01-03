#include<bits/stdc++.h>

using namespace std;

int binarySearch(int lo,int hi,int key,int arr[]){
    
    int mid = (hi+lo)/2;
    
    while(lo<=hi){
        
        if(arr[mid]==key)
            return mid;
        
        else if(arr[mid]>key)
            return binarySearch(lo,mid-1,key,arr);
        
        else if(arr[mid]<key)
            return binarySearch(mid+1,hi,key,arr);    
    }
    
    return -1;
}
int main(){
    
    int size;
    printf("Enter your size: \n");
    cin>>size;
    
    int arr[size];
    for(int i = 0; i < size;i++ ){
        scanf("%d",&arr[i]);
    }
    
    int hi = size-1;
    int lo = 0;
    int key;
    
    printf("Enter your key\n");
    cin>>key;
    
    printf("%d",binarySearch(lo,hi,key,arr));




    return 0;
}