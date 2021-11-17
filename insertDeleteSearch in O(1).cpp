#include "bits/stdc++.h"

using namespace std;

class myDataStructure
{
private:
    vector<int> arr;
    map<int, int> elementIndex;

public:
    void insert(int x)
    {
        if (elementIndex.find(x) == elementIndex.end())
        {
            int index = arr.size();
            arr.push_back(x);
            elementIndex[x] = index;
        }
        return;
    }
    void remove(int x)
    {
        if (elementIndex.find(x) != elementIndex.end())
        {
            int index = elementIndex[x];
            elementIndex.erase(x);
            int lastIndex = arr.size() - 1;
            swap(arr[index], arr[lastIndex]);
            arr.pop_back();
            elementIndex[arr[index]] = index;
        }
        return;
    }
    int getRandom()
    {
        srand(time(NULL));
        int randonIndex = rand() % arr.size();
        return arr[randonIndex];
    }
    int search(int x)
    {
        if (elementIndex.find(x) != elementIndex.end())
        {
            return elementIndex[x];
        }
        return -1;
    }
    void print()
    {
        for (auto x : arr)
            cout << x << " ";
        cout << endl;
    }
};

int main()
{

    myDataStructure ds;
    ds.insert(1);
    ds.insert(2);
    ds.insert(3);
    ds.insert(4);
    ds.insert(5);
    ds.insert(6);
    ds.insert(7);
    ds.insert(8);
    ds.insert(9);
    ds.insert(10);

    cout << ds.getRandom() << endl;

    ds.print();

    cout << ds.search(10) << endl;

    ds.remove(9);

    ds.remove(11);
    ds.remove(2);

    ds.print();

    cout << ds.search(10) << endl;

    return 0;
}
