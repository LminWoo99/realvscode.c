#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100
FILE* fp = NULL;
char name[SIZE];
char word[SIZE];
char line[SIZE];
void qu() {
   int num=0;
   int i=0;
    while (1)
    {
        printf("탐색할 단어: ");
        fflush(stdin);
        gets(word);
         while (!feof(fp))
    {
        num++;
        fgets(line, SIZE, fp);
        if (strstr(line, word) != NULL)
        {
            printf("%s: %d    %s", name, num, line);
        }
    }

        int input, i;
        char YesNo;
        printf("다시 검색할까요?(Y/N)");
        scanf("%c", &YesNo);
        if (YesNo == 'Y') {
            qu();
        }
        else if (YesNo == 'N') {
            printf("프로그램을 종료합니다\n");
            exit(1);
        }
        else
            while(1){
            printf("잘못입력하셨습니다\n");
            printf("다시 검색할까요?(Y/N)");
            scanf("%c", &YesNo);
               fflush(stdin);
            if(YesNo == 'Y'){
         
            break;
            }
            
        }
        qu();
          }

    fclose(fp);
}


int main(void)
{
    int num = 0;
    printf("파일 이름: ");
    gets(name);
    if ((fp = fopen(name, "r")) == NULL)
    {
        printf("파일오픈오류\n");
        exit(1);
    }
    qu();

    return 0;
}