#include<cstdio>

char str[2501];
char data[51];
int start = 0, cnt = 0, end, data_size;
int read_line(char buf[]) {
	int ch, i = 0;
	while ((ch = fgetc(stdin) )!= '\n') {
		buf[i++] = ch;
	}
	return i;
}

void find() {
	int i = 0;
	printf("start index = %d\n", start);
	while (i < data_size) {
		if (str[start] == data[i]) {
			start++;
			i++;
		}
		else {
			printf("return i = %d\n",i);
			if (i == 0)start++;
			else start -= (i-1);
			return;
		}
	}
	printf("%d %d\n", start, i);
	cnt++;
	return;
}
int main() {
	end = read_line(str);
	data_size = read_line(data);
	printf("%s\n%s\n", str, data);
	while (start + data_size <= end+1) {
		find();
	}
	printf("%d", cnt);
}