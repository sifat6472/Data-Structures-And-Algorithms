#include<bits/stdc++.h>

using namespace std;

int main(){

    int size;
    cin>>size;

    int number[size];

    for (int i = 0; i < size; i++){
        scanf("%d",&number[i]);
    }
    
    for (int i = 0; i < size-1; i++){
        int min = i;
        for (int j =i + 1; j < size; j++){
            if(number[min]>number[j])
                min = j;
        }
        swap(number[i],number[min]);
        
    }
    for (int i = 0; i < size; i++){
        printf("%d ",number[i]);
    }
    

    return 0;
}