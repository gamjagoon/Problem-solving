#include<cstdio>
#include<cstring>

char str[30001] = { 0,};
char key[30001] = { 0, };
int ch, i = 0, k_ptr=0;

void func(int ch)
{
	int k = 0;
	for (int i = 0; i <= ch; ++i)
	{
		if (str[i] != ' ')
		{
			str[i] -= key[k];
			if (str[i] <= 0) {
				str[i] = 'z' + str[i];
			}
			else {
				str[i] = 'a' + str[i]-1;
			}
		}
		if (k == k_ptr)k = 0;
		else k++;
	}
}
int main()
{
	while ((ch = fgetc(stdin)) != '\n') {
		str[i++] = ch;
	}
	str[i] = '\0';
	scanf("%s", &key);
	k_ptr = strlen(key);
	k_ptr--;
	func(i - 1);
	printf("%s", str);
	return 0;
}