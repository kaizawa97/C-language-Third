#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[], unsigned int h);

int main()
{
	char s[1024];

	itoa(-1000, s, 10);
	printf("%s\n", s);
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

void itoa(int n, char s[], unsigned int h)
{
	int i, sign;

	if ((sign = n) < 0)
	{
		n = -n;
	}
	i = 0;

	do
	{
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0)
	{
		s[i++] = '-';
	}
	while (h > i)
	{
		s[i++] = ' ';
	}

	s[i] = '\0';
	reverse(s);
}
