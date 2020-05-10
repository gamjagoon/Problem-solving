#include <stdio.h>
#include <string.h>

char buf[100000];

int main() {
	int ch, i = 0;
	bool not_rev = false;
	while ((ch = getchar()) != '\n')
	{
		if (ch == '<')
		{
			not_rev = true;
			i--;
			while (i >= 0)printf("%c", buf[i--]);
			i++;
			printf("<");
			continue;
		}
		if (ch == '>')
		{
			not_rev = false;
			printf(">");
			continue;
		}
		if (not_rev)printf("%c", ch);
		else if (ch == ' ')
		{
			i--;
			while (i >= 0)printf("%c", buf[i--]);
			printf(" ");
			i++;
		}
		else {
			buf[i++] = ch;
		}
	}
	i--;
	while (i >= 0)printf("%c", buf[i--]);
	return 0;
}