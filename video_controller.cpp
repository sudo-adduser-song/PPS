#include <string>
#include <iostream>
#include <vector>
#include <format>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int command_length = commands.size();
    
    int video_len_i = stoi(video_len.substr(0,video_len.find(":")))*60+stoi(video_len.substr(video_len.find(":")+1));
    int pos_i = stoi(pos.substr(0,pos.find(":")))*60+stoi(pos.substr(pos.find(":")+1));
    int op_start_i = stoi(op_start.substr(0,op_start.find(":")))*60+stoi(op_start.substr(op_start.find(":")+1));
    int op_end_i = stoi(op_end.substr(0,op_end.find(":")))*60+stoi(op_end.substr(op_end.find(":")+1));

    // cout << "video_len : " << video_len_i <<endl;
    // cout << "pos_i : " << pos_i <<endl;
    // cout << "op_start_i : " << op_start_i <<endl;
    // cout << "op_end_i : " << op_end_i <<endl;

    if (pos_i<=0) pos_i = 0;
    if (pos_i>=video_len_i) pos_i=video_len_i;
    if (pos_i>=op_start_i && pos_i<=op_end_i){
        pos_i=op_end_i;
    }
    
    for(int i =0 ;i <command_length ; i++){
        if(commands[i]=="next"){
            pos_i+=10;
        }
        if(commands[i]=="prev"){
            pos_i-=10;
        }
        if (pos_i<=0) pos_i = 0;
        if (pos_i>=video_len_i) pos_i=video_len_i;
        if (pos_i>=op_start_i && pos_i<=op_end_i){
            pos_i=op_end_i;
        }
    }
    // cout<<pos_i<<endl;
    string res = "";
    if((pos_i/60)/10==0) res+='0';
    else res+=to_string((pos_i/60)/10);

    if((pos_i/60)%10==0) res+='0';
    else res+=to_string((pos_i/60)%10);

    res+=':';

    if((pos_i%60)/10==0) res+='0';
    else res+=to_string((pos_i%60)/10);

    if((pos_i%60)%10==0) res+='0';
    else res+=to_string((pos_i%60)%10);

    // cout << res <<endl;
    return res;
}

int main(){
    // vector<string>commands = {"next","prev"};
    // solution("34:33","13:00","00:55","02:55",commands);

    vector<string>commands = {"next","prev"};
    solution("10:55","00:05","00:15","06:55",{"prev", "next", "next"});

}