#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int size;
    printf("Enter the size of the array: \n");
    
    cin>>size;

    int newArray[size];
    printf("Enter the elements of the array: \n");
    int max = 0;
    
    for(int i = 1; i <= size;i++){
        scanf("%d",&newArray[i]);
        if(newArray[i]>max)
            max = newArray[i];
    }
    
    printf("The max element is %d\n",max);

    int freqArray[max+1];
    memset(freqArray, 0, sizeof(freqArray));

    for(int j = 1; j <= size;j++){
        freqArray[newArray[j]]++;
    }

    for(int j = 1; j <= max;j++){
        freqArray[j] = freqArray[j]+freqArray[j-1];
    }
    int sortedArray[size];
    for(int j = size; j >= 1;j--){
        sortedArray[freqArray[newArray[j]]]= newArray[j];
        freqArray[newArray[j]]--;
    }

    printf("The sorted array is: \n");
    
    for(int j = 1; j <= size;j++){
        printf("%d ",sortedArray[j]);
    }
    






    return 0;
}