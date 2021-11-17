#include "bits/stdc++.h"
using namespace std;

class myDataStructure
{
private:
    vector<int> arr;
    map<int, set<int> > elementIndex;

public:
    void insert(int x)
    {
        int index = arr.size();
        arr.push_back(x);
        elementIndex[x].insert(index);
    }
    bool remove(int x)
    {
        if (elementIndex.count(x))
        {
            int indexRemoved = *elementIndex[x].begin();
            elementIndex[x].erase(indexRemoved);

            if (indexRemoved == arr.size() - 1)
            {
                arr.pop_back();
            }
            else
            {
                int lastIndex = arr.size() - 1;
                elementIndex[arr[lastIndex]].erase(lastIndex);
                elementIndex[arr[lastIndex]].insert(indexRemoved);

                swap(arr[indexRemoved], arr[lastIndex]);

                arr.pop_back();
            }
            if (elementIndex[x].size() == 0)
            {
                elementIndex.erase(x);
            }
            return true;
        }
        return false;
    }
    int getRandom()
    {
        srand(time(NULL));
        int randonIndex = rand() % arr.size();
        return arr[randonIndex];
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
    ds.insert(9);
    ds.insert(9);
    ds.insert(9);
    ds.insert(10);

    cout << ds.getRandom() << endl;

    ds.print();

    ds.remove(9);

    ds.remove(11);
    ds.remove(2);

    cout << ds.getRandom() << endl;

    ds.print();

    return 0;
}
