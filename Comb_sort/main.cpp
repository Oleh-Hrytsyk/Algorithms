#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void comb_sort(vector<T> &arr) {
    unsigned int counter = 0;
    if (arr.size() == 1) {
        return;
    }
    while (counter<=arr.size()-2)
    {
        T* first = &arr[0];
        T* last = &arr[arr.size() - counter - 1];
        while (true) {
            if (*first > *last) {
                T tmp = *first;
                *first = *last;
                *last = tmp;
            }
            if (last == &arr[arr.size() - 1]) {
                counter++;
                break;
            }
            else {
                first++;
                last++;
            }
        }
        for (unsigned int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << ' ';
        }
        cout<<endl<<endl;
    }
}

int main()
{
    vector<int> arr = { 9, 10,5,-4,6,8,1 };
    cout<<"input array: ";
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout<<endl<<endl;
    comb_sort(arr);
    cout<<"output array: ";
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout<<endl<<endl;
}
