#include <vector>
#include <iostream>
using namespace std;

void print(vector<int>& l) {
    cout << "[";
    int i;
    for (i = 0 ; i < l.size() - 1; i++) {
        cout << l[i] << ",";
    }
    cout << l[i] <<"]\n";
}

void tri_insertion(vector<int>& l) {
    for (int i = 1; i < l.size(); i++)
    {
        int v = l[i];
        int j = i;
        while (j > 0 && l[j - 1] > v)
        {
            l[j] = l[j - 1];
            j -= 1;
        }
        l[j] = v;
        print(l);
    }
    
}



int main() {
    vector<int> list = {1,5,3,4,2,10,9,2,2,2,4,6,8,1};
    tri_insertion(list);
    print(list);    
    return 0;
}