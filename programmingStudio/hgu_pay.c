/*
HGU를 사용할 학생에 대한 정보 저장
각 학생의 입금 내역에 대해서 저장
각 학생의 사용 내역에 대해서 저장

2) 선언할 구조체

a. 학생
학번, 이름, 연락처, 충전 횟수, 사용 횟수, 현재 잔액

b. 충전
학생배열의 순번, 금액

c. 사용
학생배열의 순번, 금액

[주의 사항]

프로그램 시작할 때 조회
추가되는 순간 파일 저장

*/
#include <stdio.h>

typedef struct _Student{
    char snum[10];
    char name[20];
    char phone[15];
    int charge;
    int use;
    int janek;
}Student;

typedef struct _Charge{
    int num[50];
    int money[50];
}Charge;

typedef struct _Use{
    int num[50];
    int use[50];
}Use;

int selectMenu();
int addStudent(Student *s,int cnt);
void readData(Student *s);
int chargeMoney(Student *s);
int useMoney(Student *s);
void saveData(Student *s);

int main(){
    Student* s[50];
    int menu,count = 0;

    printf("*** HGU Pay ***\n");
    while(1){
        menu == selectMenu();
        if(menu == 1){
            chargeMoney(s);
        }
        else if(menu == 2){
            useMoney(s);
        }
    }
    
}

int selectMenu(){
    int num = 0;
    printf("\n1. 충전\n");
    printf("2. 사용\n");
    printf("==> ");
    scanf("%d",&num);
    return num;
}
int addStudent(Student *s,int cnt){
    printf("학번은? ");
    scanf("%s",s[cnt].snum);

    return cnt + 1;
}

void raedData(Student *s){
    int i=0;
    while(strlen(s[i].snum)){      // why s[i]->snum (x), s[i].snum (o)?
        printf("학번       이름       연락처         충전 횟수 사용 횟수 현재 잔액\n");
        printf("%-8s %-8s %-11s %-5d %-5d %-5d\n",s[i].snum,s[i].name,s[i].phone,s[i].charge,s[i].use,s[i].janek);
    }
}

int chargeMoney(Student *s){

    return 1;
}
int useMoney(Student *s){

}

void saveDate(Student *s){

}