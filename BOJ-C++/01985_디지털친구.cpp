#include <iostream>
#include <cstdio>

using namespace std;
typedef struct strs
{
	char strA[110];
	char strB[110];
	int A[10] = { 0 };
	int B[10] = { 0 };
	int lenA = 0;
	int lenB = 0;
}strs;
strs T[3];
const char* ans[3] = { "friends","almost friends","nothing" };
int read_line(struct strs &a,bool dir)
{
	int ch, i = 0;
	while ((ch = fgetc(stdin)))
	{
		if (ch == ' ' || ch == '\n'||ch == EOF)
		{
			i++; break;
		}
		if (dir) {
			a.strA[i] = ch ;
			a.A[a.strA[i++] - '0'] ++;
		}
		else {
			a.strB[i] = ch ;
			a.B[a.strB[i++] - '0'] ++;
		}
	}
	if (dir) {
		a.strA[i] = '\0';
	}
	else {
		a.strB[i] = '\0';
	}
	return i-1;
}

bool m_cmp(int* a, int* b)
{
	int t = 9;
	bool ans = true;
	while (t >= 0) {
		if ((a[t] != 0 &&  b[t]== 0) || (a[t] == 0 && b[t] != 0)) {
			ans = false;
			break;
		}
		t--;
	}
	return ans;
}
bool _find = false;

void doit(int*A, int *B,char* b, int end,int now)
{
	if (_find)return;
	if (now >= end-1) {
		return ;
	}
	else {
		int nowch = b[now];
		int nextch = b[now + 1];
		int nownum = nowch - '0';
		int nextnum = nextch - '0';
		if (now != 0) 
		{
			if (nowch > '0' && nextch < '9')
			{
				B[nownum]--; B[nextnum]--;
				B[nownum - 1]++; B[nextnum + 1]++;
				if (m_cmp(A, B)==true) {
					_find = true;
					return;
				}
				B[nownum]++; B[nextnum]++;
				B[nownum - 1]--; B[nextnum + 1]--;
			}
			if (nowch < '9' && nextch > '0')
			{
				B[nownum]--; B[nextnum]--;
				B[nownum + 1]++; B[nextnum - 1]++;
				if (m_cmp(A, B)) {
					_find = true;
					return;
				}
				B[nownum]++; B[nextnum]++;
				B[nownum + 1]--; B[nextnum - 1]--;
			}
			doit(A, B, b, end, now + 1);
		}
		else
		{
			if (nowch > '2' && nextch < '9')
			{
				B[nownum]--; B[nextnum]--;
				B[nownum - 1]++; B[nextnum + 1]++;
				if (m_cmp(A, B)) {
					_find = true;
					return;
				}
				B[nownum]++; B[nextnum]++;
				B[nownum - 1]--; B[nextnum + 1]--;
			}
			if (nowch < '9' && nextch > '0')
			{
				B[nownum]--; B[nextnum]--;
				B[nownum + 1]++; B[nextnum - 1]++;
				if (m_cmp(A, B)) {
					_find = true;
					return;
				}
				B[nownum]++; B[nextnum]++;
				B[nownum +1]--; B[nextnum - 1]--;
			}
			doit(A, B, b, end, now + 1);
		}
	}
}

bool can_almost(struct strs& a)
{
	_find = false;
	doit(a.A,a.B, a.strB, a.lenB,0);
	if (_find == true)return true;
	doit(a.B, a.A, a.strA, a.lenA,0);
	return _find;
}
void compare(struct strs & a)
{	
	int flag = 0;
	if (m_cmp(a.A, a.B)) {
		flag = 0;
	}
	else if(can_almost(a)){
		flag =1;
	}
	else {
		flag = 2;
	}
	
	printf("%s\n", ans[flag]);
}

int main()
{
	for (int i = 0; i < 3; ++i) {
		T[i].lenA = read_line(T[i],true);
		T[i].lenB = read_line(T[i],false);
	}
	for (int i = 0; i < 3; ++i) {
		compare(T[i]);
	}
	return 0;
}