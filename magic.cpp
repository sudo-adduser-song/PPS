// some test case failure.

#include <string>
#include <iostream>
#include <vector>
#include <format>
#include <algorithm>


using namespace std;

string solution(long long n, vector<string> bans) {
    // a to z : 26
    // aa to zz : 26 * 26 = 676
    // aaa to zzz : 26 * 26 * 26 = 17576

    // a = 97 ~ z = 122
    // a = 1 ~ z = 26
    // aa = 27 ab = 28 ~ ba = 53
    /*
    aa:27 / ab:28 / ac:29 / ad:30 / ae:31 / af:32 / ag:33 / ah:34
    */

    string answer = "";
    string tmp = "";
    vector<long long> bans2int(bans.size(),0);
    long long num = 0;

    int before_count =0;
    
    for(int i = 0 ; i<bans.size(); i++){
        tmp = bans[i];
        num = tmp[0]-96;
        if(tmp.length()>=2){
            for(int j = 1; j<tmp.length(); j++){
                num *= 26;
                num+= (tmp[j]-96);
            }
        }
        bans2int[i]=num;
    }

    sort(bans2int.begin(),bans2int.end());

    long long a=0;
    int checking=0;
    for(int i = 0 ; i<bans.size(); i++){
        a = bans2int[i]-checking;
        if(a<=n) {
            checking++;
            // n++;
        }
    }
    n+=checking;

    string result ="";

    while(1){
        result.insert(result.begin(),(n%26)+96);
        n/=26;
        if(n==0)break;
    }

    return result;
}

int main(){
    cout << solution(30,{"d", "e", "bb", "aa", "ae"})<<endl; // result = "ah"
    cout << solution(7388,{"gqk", "kdn", "jxj", "jxi", "fug", "jxg", "ewq", "len", "bhc"})<<endl; // result = "jxk"
}