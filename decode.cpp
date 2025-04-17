#include <string>
#include <iostream>
#include <vector>
#include <format>

using namespace std;


int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    int count =0;
    int sum =0;
    int check =0;
    for(int n1=1;n1<=n;n1++){
        for(int n2=n1+1;n2<=n;n2++){
            for(int n3=n2+1;n3<=n;n3++){
                for(int n4=n3+1;n4<=n;n4++){
                    for(int n5=n4+1;n5<=n;n5++){
                        check =1;
                        for(int x=0;x<ans.size();x++){
                            sum =0;
                            vector<int> a(n, 0);
                            vector<int> b(n, 0);
                            for( int m =0;m<5;m++) a[q[x][m]-1]=1;
                            b[n1-1]=1;
                            b[n2-1]=1;
                            b[n3-1]=1;
                            b[n4-1]=1;
                            b[n5-1]=1;
                            for ( int m = 0 ; m<n;m++){
                                sum += a[m]*b[m];
                            }
                            if(sum != ans[x]){
                                check=0;
                            }
                        }
                        if(check==1) count++;
                        
                    }
                }
            }
        }
    }
    return count;
}

int main(){
    // cout << solution(10,{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {3, 7, 8, 9, 10}, {2, 5, 7, 9, 10}, {3, 4, 5, 6, 7}},{2, 3, 4, 3, 3})<<endl; // result = 3
    cout << solution(15,{{2, 3, 9, 12, 13}, {1, 4, 6, 7, 9}, {1, 2, 8, 10, 12}, {6, 7, 11, 13, 15}, {1, 4, 10, 11, 14}}, {2, 1, 3, 0, 1})<<endl; // result = 2
}