#include <iostream>
#include "src/Person.h"
#include "src/PhoneNumber.h"
using namespace std;

int main(){
    PhoneNumber p1(7,495,"4564489");
    PhoneNumber p2(7,495,"4564489",15);

    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}