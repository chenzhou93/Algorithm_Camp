#include <iostream>
using namespace std;

void selectionSort(int a[], int n){
    for(int i=0; i<5; i++){
        int minE = a[i];
        for(int j=i+1; j<5; j++){
            if(a[j] < minE){
                minE = a[j];
            }
        } 

    }
}

int main(){
    int a[5] = {5,4,2,3,1};
    

    return 0;
}