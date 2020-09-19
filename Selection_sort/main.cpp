#include <QCoreApplication>
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
vector<T> selection_sort(vector<T> arr) {
    T* current = &arr[0];
    while (current != &arr[arr.size()-1])
    {
        T* min = current;
        T* check = current;
        while (check < &arr[arr.size() - 1]) {
            check++;
            if (*check<*min)
            {
                min = check;
            }
        }
        T tmp = *min;
        *min = *current;
        *current = tmp;
        current++;
        for (unsigned int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
    return arr;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> arr = {-56,58,4,2,0,-7,-8,63,5,61};
    cout<<"input array: ";
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl<<"sorting:"<<endl;
    arr = selection_sort(arr);
    return a.exec();
}
