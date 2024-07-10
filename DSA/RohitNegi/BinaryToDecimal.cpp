#include<iostream>
using namespace std;
int main(){
    int num;
    cin>>num;
    int ans=0;
    int mul=1;
    while(num>0){
        int rem=num%10;  //OR rem = num & 1 BITWISE &
        num=num/10;           //jiss form mein convert krna hai uske hi base se divide krna hai
        ans=rem*mul+ans;
        mul=mul*2;
    }
    cout<<ans;
    return 0;
}