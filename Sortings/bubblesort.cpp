#include<bits/stdc++.h>

using namespace std;

int main(){

    int size;
    printf("Enter the size of the array: ");
    cin>>size;
    
    int array[size];
    for(int i = 0; i < size;i++){
        scanf("%d",&array[i]);
    }
    
    for(int i = 0; i < size;i++){
        
        for(int j = 0; j < size-1;j++){
            if(array[j]>array[j+1])
                swap(array[j],array[j+1]);
        }
    }

    for(int i = 0; i < size;i++){
        printf("%d ",array[i]);
    }

    return 0;
}