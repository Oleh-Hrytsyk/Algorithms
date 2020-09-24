#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<typename T>
void heap_sort(vector<T> &arr) {
    T* first = &arr[0];
    T* last = &arr[arr.size() - 1];
    int size = arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        int counter = 0;
        for (int i = 0; i <= (int)log2(size) - counter + 1; i++) {
            T* father = &arr[pow(2, (int)log2(size) - (counter + 1)) - 1];
            T* son = &arr[pow(2, (int)log2(size) - counter) - 1];
            for (int i = 0; i < (int)log2(size) - (counter); i++)
            {
                if (son == last) {
                    if (*son >= *father) {
                        T tmp = *son;
                        *son = *father;
                        *father = tmp;
                    }
                    counter++;
                    break;
                }
                else if ((son+1) == last) {
                    if ((*son >= *(son + 1)) && (*son >= *father)) {
                        T tmp = *son;
                        *son = *father;
                        *father = tmp;
                    }
                    else if ((*son < *(son + 1)) && (*(son + 1) >= *father))
                    {
                        T tmp = *(son + 1);
                        *(son + 1) = *father;
                        *father = tmp;
                    }
                    counter++;
                    break;
                }
                if ((*son >= *(son + 1)) && (*son >= *father)) {
                    T tmp = *son;
                    *son = *father;
                    *father = tmp;
                    if ((son + 1) == last) {
                        counter++;
                        break;
                    }
                }
                else if ((*son < *(son + 1)) && (*(son + 1) >= *father)) {
                    T tmp = *(son + 1);
                    *(son + 1) = *father;
                    *father = tmp;
                    if ((son + 1) == last) {
                        counter++;
                        break;
                    }
                }
                if (i == (int)log2(size) - (counter)-1)
                {
                    counter++;
                    break;
                }
                father++;
                son += 2;
            }
        }
        T tmp = *first;
        *first = *last;
        *last = tmp;
        last--;
        size--;
        for (unsigned int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl<<endl;
    }
}

int main()
{
    vector<int> arr = { -1, 5,4,9,6,7,8,11,2,58 };
    cout<< "input array: ";
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl<<endl;

    heap_sort(arr);
    cout<<"output array: ";
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl<<endl;
}
