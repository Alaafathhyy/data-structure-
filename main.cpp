
#include <bits/stdc++.h>
#include "List.cpp"
using namespace std ;
int main() {
    List <int> mylist(20,5);
    for(auto v:mylist) cout<<v<<" ";
    cout<<endl;
    cout<<mylist.size()<<endl;

    mylist.push_back(600);

    auto it=mylist.rend();
    cout<<*it<<endl;
    it--;
    cout<<"insert fun     ";
    cout<<*it<<" ";
    mylist.insert(1,it);
    cout<<*it<<endl;

    for (it =mylist.rend();it!=mylist.rbegin();it--)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    it =mylist.begin();

    cout<<*mylist.erase(it)<<endl;
    for(auto v: mylist )
        cout<<v<<" ";


}
