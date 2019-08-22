#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

stack<pair<int,int>> st;

void push(int new_elem)
{
    int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
    st.push({new_elem,new_min});
}

int getmin()
{
    return st.top().second;
}

int main()
{
    push(2);
    push(3);
    push(49);
    push(1024);
    cout<<getmin()<<"\n"; //Prints 2
    push(1);
    cout<<getmin()<<"\n"; //Prints 1
    return 0;
}
