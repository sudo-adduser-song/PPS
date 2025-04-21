#include <string>
#include <iostream>
#include <vector>
#include <format>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    if(h>=1){
        if(board[h][w] == board[h-1][w]) answer ++;
    }
    if(h<board.size()-1){
        if(board[h][w] == board[h+1][w]) answer ++;
    }
    if(w>=1){
        if(board[h][w] == board[h][w-1]) answer ++;
    }
    if(w<board[0].size()-1){
        if(board[h][w] == board[h][w+1]) answer ++;
    }
    return answer;
}




int main(){
    cout << solution({{"blue", "red", "orange", "red"}, {"red", "red", "blue", "orange"}, {"blue", "orange", "red", "red"}, {"orange", "orange", "red", "blue"}},1,1)<<endl; // result = 2

    cout << solution({{"yellow", "green", "blue"}, {"blue", "green", "yellow"}, {"yellow", "blue", "blue"}},0,1)<<endl; // result = 1
}