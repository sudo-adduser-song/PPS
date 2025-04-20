#include <string>
#include <iostream>
#include <vector>
#include <format>

using namespace std;


int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int short_wallet_length=0;
    int long_wallet_length=0;
    if(wallet[0]>=wallet[1]) {
        short_wallet_length=wallet[1];
        long_wallet_length=wallet[0];
    }
    else {
        short_wallet_length=wallet[0];
        long_wallet_length=wallet[1];
    }

    int short_length_index=0;
    int long_length_index=0;

    while(1){
        if(bill[0]>=bill[1]){
            short_length_index=1;
            long_length_index=0;
        }
        else{
            short_length_index=0;
            long_length_index=1;
        }
        cout<<"bill[0] = "<<bill[0]<<" / bill[1] = "<<bill[1]<<endl;
        if(short_wallet_length>=bill[short_length_index] & long_wallet_length>=bill[long_length_index] ) break;
        bill[long_length_index]/=2;
        answer++;
    }

    return answer;
}

int main(){
    // cout << solution({30,15},{26,17})<<endl; // result = 1
    cout << solution({50,50},{100,241})<<endl; // result = 4
}