
#include<vector>
#include<iostream>

using namespace std;

int main(){
    vector<int> vec;

    cout<<"vec size:"<<vec.size()<<endl;

    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
    }

    auto v = vec.begin();

    while(v != vec.end()){
        cout<<"value of v"<<*v<<endl;
        ++v;
    }

    return 0;
}