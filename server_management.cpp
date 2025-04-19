#include <string>
#include <iostream>
#include <vector>
#include <format>


using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> servers(players.size(),0);

    int tmp =0;

    for(int i = 0 ; i< players.size(); i++){
        if(players[i]>=m*(servers[i])){
            tmp = servers[i];
            for( int j =i ; j<players.size() & j<i+k;j++){
                servers[j] += (players[i]-m*(tmp))/m;
            }
            answer += (players[i]-m*(tmp))/m;
        }
        cout<<"user : "<<players[i]<< " \t server : "<<servers[i]<<endl;
    }
    return answer;
}

int main(){
    cout << solution({0, 2, 3, 3, 1, 2, 0, 0, 0, 0, 4, 2, 0, 6, 0, 4, 2, 13, 3, 5, 10, 0, 1, 5},3,5)<<endl; // result = 7
    // cout << solution({0, 0, 0, 10, 0, 12, 0, 15, 0, 1, 0, 1, 0, 0, 0, 5, 0, 0, 11, 0, 8, 0, 0, 0},5,1)<<endl; // result = 11
    // cout << solution({0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 5, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},1,1)<<endl; // result = 12
}