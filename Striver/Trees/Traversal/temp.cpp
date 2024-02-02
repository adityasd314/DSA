#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> a;
    a.push_back(vector<int>{1, 2,3,4,5,6});
    cout << sizeof(a)<<endl;
    a.push_back(vector<int>{1, 2,3,4,5,6});
    cout << sizeof(a)<<endl;
    a.push_back(vector<int>{1, 2,3,4,5,6});
    cout << sizeof(a)<<endl;
    a.push_back(vector<int>{1, 2,3,4,5,6});
    cout << sizeof(a)<<endl;
    a.push_back(vector<int>{1, 2,3,4,5,6});
    cout << sizeof(a)<<endl;
    a.push_back(vector<int>{1, 2,3,4,5,6});
    cout << sizeof(a)<<endl;
    a.push_back(vector<int>{1, 2,3,4,5,6});
    cout << sizeof(a)<<endl;
    a.push_back(vector<int>{1, 2,3,4,5,6});
    cout << sizeof(a)<<endl;
    a.push_back(vector<int>{1, 2,3,4,5,6});
    cout << sizeof(a)<<endl;
    a.push_back(vector<int>{1, 2,3,4,5,6});
    cout << sizeof(a)<<endl;
    size_t prev;
    for(auto &x: a){
        cout <<"::"<< &x;
        cout <<"<<"<< &x - prev<<">>";
        for(auto &y: x){
        cout <<"::>>"<< &y<<endl;

        prev= y;
        }

    }
    
    return 0;
}