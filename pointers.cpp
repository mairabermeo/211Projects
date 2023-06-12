#include <iostream>
using namespace std;
int main() {
int a[
5]= {
1,2,3,4,5};
 cout << sizeof(a) << endl;
 cout << sizeof(a + 1) << endl;
 cout << sizeof(a[1]) << endl;
 cout << a << endl;
 cout << a+1 << endl;
 cout << a+2 << endl;
 cout << *a << endl;
 cout << *(a + 0) << endl;
 cout << *(a +
1) << endl;
 cout << *(a +
2) << endl;
 cout << &a[
0] << endl;
 cout << &a[
1] << endl;
 cout << &a[
2] << endl;
 cout << &a[
0] + 1 << endl;
 cout << &a << endl;
 cout << &a + 1 << endl;}