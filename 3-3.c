#include <stdio.h>
#include <ctype.h>

#define MAX 1024

void expand(char s1[], char s2[]);

int main()
{
	char capital[]= "a-a";
	char capital2[MAX]=""; 

	expand(capital,capital2);

	printf("c1: %s, c2: %s\n",capital,capital2);
	return 0;
}

void expand(char s1[], char s2[])
{
	int i, j, before, after;

	for (i = 0, j = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == '-')
		{
			before = s1[i - 1]; //前の文字をチェックする
			after = s1[i + 1];  //あとの文字をチェックする
			if (i >= 1 && after != '\0' && before < after)
			{
				while (before < after)
				{
					s2[j++] = ++before;
					printf("%d\n",__LINE__);
					//printf("%c",before);
				}
				i++;
			}
			else
			{
				s2[j++] = s1[i];
				printf("%d\n",__LINE__);
			}
		}
		else
		{
			s2[j++] = s1[i];
			printf("%d\n",__LINE__);
		}
	}

	s2[j] = s1[i];
	s2[++j] = '\0';


}

	
		/* 	#<{(| else |)}># */
			/* { */
			/* 	s2[++j] = s1[i]; */
			/* } */
			/* } */
			/* else */
			/* { */
			/* 	s2[++j] = s1[i]; */
            /*  */
	
	//	s2[j] = s1[i];
		//s2[++i] = '\0';

// a-g "abcdefg" アスキーコードでやれば良いのではないか

//大文字のAは65 小文字のaは97
