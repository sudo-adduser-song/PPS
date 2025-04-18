// Exceed Time Limit.

#include <string>
#include <iostream>
#include <vector>
#include <format>

using namespace std;
bool check(vector<string> storage, int x, int y){
    bool result = false;
    bool up=false;
    bool down=false;
    bool left=false;
    bool right=false;
    if(x==0 | x==storage.size()-1 | y==0 | y== storage[x].size()-1){
        result=true;
    }
    else{
        char tmp = storage[x][y];
        storage[x][y]='_';
        if(storage[x-1][y]=='-') left = check(storage,x-1,y);
        if(storage[x+1][y]=='-') right = check(storage,x+1,y);
        if(storage[x][y-1]=='-') down = check(storage,x,y-1);
        if(storage[x][y+1]=='-') up = check(storage,x,y+1);
        result = left|right|down|up;
        storage[x][y] = tmp;
    }

    return result;
}


int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int count= storage.size() * storage[0].size();
    vector<string> tmp_storage;
    for(int n = 0 ; n<requests.size();n++){
        tmp_storage=storage;
        if(requests[n].size()==1){
            for(int x =0; x<storage.size();x++){
                for(int y =0; y<storage[x].size();y++){
                    if(storage[x][y]== requests[n][0]) {
                        bool check_flag=false;
                        check_flag=check(storage,x,y);
                        if(check_flag) {
                            tmp_storage[x][y] = '-';
                            count--;
                        }
                    }
                }
            }
        }
        else{
            for(int x =0; x<storage.size();x++){
                for(int y =0; y<storage[x].size();y++){
                    if(storage[x][y]== requests[n][0]) {
                        tmp_storage[x][y]='-';
                        count--;
                    }
                }
            }
        }
        storage=tmp_storage;
    }

    return count;
}

int main(){

    // cout << solution({"AZWQY", "CAABX", "BBDDA", "ACACA"},{"A", "BB", "A"})<<endl; // result = 11
    
    cout << solution({"HAH", "HBH", "HHH", "HAH", "HBH"},{"C", "B", "B", "B", "B", "H"})<<endl; // result = 4
}