/*
구간 합 구하기 2차원 버전

사용자로부터 입력이 N X N 형태의 배열을 입력받았을 때 
새로운 부분합 행렬 D를 선언하여 D[n,m] 에 (0,0) 부터 (n,m) 으로 이루어진 사각형모양으로 부분합을 계산하여 입력한다.
이를 활용하여 질문에서 요구하는 일부분의 부분합을 계산한다.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    // 아래 세 코드는 C++ 에서 작성한 코드의 시간을 단축시켜줄 수 있는 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector< vector<int> > A(N+1, vector<int>(N+1,0)); // 사용자가 입력한 값을 저장하기 위한 행렬
    vector< vector<int> > D(N+1, vector<int>(N+1,0)); // 부분합을 저장하기 위한 행렬 

    for ( int i = 1; i<=N; i++){
        for (int j = 1; j <=N ; j++){
            cin >> A[i][j];
            D[i][j] = D[i][j-1] + D[i-1][j] - D[i-1][j-1] + A[i][j];
        }
    }

    for (int i=0; i<M; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = D[x2][y2] - D[x1-1][y2] - D[x2][y1-1]+ D[x1-1][y1-1];
        cout << result << "\n";
    }
    
    return 0;
}