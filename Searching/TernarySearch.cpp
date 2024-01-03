#include<bits/stdc++.h>

using namespace std;

int ternarySearch(int min, int max, int key, int arr[]){
    
    if(max>=min){

        int mid1 = (2*max+min)/3;
        int mid2 = (2*min+max)/3;

        if(key == arr[mid1])
            return mid1;
        if(key == arr[mid2])
            return mid2;    

        if(key < arr[mid2])
            return ternarySearch(min,mid2-1,key,arr);
        
        else if(key > arr[mid1])
            return ternarySearch(mid1+1,max,key,arr);
        else 
            return ternarySearch(mid2+1,mid1-1,key,arr);    

    }
    return -1;
} 

int main(){
    
    int size;
    
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;
    
    int arr[200],min,max;
     max = 0;
    
    for (int i = 0; i <size; i++){
        if(i==0)
            min = i;
        
        scanf("%d",&arr[i]);
        
        if(arr[i]>max)
            max = i;
    }
    
    int key = 5;
    printf("%d %d\n",max,min);
    printf("The Index of key is %d",ternarySearch(min,max,key,arr));





    return 0;
}