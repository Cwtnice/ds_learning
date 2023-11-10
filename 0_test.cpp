#include <iostream>
using namespace std;
#define MAX 10

static struct {
    int x, y[3];
} a[3] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}}, *p;




int main(){
    p = a+1;

    int i=0;
    cout << *((int *)(p+1)+2) << endl; // a[2][2]
    cout << *((int *)(p+1)+2) << endl;

    return 0;

}