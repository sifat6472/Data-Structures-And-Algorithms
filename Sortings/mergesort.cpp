#include<bits/stdc++.h>

using namespace std;

void mergeArrays(int x[],int y[],int a[],int s,int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;

     while(i<=mid && j<=e){
         if(x[i]<y[j]){
            a[k] = x[i];
            i++;
            k++;
        }else{
            a[k] = y[j];
            j++;
            k++;
        }
    } 
    while(i<=mid){
        a[k] = x[i];
        i++;
        k++;
    }
    while(j<=e){
         a[k] = y[j];
        j++;
        k++;
    }
}



void mergeSort(int a[],int s,int e){
    if(s>=e)
        return;
    
    int mid = (s+e)/2;
    int x[100],y[100];
    
    for (int i = 0; i <=mid; i++){
        x[i] = a[i];
    }
    
    for (int i = mid+1; i <=e; i++){
        y[i]=a[i];
    }
    mergeSort(x,s,mid);
    mergeSort(y,mid+1,e);
    mergeArrays(x,y,a,s,e);    
}

int main(){
    int a[]={4,3,2,1,9,8,6,7};

    mergeSort(a,0,7);

    for (int i = 0; i < 8; i++){
        cout<<a[i]<<" ";
    }
    
    return 0;
}