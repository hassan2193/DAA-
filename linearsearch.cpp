#include<iostream>
#include<vector>
using namespace std;

vector<int> linearSearch(int arr[],int n, int key){

    int count = 0;
    for(int i=0; i<n; i++){
        count++;
        if(arr[i] == key){
            return {i, count};
        }
    }

    return {-1, count};

}

int main(){

    int arr[8] = {0, 8, 2, 3, 1, -2, 5, 4};
    vector<int> ls = linearSearch(arr,8,1); 

    if(ls[0]==-1){
        cout<<"Key is not found and number of key comparisons were "<<ls[1]<<" which is equal to the size of array";
    } 
    else{
        cout<<"Key found at index "<<ls[0]<<" and number of comparisons were "<<ls[1];
    }
    
    return 0;
}