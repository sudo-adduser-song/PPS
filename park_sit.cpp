#include <string>
#include <iostream>
#include <vector>
#include <format>

using namespace std;

int check(vector<vector<int>> park, int x, int y,int length){
    int result =1;
    
    if(x+length < park.size() & y+length < park[0].size()){
        for(int i =x; i<=x+length ; i++){
            if(park[i][y+length] == 0) return 1;
        }

        for(int i =y; i<=y+length ; i++){
            if(park[x+length][i] == 0) return 1;
        }
    }
    else {
        return 1;
    }

    return 1+check(park,x,y,length+1);
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    vector<vector<int>> park2int(park.size(),vector<int>(park[0].size(),0));

    for(int i = 0 ; i < park.size();i++){
        for(int j=0 ;j < park[0].size();j++){
            cout<<park[i][j]<<"\t";
            if (park[i][j]=="-1") park2int[i][j]=1;
            else park2int[i][j]=0;
        }
        cout<<endl;
    }
    int size=0;

    cout<<endl;
    cout<<"park size = "<<park.size()<<" / park[0] size "<<park[0].size()<<endl;
    int max_size=0;
    for(int i = 0 ; i < park.size();i++){
        for(int j=0 ;j < park[0].size();j++){
            size=0;
            if (park2int[i][j]==1) {
                size = check(park2int,i,j,1);
            }
            cout<<park2int[i][j]<<","<<size<<"\t";
            if(size>=max_size) max_size=size;
        }
        cout<<endl;
    }
    int max_mat = 0;
    for(int i =0 ; i<mats.size(); i++){
        if(mats[i] <= max_size) {
            if(mats[i] >= answer){
                answer = mats[i];
            } 
        }
    }
    return answer;
}

int main(){
    // cout << solution({1},{{"A"}})<<endl; // result = -1

    cout << solution({3}, {{"-1", "-1", "-1"}, {"-1", "-1", "-1"}, {"-1", "-1", "A"}})<<endl; // result = -1 
    // cout << solution({5,3,2},{{"A", "A", "-1", "B", "B", "B", "B", "-1"}, {"A", "A", "-1", "B", "B", "B", "B", "-1"}, {"-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"}, {"D", "D", "-1", "-1", "-1", "-1", "E", "-1"}, {"D", "D", "-1", "-1", "-1", "-1", "-1", "F"}, {"D", "D", "-1", "-1", "-1", "-1", "-1", "F"}})<<endl; // result = 3
}