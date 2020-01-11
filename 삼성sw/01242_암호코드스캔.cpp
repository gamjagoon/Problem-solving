#include <iostream>
 
const int numbers[10] = {
	0b0001101,0b0011001,0b0010011,0b0111101,
	0b0100011,0b0110001,0b0101111,0b0111011,
	0b0110111,0b0001011
};
int hex[256];
std::string map[2000];
int s[100000];
int bin_code[501 * 4];
int top = -1;
int code[8];
 
void initHex(void)
{
    for (int i = '0'; i <= '9'; i++) {
        hex[i] = i - '0';
    }
    for (int i = 'A'; i <= 'F'; i++) {
        hex[i] = i - ('A' - 10);
    }
}
 
void input(int &n, int &m)
{
    std::cin>>n>>m;
    for (int i = 0; i < n; i++) {
        std::cin>>map[i];
    }
}
 
int memncmp(const int *lhs, const int *rhs, int len)
{
    for (int i = 0; i < len; i++) {
        if (lhs[i] != rhs[i]) {
            return lhs[i] - rhs[i];
        }
    }
    return 0;
}
 
void memnset(int* a, int val, int size)
{
	char *ptr = (char*)a;
	for (int i = 0; i <= size; ++i) {
		*ptr = val;
		ptr++;
	}
}

 
int make_bin(int _x, int y)
{
	int ret = 0;
	for (int c = _x; c >= 0; --c) {
		int tmp = hex[map[y][c]];
		for (int i = 0; i < 4; i++) {
			s[++top] = tmp & (1<<i) ? 1 : 0;
		}
	}
	ret = top +1;
	for (int i = 0; top != -1; ++i) {
		bin_code[i] = s[top--];
	}
	return ret;
}
 

int getCodeLen(int &limit)
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
 
void make_dec(int limit, int len)
{
    int* p = &bin_code[limit - len];
    int temp;
    int zip = len / 56;
    for (int i = 0; i < 8; i++) {
        temp = 0;
        for (int j = 0; j < 7; j++) {
            temp <<= 1;
            temp += *p;
            p += zip;       
        }
        for (int n = 0; n <= 9; n++) {
            if(numbers[n] == temp){
                code[i] = n;
                break;
            }
        }
    }
}
 
bool check(void)
{
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
 
int cal(void)
{
    int ret = 0;
    for (int i = 0; i < 8; i++) {
        ret += code[i];
    }
    return ret;
}
 
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
 
int run(int n, int m)
{
    int ret = 0;
    for (int y = 0; y < n; y++) {
        for (int x = m - 1; x >= 0; x--) {
            if (map[y][x] != '0') {
                int limit = make_bin(x, y);
                int len = getCodeLen(limit);
                make_dec(limit, len);
                if (check())
                    ret += cal();
                clean(len, x, y, n);
                memnset(bin_code, 0, sizeof(bin_code));
                top = -1;
            }
        }
    }
    return ret;
}
 
int main(void)
{
    int t;
    initHex();
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin>>t;
    for (int tc = 1; tc <= t; tc++) {
        int n, m;
        input(n, m);
        std::cout<<"#"<<tc<<' '<<run(n,m)<<'\n';
    }
    return 0;
}