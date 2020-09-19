#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void insert_sort(vector<T> &arr){
    T* current = &arr[1];
    T tmp;
    T* sort;
    while (current != &arr[arr.size() - 1]) {
        sort = current;
        while (true)
        {
            if (*sort < *(sort - 1)) {
                tmp = *sort;
                *sort = *(sort - 1);
                *(sort - 1) = tmp;
                if(sort > &arr[1]){
                    sort--;
                }
                else{
                    break;
                }
            }
            else {
                break;
            }
        }
        current++;
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << ' ';
        }
        cout<<endl<<endl;
    }
}

int main()
{
    vector<int> arr = { 5,-9,1,9, -65,45 };

    cout<<"Input array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout<<endl<<endl<<"Sorting: "<<endl;
    insert_sort(arr);
    cout<<"Output array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout<<endl;
}
