// 1. 사용자의 데이터 타입 정의
// 2. 하나의 데이터를 추가하는 기능(함수) 구현 (Create)
// 3. 하나의 데이터 조회 기능(함수) 구현 (Read)
// 4. 하나의 데이터 수정 기능(함수) 구현 (Update)
// 5. 하나의 데이터 삭제 기능(함수) 구현 (Delete)
// 6. 각 함수를 사용하여 전체 프로그램을 구성하는 main 함수 구현
#include <stdio.h>

typedef struct{
    char name[20];
    int score[3]; 
}Score;

int selectMenu();
int addScore(Score *s1);
void readScore(Score *s);
int updateScore(Score *s);
int deleteScore(Score *s);

int main(){
    Score s1;
    int count=0, menu;
    
    while(1){
        menu = selectMenu();
        if(menu == 0) break;
        if(menu == 1 || menu == 3 || menu == 4){
            if(count == 0){
                printf("입력된 데이터가 없습니다.\n");
                printf("메뉴를 다시 선택해주세요.\n");
                continue;
            }
        }
        if(menu == 1){
            printf("Name\tkor \tEng \tMath\tSum \tAvg \n");
            readScore(&s1);
        }
        else if(menu == 2){
            addScore(&s1);
            count++;
        } 
        else if(menu == 3) updateScore(&s1);
        else if(menu == 4){
            deleteScore(&s1);
            count--;
        }
    }

    return 0;
}

int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

// 함수명 / 입력 Parameters 정의 / 결과(Return type)
// addScore() / Score s / 성공여부(1,0)
int addScore(Score *s){
    printf("이름은? ");
    scanf("%s",s->name);

    printf("국어는? ");
    scanf("%d", &s->score[0]);

    printf("영어는? ");
    scanf("%d", &s->score[1]);

    printf("수학은? ");
    scanf("%d", &s->score[2]);
    return 1;
}

void readScore(Score *s){
    int sum = s->score[0] + s->score[1] + s->score[2] ;
    double avg = sum/3.0;

    printf("%s\t%d \t%d \t%d\t%d \t%-5.1f \n",s->name,s->score[0],s->score[1],s->score[2],sum,avg);
}

int updateScore(Score *s){
    printf("이름은? ");
    scanf("%s",s->name);

    printf("국어는? ");
    scanf("%d", &s->score[0]);

    printf("영어는? ");
    scanf("%d", &s->score[1]);

    printf("수학은? ");
    scanf("%d", &s->score[2]);
    printf("=> 수정성공!\n");
    return 1;
}

int deleteScore(Score *s){
    for(int i=0; i<3; i++){
        s->score[i] = -1;
    }

    printf("%s의 정보가 삭제되었습니다.\n",s->name);
    return 1;
}