#include<iostream>
using namespace std;

void prime_sieve(int n){
    int prime[100] = {0};

    for(int i=2; i<n; i++){
        if(prime[i]==0){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = 1;
            }
        }
    }

    for(int i=2; i<=n; i++){
        if(prime[i]==0){
            cout<<i<<" ";
        }
    }
}

int main(){
    int n;
    cout<<"ENTER LIMIT : ";
    cin>>n;
    cout<<endl;

    prime_sieve(n);
    return 0;
}