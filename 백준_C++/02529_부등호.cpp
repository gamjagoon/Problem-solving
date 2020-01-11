#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int K,max_val = 9,min_val = 0;
typedef struct P{
	int mindegree = 0;
	int maxdegree = 0;
	vector<int> min_next;
	vector<int> max_next;
	int max,min;
}P;
P points[10];


int main()
{
	cin>>K;
	char tmp;
	for(int i = 1; i<=K;++i){
		cin>>tmp;
		if(tmp == '<'){
			points[i-1].min_next.push_back(i);
			points[i].max_next.push_back(i-1);
			points[i-1].maxdegree +=1;
			points[i].mindegree +=1;
		}
		else{
			points[i].min_next.push_back(i-1);
			points[i-1].max_next.push_back(i);
			points[i].maxdegree +=1;
			points[i-1].mindegree +=1;
		}
	}
	priority_queue<int,vector<int>,greater<int>>min_pq;
	priority_queue<int,vector<int>,greater<int>>max_pq;
	for(int i = 0 ; i <= K;++i){
		if(points[i].mindegree ==0){
			min_pq.push(i);
		}
		if(points[i].maxdegree ==0)
		{	
			max_pq.push(i);
		}
	}
	for(int i = 0;i<= K; ++i){
		int x = min_pq.top();
		min_pq.pop();
		points[x].min = min_val++;
		for(auto j : points[x].min_next){
			points[j].mindegree--;
			if(points[j].mindegree == 0){
				min_pq.push(j);
			}
		}
	}
	for(int i = 0;i<= K; ++i){
		int x = max_pq.top();
		max_pq.pop();
		points[x].max = max_val--;
		for(auto j : points[x].max_next){
			points[j].maxdegree--;
			if(points[j].maxdegree == 0){
				max_pq.push(j);
			}
		}
	}
	for(int i = 0; i<= K ;++i){
		cout<<points[i].max;
	}cout<<endl;
	for(int i = 0; i<= K ;++i){
		cout<<points[i].min;
	}
}