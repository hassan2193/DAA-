#include <iostream>
using namespace std;
int main()
{
    int arr[]={12,13,14,15,16,17,18};
    int size=7;
    int key=177;
    int found=0;
    int count=0;
    
    for(int i=0; i<size; i++)
    {
        count++;
        if(arr[i]==key)
        {
            cout<<"target is found and number of key comparisons were "<<count;
            found=1;
            break;
        }
    }
    
    if(found==0)
    cout<<"target is not found and number of comparisons were"<<count;
}