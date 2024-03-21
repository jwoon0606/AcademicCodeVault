#include <stdio.h>

/*
1. 함수
- int selectMenu(구조체)
- int createScore(구조체)
- void readScore(구조체)
- void updateScore(구조체)
- int deleteScore(구조체)
2. 구조체
- 학번 : char[10]
- 이름 : char[20]
- 성적 3개 : int[3]
*/

typedef struct _student{
    char snum[10];
    char name[20];
    int score[3];
}Student;

char class[3][4] = {"KOR","ENG","MATH"};

int selectMenu();
int createScore(Student* s);
void readScore(Student* s);
void updateScore(Student* s);
int deleteScore(Student* s);

int main(){
    Student s;
    int menu=0,count=0;
    printf("*** 학생 점수 관리 프로그램 ***\n");
    while(1){
        menu = selectMenu();
        if(count == 0 && (menu==2 || menu==3 || menu==4)){
            printf("No data.\n");
        }
        else if(menu == 1){
            count += createScore(&s);
        }else if(menu == 2){
            readScore(&s);
        }else if(menu == 3){
            updateScore(&s);
        }else if(menu == 4){
            count += deleteScore(&s);
        }
        else break;
    }
}

int selectMenu(){
    int num = 0;
    printf("\n1. 생성\n");
    printf("2. 조회\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("0. 종료\n");
    printf("=> ");
    scanf("%d",&num);

    return num;
}

int createScore(Student* s){
    printf("Name? ");
    scanf("%s",s->name);
    printf("Student Number? ");
    scanf("%s",s->snum);
    for(int i=0; i<3; i++){
        printf("%s Score?? ",class[i]);
        scanf("%d",&s->score[i]);
    }

    return 1;
}
void readScore(Student* s){
    int sum = 0;
    float avg = 0.f;
    for(int i=0; i<3; i++){
        sum += s->score[i];
    }
    avg = sum / 3.f;
    printf("snum      name      kor  eng  math  sum  avg\n");
    printf("%-8s  %-8s  %-3d  %-3d  %-4d  %-3d  %-.1f\n",s->snum,s->name,s->score[0],s->score[1],s->score[2],sum,avg);
}

void updateScore(Student* s){
    printf("Name? ");
    scanf("%s",s->name);
    printf("Student Number? ");
    scanf("%s",s->snum);
    for(int i=0; i<3; i++){
        printf("%s Score?? ",class[i]);
        scanf("%d",&s->score[i]);
    }
}
int deleteScore(Student* s){
    for(int i=0; i<3; i++){
        s->score[i] = -1;
    }
    printf("삭제되었습니다.");
    return -1;
}