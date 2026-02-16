
#include<vector>
#include<iostream>

using namespace std;

int main(){
    vector<int> vec;
    int i;

    cout<<"vec size:"<<vec.size()<<endl;

    for (i = 0; i < 5; i++) {
        vec.push_back(i);
    }

    vector<int>::iterator v = vec.begin();

    while(v != vec.end()){
        cout<<"value of v"<<*v<<endl;
        v++;
    }

    return 0;
}