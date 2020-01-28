#include <stdio.h>
#include <string.h>

void itob(unsigned int n, char s[], int b);
void reverse(char s[]);

int main()
{
	char s[2048];

	itob(40, s, 2);
	for (int i = 0; i < 20; ++i)
	{
		printf("%d ", s[i]);
	}
	printf("\n%s\n", s);
}

void itob(unsigned int n, char s[], int b)
{
	int i = 0;
	int c = 0;

	while ((n = n / b) > 0) //条件の部分を短縮版にしました。
	{
		c = n % b;
		if (c < 10)
		{
			printf("a");
			s[i++] = c + '0';
		}
		else
		{
			s[i++] = c + '7'; //'7'のアスキーコードは55 10以上だった場合は足してあげる
		}
	}
	// while (n > 0) 条件の部分を短縮しない場合はこちらです。
	// {
	// 	c = n % b;
	//  n = n / b;
	// 	if (c < 10)
	// 	{
	// 		printf("a");
	// 		s[i++] = c + '0';
	// 	}
	// 	else
	// 	{
	// 		s[i++] = c + '7'; //'7'のアスキーコードは55 10以上だった場合は足してあげる
	// 	}
	// }

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
