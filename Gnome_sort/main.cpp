#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> gnome_sort(vector<T> arr) {
    T* current_position = &arr[0];
    while (current_position < &arr[arr.size() - 1]) {
        if (*current_position<*(current_position+1)) {
            current_position++;
        }
        else {
            T tmp = *current_position;
            *current_position = *(current_position + 1);
            *(current_position + 1) = tmp;
            if(current_position!=&arr[0])
            current_position--;
        }
        for (unsigned int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl<<endl;
    }
    return arr;
}

int main()
{
    vector<int> arr = { 4,3,5,2,1,-23,8,6,7 };
    cout<<"input array: ";
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl<<endl;
    arr = gnome_sort(arr);
    cout<<"output array: ";
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl<<endl;
}
