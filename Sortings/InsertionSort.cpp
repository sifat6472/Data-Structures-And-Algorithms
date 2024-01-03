#include<bits/stdc++.h>

using namespace std;

int main(){

    int size;
    cin>>size;

    int number[size];
    int loopEx = 0;
    for (int i = 0; i < size; i++){
        scanf("%d",&number[i]);
    }
    
    for (int i = 1; i < size; i++){ // Size  = 4;i = 1;True i = 2 ; True ; i = 3; True i = 4; False
        int key = number[i];
        int j = i-1;
        
        while(number[j]>key && j>=0){// 30 40 20 10 - 1
            number[j+1] = number[j];//  30 20 40 10 - 2
            j--;                    //  20 30 40 10 - 3
            loopEx++;               //  20 30 10 40 - 4
        }                           //  20 10 30 40 - 5
                                    //  10 20 30 40 - 6
        printf(" \nhere is j+1 and key %d %d\n",j+1,key);
        number[j+1] = key;
        
    }
    printf("\nWhile Executed %d\n",loopEx);
    for (int i = 0; i < size; i++){
        printf("%d ",number[i]);
    }
    
    return 0;
}