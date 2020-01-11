#include <iostream>
#define mfor(i,s,e) for(auto i = s; i <=e; ++i)
#define endl '\n'
using namespace std;

int hex_code[256];
int tmp_bin[100000];
int bin_code[2004];
string map[2000];
int code[8];
int top = -1;

const int numbers[10] = {
	0b0001101,0b0011001,0b0010011,0b0111101,
	0b0100011,0b0110001,0b0101111,0b0111011,
	0b0110111,0b0001011
};

//pass
void hash_hex()
{
	int tmp = 0;
	for (int i = '0'; i <= '9'; ++i) {
		hex_code[i] = tmp;
		tmp++;
	}
	for (int i = 'A'; i <= 'F'; ++i) {
		hex_code[i] = tmp;
		tmp++;
	}
}
//pass
void input(int &n, int &m)
{
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
		cin>>map[i];
}

//pass
int getcodelen(int& limit)
{
	int setcnt = 0;
	int i = limit;
	while(!bin_code[i])i--;
	limit = i+ 1;
	for (; i >0 ; --i) {
		if(bin_code[i]!= bin_code[i-1])setcnt++;
		if (setcnt == 31) {
			break;
		}
	}
	int ret = 56;
	int len = limit - i;
	while (len > ret) {
		ret += 56;
	}
	return ret;
}

//pass
int make_bin(int n,int x) {
	int ret = 0;
	for (int c = x; c >= 0; --c) {
		int tmp = hex_code[map[n][c]];
		for (int i = 0; i < 4; i++) {
			tmp_bin[++top] = tmp & (1<<i) ? 1 : 0;
		}
	}
	ret = top +1;
	for (int i = 0; top != -1; ++i) {
		bin_code[i] = tmp_bin[top--];
	}
	return ret;
}

//pass
void make_code(int len, int limit) {
	int *p = &bin_code[limit - len];
	int tmp = 0;
	int zip = len/56;
	for (int id = 0; id < 8; ++id) {
		tmp  = 0;
		for (int i = 0; i < 7; ++i)
		{
			tmp <<= 1;
			tmp += *p;
			p += zip;
		}
		for (int i = 0; i <= 9; ++i)
		{
			if (numbers[i] == tmp) {
				code[id] = i;
				break;
			}
		}
	}
}

//pass
bool isgood(void) {
	int val = 0;
	for (int i = 0; i <= 7; ++i) {
		if (i % 2 == 0) {
			val += code[i]*3;
		}
		else {
			val += code[i];
		}
	}
	return !(val % 10);
}

//pass
int calc()
{
	int ret  = 0;
	for (int i = 0; i <= 7; ++i)
	{
		ret += code[i];
	}
	return ret;
}
//pass
void clean(int len, int _c, int _r, int n)
{
	int sz = len / 4;
	for (int r = _r; r < n; ++r) {
		if (map[r][_c] == '0') {
			break;
		}
		for (int c = _c; c >= _c - sz; --c) {
			map[r][c] = '0';
		}
	}
}
//pass
void clean_bin(void* a, int val, int len) {
	char *ptr = (char*)a;
	for (int i = 0; i <= len; ++i) {
		*ptr = val;
		ptr++;
	}
}

int solve(const int n, const int m) {
	int ret = 0;
	mfor(i, 0, n - 1) {
		for (int j = m - 1; j >= 0; --j) {
			if (map[i][j] != '0') {
				int limit = make_bin(i,j);
				int len = getcodelen(limit);
				make_code(len,limit);
				if(isgood())
					ret += calc();
				clean(len,j,i,n);
				clean_bin(bin_code,0,sizeof(bin_code));
				top = -1;
			}
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	hash_hex();
	int tc = 1,T;
	cin>>T;
	for (; tc <= T; ++tc) {
		int n,m;
		input(n,m);
		cout<<"#"<<tc<<' '<<solve(n,m)<<'\n';
	}
}
