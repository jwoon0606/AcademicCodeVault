#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "shop_structs.h"
#include "shop_functions.h"

#define INPUT_FILE "members.txt"
#define OUPUT_FILE "report.txt"

char LNAME[5][30]={"Bronze","Silver","Gold","Platinum","Diamond"}; // labels by level

// select menu
int selectMenu(){
    int menu = 0;
    printf("\n1. 조회\n");
    printf("2. 회원 추가\n");
    printf("3. 회원 정보 수정\n");
    printf("4. 회원 삭제\n");
    printf("5. 검색\n");
    printf("6. 계산\n");
    printf("7. 저장\n");
    printf("0. 종료\n");
    printf("메뉴 입력 => ");

    scanf("%d",&menu);
    return menu;
} 

 // Load data from file
int loadData(Member *m[]){
    FILE* fp = NULL;
    fp = fopen(INPUT_FILE,"r");
    if(fp == NULL){
        printf("Failed to open file %s on line %d of file %s",INPUT_FILE,__LINE__,__FILE__);
        exit(-1);
    }
    int i=0;
    while(!feof(fp)){
        m[i] = (Member*)malloc(sizeof(Member));
        fscanf(fp,"%d",&m[i]->mnum);
        fscanf(fp,"%s",m[i]->name);
        fscanf(fp,"%s",m[i]->phone);
        fscanf(fp,"%d",&m[i]->totalSpend);
        m[i]->level = findLevel(m[i]->totalSpend);
        fscanf(fp,"%d",&m[i]->point.balance);
        if(m[i]->point.balance >= 5000) m[i]->point.usable = 1;
        else m[i]->point.usable = 0;
        i++;
    }
    fclose(fp);
    printf("%d members are uploded\n",i-1);

    return i-1;
}

// find Member index
int findMemberIndex(Member *m[],int cnt){
    int index = 0;
    readMember(m,cnt);
    printf("\n");
    printf("Index number of the member you are looking for? ");
    scanf("%d",&index);
    return index-1;
}

int findLevel(int spend){
    int range[5]={50000,300000,1000000,3000000,10000000}; // range for level
	for(int j=0;j<5;j++)
		if(spend<range[j])
			return j;
	return 0;
}

int findPointUsable(int balance){
    if(balance >= 5000) return 1;
    else return 0;
}

// print one member
void printOneMember(Member *m[], int index){
    printf("%3d   %-12d %-10s %-14s %-9d %-9s %-9d\n",index+1,m[index]->mnum,m[index]->name,m[index]->phone,m[index]->totalSpend,LNAME[m[index]->level],m[index]->point.balance);
}

// Create
int addMember(Member *m[],int cnt){
    m[cnt] = (Member*)malloc(sizeof(Member));

    m[cnt]->mnum = rand()%10000 + 1;

    printf("Name? ");
    scanf("%s",m[cnt]->name);
    printf("Phone number? ");
    scanf("%s",m[cnt]->phone);

    m[cnt]->point.balance = 2000;
    m[cnt]->point.usable = 0;

    printf("Member %s's data is uploded\n",m[cnt]->name);

    return cnt + 1;
}

// Read
void readMember(Member *m[],int cnt){
    printf("\n번호  회원 번호    이름       연락처         총 소비량  등급    포인트 잔액\n");
    for(int i=0; i<cnt; i++){
        printf("%3d   %-12d %-10s %-14s %-9d %-9s %-9d\n",i+1,m[i]->mnum,m[i]->name,m[i]->phone,m[i]->totalSpend,LNAME[m[i]->level],m[i]->point.balance);
    }
}

// Update
void updateMember(Member *m[], int cnt){
    int index = findMemberIndex(m,cnt);
    
    m[index]->mnum = rand()%10000 + 1;
    printf("New member's name? ");
    scanf("%s",m[index]->name);
    printf("New member's phone number? ");
    scanf("%s",m[index]->phone);
    printf("New member's total spend? ");
    scanf("%d",&m[index]->totalSpend);
    m[index]->level = findLevel(m[index]->totalSpend);
    printf("New member's point balance? ");
    scanf("%d",&m[index]->point.balance);
    m[index]->point.usable = findPointUsable(m[index]->point.balance);

    printf("Member %s's data is updated\n",m[index]->name);
}
int deleteMember(Member *m[], int cnt){
    int index = findMemberIndex(m,cnt);
    char yesno = ' ';
    printf("Do you want to delete %s student's data?(Y,N) => ",m[index]->name);
    getchar();
    scanf("%c",&yesno);
    if(yesno == 'y'){
        for(int i=index; i<cnt; i++){
            m[i] = m[i+1];
        }
        free(m[cnt]);
        m[cnt] = NULL;
        printf("This Member is deleted.\n");
        return cnt-1;
    }
    else{
        printf("No Delete.\n");
        return cnt;
    }
}

void searchMember(Member *m[], int cnt){
    int mode = 0;
    printf("Choose finding mode(1: name, 2: member number, 3: level => ");
    scanf("%d",&mode);

    int index = 0;
    int count = 0;

    while(1){
        if(mode == 1){

            printf("The name of the Member you are looking for? ");
            char i_string[STR_LEN] = "";
            scanf("%s",i_string);
            for(int i=0; i<cnt; i++){
                if(strstr(m[i]->name,i_string)){
                    count++;
                    if(count == 1) printf("\n번호  회원 번호    이름       연락처         총 소비량  등급     포인트 잔액\n");
                    printOneMember(m,i);
                }
            }
            printf("Found %d members\n",count);
            break;
        }
        else if(mode == 2){
            int num = 0;
            printf("Number of member? ");
            scanf("%d",&num);
            for(int i=0; i<cnt; i++){
                if(num == m[i]->mnum){
                    printf("\n번호  회원 번호    이름       연락처         총 소비량  등급     포인트 잔액\n");
                    printOneMember(m,i);
                    break;
                }
            }
            break;
        }
        else if(mode == 3){
            printf("Level you are looking for?(Bronze: 0, Silver: 1, Gold: 2, Platinum: 3, Diamond: 4) ");
            int level = 0;
            scanf("%d",&level);
            for(int i=0; i<cnt; i++){
                if(m[i]->level == level){
                    count++;
                    if(count == 1) printf("\n번호  회원 번호    이름       연락처         총 소비량  등급     포인트 잔액\n");
                    printOneMember(m,i);
                }
            }
            printf("Found %d members\n",count);
            break;
        }
        else printf("Wrong number!\n");
    }
}

void caculateTotal(Member *m[], int cnt){
    // 회원을 찾는다.
    int index = findMemberIndex(m,cnt);

    // 금액을 입력받는다.
    int total = 0;
    printf("How much is total price? ");
    scanf("%d",&total);
    int final_price = total;

    // 등급을 확인해서 할인율을 적용한다
    int level = m[index]->level;
    if(level == 0){
        printf("등급: %s, 할인율: 1%%, 총 할인 금액: %d\n",LNAME[m[index]->level],(int)(final_price*0.01));
        final_price *= 0.99;
    }else if(level == 1){
        printf("등급: %s, 할인율: 3%%, 총 할인 금액: %d\n",LNAME[m[index]->level],(int)(final_price*0.03));
        final_price *= 0.97;
    }else if(level == 2){
        printf("등급: %s, 할인율: 7%%, 총 할인 금액: %d\n",LNAME[m[index]->level],(int)(final_price*0.07));
        final_price *= 0.93;
    }else if(level == 3){
        printf("등급: %s, 할인율: 12%%, 총 할인 금액: %d\n",LNAME[m[index]->level],(int)(final_price*0.12));
        final_price *= 0.88;
    }else if(level == 4){
        printf("등급: %s, 할인율: 20%%, 총 할인 금액: %d\n",LNAME[m[index]->level],(int)(final_price*0.2));
        final_price *= 0.8;
    }

    // 포인트 사용가능한지 확인하고 사용할 것인지 물어본다
    if(m[index]->point.usable == 1){
        printf("Use points?(yes: 1, no: 0) ");
        int yesno = 0;
        scanf("%d",&yesno);
        if(yesno == 1){
            if(m[index]->point.balance >= final_price){
                m[index]->point.balance -= final_price;
                m[index]->point.balance += total / 10;
                m[index]->point.usable = findPointUsable(m[index]->point.balance);
                final_price = 0;
            }else{
                final_price -= m[index]->point.balance;
                m[index]->point.balance = 0;
                m[index]->point.balance += total / 10;
                m[index]->point.usable = findPointUsable(m[index]->point.balance);
            }
        }
    }

    // 최종 결제 금액을 보여 주고 정보에 적용한다.
    printf("Total price: %d\n",final_price);
    m[index]->totalSpend += total;
    m[index]->level = findLevel(m[index]->totalSpend);
}

void saveData(Member *m[],int cnt){
    FILE* fp = NULL;
    fp = fopen(INPUT_FILE,"w");
    if(fp == NULL){
        printf("Failed to open the file %s on line %d of file %s",INPUT_FILE,__LINE__,__FILE__);
        exit(-1);
    }

    for(int i=0; i<cnt; i++){
        fprintf(fp,"%-12d %-10s %-14s %-9d %-9s %-9d\n",m[i]->mnum,m[i]->name,m[i]->phone,m[i]->totalSpend,LNAME[m[i]->level],m[i]->point.balance);
    }

    //파일 닫기
    fclose(fp);

    // report.txt에 보고서 출력하기
    fp = fopen(OUPUT_FILE,"w");
    if(fp == NULL){
        printf("Failed to open the file %s on line %d of file %s",OUPUT_FILE,__LINE__,__FILE__);
        exit(-1);
    }

    fprintf(fp,"\n번호  회원 번호    이름       연락처         총 소비량  등급     포인트 잔액\n");
    for(int i=0; i<cnt; i++){
        fprintf(fp,"%3d   %-12d %-10s %-14s %-9d %-9s %-9d\n",i+1,m[i]->mnum,m[i]->name,m[i]->phone,m[i]->totalSpend,LNAME[m[i]->level],m[i]->point.balance);
    }
    
    // 파일 닫기
    fclose(fp);
    
    // 저장 되었음을 알리기
    printf("저장되었습니다.\n");
}