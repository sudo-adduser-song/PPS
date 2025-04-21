#include <string>
#include <iostream>
#include <vector>
#include <format>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp = triangle;

    for(int i = triangle.size()-1 ; i>0; i--){
        for(int j = 0; j<triangle[i].size()-1;j++){
            dp[i-1][j]+= max(dp[i][j],dp[i][j+1]);
        }
    }
    return dp[0][0];
}


int main(){ 
    cout << solution({{7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5}})<<endl;
}