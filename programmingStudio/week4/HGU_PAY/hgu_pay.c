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
#include <string.h>

#define INPUT_FILE "student.txt"
#define OUPUT_FILE "report.txt"

#define MAX_LEN 50
#define STR_LEN 30

// 학생 정보 구조체
typedef struct _Student{
    char snum[STR_LEN]; // 학번
    char name[STR_LEN]; // 이름
    char phone[STR_LEN]; // 연락처
    int charge; // 충전 횟수
    int expend; // 사용 횟수
    int balance; // 잔액
}Student;

int selectMenu(); // select menu
int findStudentIndex(Student *s[],int cnt); // find student index
void printOneStudent(Student *s[], int index); // print one student
int loadData(Student *s[]); // Load data from file
int addStudent(Student *s[],int cnt); // Create
void readStudent(Student *s[],int cnt); // Read
void updateStudent(Student *s[], int cnt); // Update
int deleteStudent(Student *s[], int cnt); // Delete
void searchStudent(Student *s[], int cnt); // Search student
void chargeMoney(Student *s[], int cnt); // Charge money
void useMoney(Student *s[],int cnt); // Expend money
void saveData(Student *s[],int cnt); // Save data

int main(){
    Student* student[MAX_LEN] = {NULL,};

    int menu,count = 0;
    
    count = loadData(student);

    printf("*** HGU Pay ***\n");
    while(1){
        menu = selectMenu();
        if(menu == 1){
            readStudent(student,count);
        }else if(menu == 2){
            count = addStudent(student,count);
        }else if(menu == 3){
            updateStudent(student,count);
        }else if(menu == 4){
            count = deleteStudent(student,count);
        }else if(menu == 5){
            searchStudent(student,count);
        }else if(menu == 6){
            chargeMoney(student,count);
        }else if(menu == 7){
            useMoney(student,count);
        }else if(menu == 8){
            saveData(student,count);
        }else break;
    }
}

void printOneStudent(Student *s[], int index){
    printf("%3d   %-10s %-10s %-14s %-9d %-9d %-9d\n",index+1,s[index]->snum,s[index]->name,s[index]->phone,s[index]->charge,s[index]->expend,s[index]->balance);
}

int findStudentIndex(Student *s[],int cnt){
    int index = 0;
    readStudent(s,cnt);
    printf("\n");
    printf("Index number of the student you are looking for? ");
    scanf("%d",&index);
    return index-1;
}

int loadData(Student *s[]){
    FILE* fp = NULL;
    fp = fopen(INPUT_FILE,"r");
    if(fp == NULL){
        printf("Failed to open file %s on line %d of file %s",INPUT_FILE,__LINE__,__FILE__);
        exit(-1);
    }
    int i=0;
    while(1){
        if(feof(fp)) break;
        s[i] = (Student*)malloc(sizeof(Student));
        fscanf(fp,"%s",s[i]->snum);
        fscanf(fp,"%s",s[i]->name);
        fscanf(fp,"%s",s[i]->phone);
        fscanf(fp,"%d",&s[i]->charge);
        fscanf(fp,"%d",&s[i]->expend);
        fscanf(fp,"%d",&s[i]->balance);
        i++;
    }
    fclose(fp);
    printf("%d students are uploded",i);

    return i;
}

int selectMenu(){
    int menu = 0;
    printf("\n1. 조회\n");
    printf("2. 학생 추가\n");
    printf("3. 학생 정보 수정\n");
    printf("4. 학생 삭제\n");
    printf("5. 검색\n");
    printf("6. 충전\n");
    printf("7. 사용\n");
    printf("8. 저장\n");
    printf("0. 종료\n");
    printf("메뉴 입력 => ");

    scanf("%d",&menu);
    return menu;
}
int addStudent(Student *s[],int cnt){
    s[cnt] = (Student*)malloc(sizeof(Student));

    printf("Student number? ");
    scanf("%s",s[cnt]->snum);
    printf("Name? ");
    scanf("%s",s[cnt]->name);
    printf("Phone number? ");
    scanf("%s",s[cnt]->phone);
    printf("Student %s's data is uploded\n",s[cnt]->name);

    return cnt + 1;
}

void readStudent(Student *s[],int cnt){
    printf("\n번호  학번       이름       연락처         충전 횟수 사용 횟수 현재 잔액\n");
    for(int i=0; i<cnt; i++){
        printf("%3d   %-10s %-10s %-14s %-9d %-9d %-9d\n",i+1,s[i]->snum,s[i]->name,s[i]->phone,s[i]->charge,s[i]->expend,s[i]->balance);
    }
}

void updateStudent(Student *s[], int cnt){
    int index = findStudentIndex(s,cnt);
    printf("New student number? ");
    scanf("%s",s[index]->snum);
    printf("New name? ");
    scanf("%s",s[index]->name);
    printf("New phone number? ");
    scanf("%s",s[index]->phone);
    s[index]->charge = 0;
    s[index]->expend = 0;
    s[index]->balance = 0;
    printf("Student %s's data is updated\n",s[index]->name);
}

int deleteStudent(Student *s[], int cnt){
    int index = findStudentIndex(s,cnt);
    char yesno = ' ';
    printf("Do you want to delete %s student's data?(Y,N) => ",s[index]->name);
    getchar();
    scanf("%c",&yesno);
    if(yesno == 'y'){
        for(int i=index; i<cnt; i++){
            s[i] = s[i+1];
        }
        free(s[cnt]);
        s[cnt] = NULL;
        printf("This Student is deleted.\n");
        return cnt-1;
    }
    else{
        printf("No Delete.\n");
        return cnt;
    }
}

void searchStudent(Student *s[], int cnt){
    int mode = 0;
    printf("Choose finding mode(1: name, 2: year of enrollment) => ");
    scanf("%d",&mode);

    int index = 0;
    int count = 0;

    while(1){
        if(mode == 1){

            printf("The name of the student you are looking for? ");
            char i_string[STR_LEN] = "";
            scanf("%s",i_string);
            for(int i=0; i<cnt; i++){
                if(strstr(s[i]->name,i_string)){
                    count++;
                    if(count == 1) printf("번호  학번       이름       연락처         충전 횟수 사용 횟수 현재 잔액\n");
                    printOneStudent(s,i);
                }
            }
            printf("Found %d students\n",count);
            break;
        }
        else if(mode == 2){
            int year = 0;
            printf("Year of enrollment? ");
            scanf("%d",&year);
            for(int i=0; i<cnt; i++){
                int e_year = atoi(s[i]->snum) / 100000 % 100;
                if(e_year == year){
                    count++;
                    if (count == 1) printf("번호  학번       이름       연락처         충전 횟수 사용 횟수 현재 잔액\n");
                    printOneStudent(s,i);
                }
            }
            printf("Found %d students\n",count);
            break;
        }
        else printf("Wrong number!\n");
    }
}

void chargeMoney(Student *s[], int cnt){
    int index = findStudentIndex(s,cnt);
    printf("How many charge time?(one time : 10000 Woon)\n");
    int charge = 0;
    scanf("%d",&charge);
    s[index]->charge = charge;
    
    s[index]->balance += 10000 * charge;
}
void useMoney(Student *s[], int cnt){
    int index = findStudentIndex(s,cnt);
    printf("How many expend time?(one time : 10000 Woon)\n");
    int expend = 0;
    scanf("%d",&expend);
    s[index]->expend = expend;
    
    s[index]->balance -= 10000 * expend;
}

void saveData(Student *s[], int cnt){
    // student.txt에 변경사항 저장하기
    FILE* fp = NULL;
    fp = fopen(INPUT_FILE,"w");
    if(fp == NULL){
        printf("Failed to open the file %s on line %d of file %s",INPUT_FILE,__LINE__,__FILE__);
        exit(-1);
    }

    for(int i=0; i<cnt; i++){
        fprintf(fp,"%s %s %s %d %d %d\n",s[i]->snum,s[i]->name,s[i]->phone,s[i]->charge,s[i]->expend,s[i]->balance);
    }

    //파일 닫기
    fclose(fp);

    // report.txt에 보고서 출력하기
    fp = fopen(OUPUT_FILE,"w");
    if(fp == NULL){
        printf("Failed to open the file %s on line %d of file %s",OUPUT_FILE,__LINE__,__FILE__);
        exit(-1);
    }

    fprintf(fp,"\n번호  학번       이름       연락처         충전 횟수 사용 횟수 현재 잔액\n");
    for(int i=0; i<cnt; i++){
        fprintf(fp,"%3d  %-10s%-10s%-12s %-7d %-7d %-7d\n",i+1,s[i]->snum,s[i]->name,s[i]->phone,s[i]->charge,s[i]->expend,s[i]->balance);
    }
    
    // 파일 닫기
    fclose(fp);
    
    // 저장 되었음을 알리기
    printf("저장됐다.\n");
}

/*
다음에 만들 때는 금액을 좀 다양하게 해야할 듯
*/