#include <stdio.h>
#include <string.h>

void itob(unsigned int n, char s[], int b);
void reverse(char s[]);

int main()
{
	char s[2048];

	itob(10, s, 16);
	printf("%s\n", s);
}

void itob(unsigned int n, char s[], int b)
{
	int i = 0;
	int c = 0;
	do //doの場合で書いたらこちらになります。
	{
		c = n % b;
		n = n / b;
		if (c < 10)
		{
			s[i++] = c + '0';
		}
		else
		{
			s[i++] = c + '7'; //'7'のアスキーコードは55 10以上だった場合は足してあげる
		}
	} while (n > 0);

	s[++i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
