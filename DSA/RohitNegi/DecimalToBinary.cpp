#include<iostream>
using namespace std;
int main(){
    int num;
    cin>>num;    //13 - 1101
    int ans=0;
    int mul=1;
    while(num>0){
        int rem=num%2;    // OR rem = num & 1; bitwise operation of the num with 1 also gives the last digit
        num=num/2;     // OR num=num>>1; same as divide by 2
        ans = rem*mul+ans;
        mul=mul*10;
    }
    cout<<ans;
    return 0;
}