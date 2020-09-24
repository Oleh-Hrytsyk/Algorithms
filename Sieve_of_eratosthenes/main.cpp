#include <iostream>
#include <vector>
using namespace std;


vector<int> generate_arr(int size){
    vector<int> result;
    for(int i=1; i<=size; i++){
        result.push_back(i);
    }
    return result;
}

void sieve_of_Eratosthenes(vector<int> arr){
        for(unsigned int i=1; i<10 && i<arr.size(); i++){
            if(arr[i]!=-1){
                for(unsigned int j=arr[i]+i; j<arr.size(); j+=arr[i]){
                    arr[j]=-1;
                }
            }
        }
        for(unsigned int j=0; j<arr.size(); j++){
            if(arr[j]!= -1){
                cout<<arr[j]<<' ';
            }
        }
        cout<<endl;
}

int main()
{
    int count;
    cout<<"Enter count of numbers: ";
    cin>>count;
    cout<<endl<<"Result: ";
    sieve_of_Eratosthenes(generate_arr(count));
    cout<<endl;
}
