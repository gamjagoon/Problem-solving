#include<stdio.h>
int main(void) {
	int n, t[44], tt[990];//t는 삼각수의 배열(1000까지는 44개 이내의 삼각수가 존재한다 직접 해봄)
	int i, ii, j, k = 0;//tt는 가능한 모든 t[a]+t[b]의 수들을 저장함
	//(t1+t1,t1+t2~t1+t44//t2+t2,t2+t3~t2+t44)
//삼각수 구해서 배열에 저장(t[])
	for (i = 1; i <= 44; i++) {
		t[i - 1] = i * (i + 1) / 2;
	}
	//tt배열 구하기    
	for (i = 1; i <= 44; i++) {
		for (j = i; j <= 44; j++) {
			tt[k] = t[i - 1] + t[j - 1];
			if (tt[k] > 1000) break;
			k++;
		}
	}
	//테스트케이스 입력     
	scanf("%d", &n);
	//입력   
	for (i = 0; i < n; i++) {
		int q = 0, r = 0;
		scanf("%d", &q);
		//각각의 테스트케이스에 대해서 큰 수부터 차례로 더해감
			   //(배열 t의 맨 마지막부터 하나씩 줄여가며 합을 확인)
		for (j = 44; j >= 1; j--) {
			if (t[j - 1] < q) {
				for (ii = 0; ii < k; ii++) {
					if ((q - t[j - 1]) == tt[ii]) {
						//입력받은 q에대해 해당되는 삼각수 t[j-1]을 뺀 것이 tt[ii]와 같을 경우
						r = 1;         //q 는 세개의 삼각수의 합으로 표현됨.
						break;
					}
				}
			}
			if (r == 1) break;
			if (t[j - 1] * 2 <= q) {//두 개의 합과 같거나 작은 경우는 세개의 합으로 표현될 수 없으므로 0 출력 
				r = 0;
				break;
			}
		}
		printf("%d\n", r);
	}
	return 0;
}