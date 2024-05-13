/*
// 학생의 정보를 받을 구조체를(Student)를 선언하세요
학번, 이름
국어, 영어, 수학 점수 (100점 만점)

1. 성적을 등록하는 함수(createScore)
파라미터는 구조체, 리턴 값은 성공은 1 실패는 0
2. 학생의 성적을 조회하는 함수(readScore)
3. 학생의 성적 수정
4. 학생의 성적 삭제

메인함수에서는
성적 등록 하고, 바로 조히하는 기능 넣기
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char snum[20];
    char name[20];
    int score[3];
} Student;

int selectMenu();
int createScore(Student *s[], int cnt);
void readScore(Student *s[], int cnt);
int updateScore(Student *s[], int cnt);
int deleteScore(Student *s[], int cnt);
void saveData(Student *s[], int cnt);
void searchStudent(Student *s[], int cnt);

int main()
{
    Student *s[50];
    int count = 0, menu = 0;

    printf("!학생 성적 입력 프로그램!\n");
    while (1)
    {
        menu = selectMenu();
        if (menu == 0)
            break;
        if (menu != 1)
        {
            if (count == 0)
            {
                printf("입력된 데이터가 없습니다.\n");
                continue;
            }
        }
        if (menu == 1)
        {
            count = createScore(s, count);
        }
        else if (menu == 2)
        {
            readScore(s, count);
        }
        else if (menu == 3)
        {
            updateScore(s, count);
        }
        else if (menu == 4)
        {
            count = deleteScore(s, count);
        }
        else if (menu == 5)
        {
            saveData(s, count);
        }
        else if (menu == 6)
        {
            searchStudent(s, count);
        }
    }

    return 0;
}

int selectMenu()
{
    int menu = 0;
    printf("메뉴를 선택하세요\n");
    printf("1. 추가 2. 조회 3. 수정 4. 삭제 5. 저장 6. 검색 0. 나가기 ");
    scanf("%d", &menu);
    return menu;
}

int createScore(Student *s[], int cnt)
{
    Student *p = (Student *)malloc(sizeof(Student));

    printf("Name? ");
    scanf("%s", p->name);

    printf("Student number? ");
    scanf("%s", p->snum);

    char subject[3][20] = {"Korean", "English", "Math"};
    for (int i = 0; i < 3; i++)
    {
        printf("%s score? ", subject[i]);
        scanf("%d", &p->score[i]);
        if (p->score[i] < 0 || p->score[i] > 100)
        {
            printf("0 < score < 100 !!!\n");
            i--;
        }
    }
    s[cnt] = (Student *)malloc(sizeof(Student));
    *s[cnt] = *p;

    return cnt + 1;
}

void readScore(Student *s[], int cnt)
{
    printf("\n");
    printf("snum      Name    kor  Eng  Math Sum  Avg  \n");
    for (int i = 0; i < cnt; i++)
    {
        int sum = s[i]->score[0] + s[i]->score[1] + s[i]->score[2];
        double avg = sum / 3.0;
        printf("%-10s%-8s%-5d%-5d%-5d%-5d%-5.1f \n", s[i]->snum, s[i]->name, s[i]->score[0], s[i]->score[1], s[i]->score[2], sum, avg);
    }
    printf("\n");
}

int updateScore(Student *s[], int cnt)
{
    readScore(s, cnt);
    printf("수정할 학생의 학번을 입력하세요");
    char snum[20];
    int idx = 0;
    scanf("%s", snum);
    for (int i = 0; i < cnt; i++)
    {
        if (strcmp(s[i]->snum, snum) == 0)
            idx = i;
        break;
    }
    printf("%s의 데이터를 수정합니다.\n", s[idx]->name);
    char subject[3][20] = {"Korean", "English", "Math"};
    for (int i = 0; i < 3; i++)
    {
        printf("%s score? ", subject[i]);
        scanf("%d", &s[idx]->score[i]);
        if (s[idx]->score[i] < 0 || s[idx]->score[i] > 100)
            return 0;
    }

    return 1;
}

int deleteScore(Student *s[], int cnt)
{
    readScore(s, cnt);
    printf("수정할 학생의 학번을 입력하세요");
    char snum[20];
    int idx = 0;
    scanf("%s", snum);
    for (int i = 0; i < cnt; i++)
    {
        if (strcmp(s[i]->snum, snum) == 0)
            idx = i;
        break;
    }

    int yesorno;
    printf("%s의 데이터를 삭제하시겠습니까(Yes:1 No:0)? ", s[idx]->name);
    scanf("%d", &yesorno);

    if (yesorno == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            s[idx]->score[i] = -1;
        }
        printf("%s의 데이터가 삭제되었습니다.\n", s[idx]->name);
        return cnt + 1;
    }
    else
    {
        printf("삭제되지 않았습니다.\n");
        return cnt;
    }
}

void saveData(Student *s[], int cnt)
{
    FILE *fp = fopen("score.txt", "wt");
    if (fp == NULL)
    {
        printf("Can't open the file\n");
        exit(-1);
    }
    int i = 0;
    for (int i = 0; i < cnt; i++)
    {
        int sum = s[i]->score[0] + s[i]->score[1] + s[i]->score[2];
        double avg = sum / 3.0;
        fprintf(fp, "%-10s%-8s%-5d%-5d%-5d%-5d%-5.1f \n", s[i]->snum, s[i]->name, s[i]->score[0], s[i]->score[1], s[i]->score[2], sum, avg);
    }
    printf("저장이 완료되었습니다.\n");
    fclose(fp);
}

void searchStudent(Student *s[], int cnt)
{
    char search[30] = "";
    printf("이름을 입력하세yo: ");
    scanf("%s", search);
    printf("\n");
    printf("snum      Name    kor  Eng  Math Sum  Avg  \n");
    for (int i = 0; i < cnt; i++)
    {
        if (strstr(s[i]->name, search))
        {
            int sum = s[i]->score[0] + s[i]->score[1] + s[i]->score[2];
            double avg = sum / 3.0;
            printf("%-10s%-8s%-5d%-5d%-5d%-5d%-5.1f \n", s[i]->snum, s[i]->name, s[i]->score[0], s[i]->score[1], s[i]->score[2], sum, avg);
        }
    }
    printf("\n");
}