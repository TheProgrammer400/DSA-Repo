#include<iostream>
using namespace std;

void towerOfHanoi(int n, string src, string helper, string dest){
    if (n == 1){
        cout<<"Transfer disk "<<n<<" from "<<src<<" to "<<dest<<endl;
        return ;
    }

    towerOfHanoi(n-1, src, dest, helper);
    cout<<"Transfer disk "<<n<<" from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1, helper, src, dest);
}

int main(){
    int n = 3;
    towerOfHanoi(3, "A", "B", "C");
    return 0;
}