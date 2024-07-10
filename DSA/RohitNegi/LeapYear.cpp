#include<iostream>
using namespace std;
int main(){
    int num;
    cin>>num;
    bool flag=false;
    if(num%400==0){
        flag=true;
    }
    else if(num%4==0 && num%100!=0){
        flag=true;
    }
    if(flag)cout<<"leap";
    else cout<<"nooo";
}