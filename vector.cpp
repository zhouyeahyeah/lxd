#include "vector.h"

void test_vector()
{
    lxd::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    for(auto x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    for(lxd::vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    for(size_t i=0;i<v.size();i++)
    {
        v[i]++;
    }
    for(auto e:v)
    {
        cout<<e<<" ";
    }
    cout<<endl;

    v.insert(v.begin(), 100);
    v.erase(v.end()-1);

    for(auto d:v)
    {
        cout<<d<<" ";
    }
    cout<<endl;

}

int main()
{
    test_vector();
    system("pause");
    return 0;
}