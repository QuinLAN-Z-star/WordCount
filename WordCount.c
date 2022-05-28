#include <stdio.h>
#include <string.h>
int main (int ac, char *av[])
{
    FILE *fp;
    int cnt = 0; 
    if ((fp=fopen(av[2], "r")) == NULL)
    {
        puts("error!\n");
        return 0;
    }
    if (av[1][1] == 'w') 
    {
        char s[1024];
        while (fscanf(fp, "%s",&s) != EOF)
        {
            cnt ++;
            for (int i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    cnt ++;
        }
        printf("单词数=%d\n", cnt);
    }
    else if (av[1][1] == 'c') 
    {
        char c;
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("字符数=%d", cnt);
    }
    fclose(fp);
    return 0;
}

