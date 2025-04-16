// 정확도 테스트는 통과했으나 효율성 테스트 불합격

#include <string>
#include <iostream>
#include <vector>
#include <format>

using namespace std;

vector< vector<int> > floodfill(vector< vector<int> > land, int cur_x, int cur_y){
    int x=land.size();
    int y=land[0].size();

    int left =0;
    int right =0;
    int up = 0;
    int down =0;
    land[cur_x][cur_y]=0;
    // cout<<"[floodfill call] cur_x = "<<cur_x<<" / cur_y = "<<cur_y<<endl;
    if(cur_x>0){
        if(land[cur_x-1][cur_y] == 1) land=floodfill(land,cur_x-1,cur_y);
    }
    if(cur_x<x-1){
        if(land[cur_x+1][cur_y] == 1) land=floodfill(land,cur_x+1,cur_y);
    }
    if(cur_y>0){
        if(land[cur_x][cur_y-1] == 1) land=floodfill(land,cur_x,cur_y-1);
    }
    if(cur_y<y-1){
        if(land[cur_x][cur_y+1] == 1) land=floodfill(land,cur_x,cur_y+1);
    }

    return land;
}

int difference(vector<vector<int>> prev, vector<vector<int>> cur){
    int diff =0;

    for(int i = 0; i<prev.size();i++){
        for( int j =0; j<prev[0].size();j++){
            if(prev[i][j]==1 & cur[i][j]==0) diff++;
        }
    }
    return diff;
}

int solution(vector< vector<int> > land) {
    int answer = 0;
    int x=land.size();
    int y=land[0].size();

    // for(int i=0;i<x;i++){
    //     for(int j=0;j<y;j++){
    //         if(land[i][j]==1) cout<<"[-]";
    //         else cout<<"[ ]";
    //     }
    //     cout<<endl;
    // }
    vector<vector<int>> prev_land;
    vector<vector<int>> tmp_land;
    int tmp_sum=0;
    int max=0;
    for(int i=0;i<y;i++){
        tmp_sum=0;
        tmp_land=land;
        for(int j=0;j<x;j++){
            if(land[j][i]==1){
                prev_land=tmp_land;
                tmp_land=floodfill(tmp_land,j,i);
                tmp_sum+=difference(prev_land,tmp_land);
            }
        }
        // cout<<"i = "<<i<<" / sum = "<<tmp_sum<<endl;
        if(max<=tmp_sum) max=tmp_sum;
    }

    return max;
}

int main(){
    cout << solution({{0, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {1, 1, 0, 0, 0, 1, 1, 0}, {1, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 1, 1}}); // result = 9

    // cout << solution({{1, 0, 1, 0, 1, 1}, {1, 0, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 1}, {1, 0, 0, 1, 0, 0}, {1, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1}}); // result = 16
}