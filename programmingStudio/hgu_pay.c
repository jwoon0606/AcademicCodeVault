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
#include <stdlib.h>

// 학생 정보 구조체
typedef struct _Student{
    char snum[10]; // 학번
    char name[20]; // 이름
    char phone[15]; // 연락처
    int input; // 충전 횟수
    int expend; // 사용 횟수
    int balance; // 잔액
}Student;

int selectMenu();
int loadData(Student *s[], int cnt); // Load data from file
int addStudent(Student *s[],int cnt); // Create
void readStudent(Student *s[],int cnt); // Read
int deleteData(Student *s[], int cnt); // Delete
void saveData(Student *s[]); // Save data
int chargeMoney(Student *s[]); // Charge money(Update)
int useMoney(Student *s[]); // Expend money(Update)
void searchStudent(Student *s[]); // Search student

int main(){
    Student* s[50] = {NULL,};
    int menu,count = 0;

    printf("*** HGU Pay ***\n");
    while(1){
        menu == selectMenu();
        if(menu == 1){
            readData(s,count);
        }else if(menu == 2){
            uaddStudent(s,count);
        }else if(menu == 3){

        }

    }
}

int loadData(Student *s[], int cnt){
    FILE* fp = NULL;
    fp = fopen("student.txt","r");
    if(fp == NULL){
        printf("Failed to open file %s on line %d of file %s","Student.txt",__LINE__,__FILE__);
        exit(-1);
    }
    while(1){
        if(fp == EOF) break;


    }

}

int selectMenu(){
    int num = 0;
    printf("\n1. 조회\n");
    printf("2. 학생 추가\n");
    printf("3. 학생 정보 수정\n");
    printf("4. 학생 삭제\n");
    printf("5. 저장\n");
    printf("6. 불러오기\n");
    printf("7. 충전\n");
    printf("8. 사용\n");
    printf("9. 검색\n");
    printf("0. 종료\n");
    printf("메뉴 입력 => \n");

    scanf("%d",&num);
    return num;
}
int addStudent(Student *s[],int cnt){
    printf("학번은? ");
    scanf("%s",s[cnt].snum);

    return cnt + 1;
}

void raedData(Student *s[]){
    int i=0;
    while(strlen(s[i].snum)){      // why s[i]->snum (x), s[i].snum (o)?
        printf("학번       이름       연락처         충전 횟수 사용 횟수 현재 잔액\n");
        printf("%-8s %-8s %-11s %-5d %-5d %-5d\n",s[i]->snum,s[i]->name,s[i]->phone,s[i]->input,s[i]->expend,s[i]->balance);
    }
}

int chargeMoney(Student *s[]){

    return 1;
}
int useMoney(Student *s[]){

}

void saveDate(Student *s[]){

}