#include <iostream>
using namespace std;
double power(double m, int n = 2){
    if(!n)return 1;
    double tmp = power(m,n>>1);
    if(n&1)return m*tmp*tmp;
    return tmp*tmp;
}
int power(int m, int n = 2){
    if(!n)return 1;
    int tmp = power(m,n>>1);
    if(n&1)return m*tmp*tmp;
    return tmp*tmp;
}
int main() {
    cout<<power(2);
    return 0;
}