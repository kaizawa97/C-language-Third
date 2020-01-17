#include <stdio.h>
int escape(char s[10], char[10]);

int main(void)
{
	int c, i;
	char s[10], t[10];

	i = 0;
	while ((c = getchar()) != EOF)
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';

	escape(s, t);
	printf("%s", t);
	return 0;
}

int escape(char s[10], char t[10])
{
	int j, i;

	// j = 0;

	for (i = 0, j = 0; s[i] != '\0'; i++)
	{
		switch (s[i])
		{
		case '\t':
			t[j++] = '\\';
			// j++;
			t[j++] = 't';
			// j++;
			break;
		case '\n':
			t[j] = '\\';
			j++;
			t[j] = 'n';
			j++;
			break;
		default:
			t[j] = s[i];
			j++;
			break;
		}
	}
	t[j] = '\0';
}