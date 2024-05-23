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

typedef struct
{
    char snum[20];
    char name[20];
    int score[3];
} Student;

int selectMenu();
int createScore(Student *s);
void readScore(Student *s);
int updateScore(Student *s);
int deleteScore(Student *s);

int main()
{
    Student s;
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
            createScore(&s);
            count++;
        }
        else if (menu == 2)
        {
            readScore(&s);
        }
        else if (menu == 3)
        {
            updateScore(&s);
        }
        else if (menu == 4)
        {
            if (deleteScore(&s) == 1)
                count--;
        }
    }

    return 0;
}

int selectMenu()
{
    int menu = 0;
    printf("메뉴를 선택하세요\n");
    printf("1. 추가 2. 조회 3. 수정 4. 삭제 0. 나가기 ");
    scanf("%d", &menu);
    return menu;
}

int createScore(Student *s)
{
    printf("Name? ");
    scanf("%s", s->name);

    printf("Student number? ");
    scanf("%s", s->snum);

    char subject[3][20] = {"Korean", "English", "Math"};
    for (int i = 0; i < 3; i++)
    {
        printf("%s score? ", subject[i]);
        scanf("%d", &s->score[i]);
        if (s->score[i] < 0 || s->score[i] > 100)
            return 0;
    }

    return 1;
}

void readScore(Student *s)
{
    int sum = s->score[0] + s->score[1] + s->score[2];
    double avg = sum / 3.0;

    printf("\n");
    printf("snum      Name    kor  Eng  Math Sum  Avg  \n");
    printf("%-10s%-8s%-5d%-5d%-5d%-5d%-5.1f \n", s->snum, s->name, s->score[0], s->score[1], s->score[2], sum, avg);
    printf("\n");
}

int updateScore(Student *s)
{
    printf("%s의 데이터를 수정합니다.\n", s->name);
    char subject[3][20] = {"Korean", "English", "Math"};
    for (int i = 0; i < 3; i++)
    {
        printf("%s score? ", subject[i]);
        scanf("%d", &s->score[i]);
        if (s->score[i] < 0 || s->score[i] > 100)
            return 0;
    }

    return 1;
}

int deleteScore(Student *s)
{
    int yesorno;
    printf("%s의 데이터를 삭제하시겠습니까(Yes:1 No:0)? ", s->name);
    scanf("%d", &yesorno);

    if (yesorno == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            s->score[i] = -1;
        }
        printf("%s의 데이터가 삭제되었습니다.\n", s->name);
        return 1;
    }
    else
    {
        printf("삭제되지 않았습니다.\n");
        return 0;
    }
}