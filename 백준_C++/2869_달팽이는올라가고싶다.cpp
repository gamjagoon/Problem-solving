#include <iostream>
using namespace std;

void init();
void doit();
//1 ≤ B < A ≤ V ≤ 1,000,000,000
int A,B,V,day = 0,up;

int main(){
	init();
	doit();
	return 0;
}

void doit(){
	day += V/up;
	V -= up*(V/up);
	if(V > 0){
		day++;
		V-=up;
	}
	printf("%d",day);
	return ;
}

void init(){
	cin>>A>>B>>V;
	up = A- B;
	V -= A;
	day++;
}