#include <iostream>
#include <queue>
using namespace std;

queue <pair<int, pair<int,int>>> find_q;
queue <pair<int,int>> delete_list;

int check[16][16], map[16][16], map_c[16][16];
int dir_x[3] = {0,-1,0};
int dir_y[3] = {-1,0,1};
int N, M, D, tx, ty, qd, qx ,qy, cnt = 0, total = 0;

void search(){
    while(!find_q.empty()){
        qd = find_q.front().first;
        qx = find_q.front().second.first;
        qy = find_q.front().second.second;
        find_q.pop();
        
        for(int i=0; i<3; i++){
            tx = qx + dir_x[i];
            ty = qy + dir_y[i];
            if( tx >= 1 && ty >= 1 && ty <= N && map[tx][ty]){
                delete_list.push({tx,ty}); // 사거리안에 있는 적을 찾으면 삭제리스트에 넣기.
                while(!find_q.empty()) // 찾으면 큐 비워주기
                    find_q.pop();
                return;
            }
            else if( D >= qd+1 )
                find_q.push(make_pair(qd+1, make_pair(tx, ty)));
        }
    }
}

void attack(int first, int second, int third){
    
    for(int t = 0; t < N; t++){
        // 첫번째 궁수 적 찾기.
        if(map[N][first])
            delete_list.push({N,first}); // 바로 위(거리1)에서 발견하면 삭제리스트에 넣기.
        else if( D >= 2){
            find_q.push(make_pair(2, make_pair(N, first)));
            search();
        }
        
        // 두번째 궁수 적 찾기.
        if(map[N][second])
            delete_list.push({N,second}); // 바로 위(거리1)에서 발견하면 삭제리스트에 넣기.
        else if( D >= 2){
            find_q.push(make_pair(2, make_pair(N, second)));
            search();
        }
        
        // 세번째 궁수 적 찾기.
        if(map[N][third])
            delete_list.push({N,third}); // 바로 위(거리1)에서 발견하면 삭제리스트에 넣기.
        else if( D >= 2){
            find_q.push(make_pair(2, make_pair(N, third)));
            search();
        }
        
        // 삭제할 적의 좌표값이 들어있음. 중복된 좌표를 제외하고 카운트함.
        while(!delete_list.empty()){
            int ax = delete_list.front().first;
            int ay = delete_list.front().second;
            delete_list.pop();
            if(!check[ax][ay]){
                cnt++;
                map[ax][ay] = 0;
                check[ax][ay] = 1;
            }
        }
        
        // 맵 한칸씩 아래로 내리기
        for(int i=N-1; i>=1; i--)
            for(int j=1; j<=M; j++)
                map[i+1][j] = map[i][j];
        for(int i=1; i<=M; i++)
            map[1][i] = 0;
        
        // 중복된 좌표를 셀때 사용한 2차원배열 초기화
        for(int i=1; i<=15; i++)
            for(int j=1; j<=15; j++)
                check[i][j] = 0;
    }
}

int main(){
    scanf("%d %d %d",&N, &M, &D);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%d",&map[i][j]);
            map_c[i][j] = map[i][j];
        }
    }
    
    for(int i=1; i<=M; i++){ // 순열을 사용하여 궁수의 위치 완전탐색으로 찾기.
        for(int j=i+1; j<=M; j++){
            for(int k=j+1; k<=M; k++){
                attack(i,j,k);
                
                for(int l=1; l<=N; l++) // 맵 초기화
                    for(int m=1; m<=M; m++)
                        map[l][m] = map_c[l][m];
                if(cnt > total)
                    total = cnt;
                cnt = 0;
            }
        }
    }

    printf("%d",total);
    return 0;
}