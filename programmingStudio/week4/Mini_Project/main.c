/*
쇼핑몰 회원 관리 프로그램

1) 기본 컨셉
온라인 쇼핑몰 회원들의 정보를 관리하는 프로그램
구매할 때마다 포인트 적립
총 소비 금액을 기준으로 등급 나뉨
등급이 높을 수록 할인율, 포인트 적립 높음
포인트는 5000원 이상부터 사용 가능

2) 선언할 구조체
a. 회원 구조체
회원 번호(무작위), 이름, 연락처, 총 소비량, 등급, 포인트(구조체)

b. 포인트 구조체
포인트 잔액, 사용 가능 여부(5000 포인트 이상인지)

3) 사용할 함수
- 메뉴 선택
- 회원 인덱스 찾기
- 해당 인덱스의 회원 한 명 정보 출력
- 데이터 불러오기
- 회원 추가하기
- 회원 조회
- 회원 정보 수정
- 회원 정보 삭제
- 회원 정보 검색
- 결제 금액 계산
- 정보 저장

4) branch 사용
- main : main.c 관리, README.md 파일 제작, screenshots 폴더 관련 업무
- headfile : 헤더 파일 제작
- function : 함수 기능 구현 c 파일 제작
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "shop_structs.h"
#include "shop_functions.h"
#include "shop_functions.c"

int main(){
    Member* member[MAX_LEN] = {NULL,};

    int menu,count = 0;
    srand(time(0));
    
    count = loadData(member);

    printf("*** 온라인 쇼핑몰 회원관리 프로그램 ***\n");
    while(1){
        menu = selectMenu();
        if(menu == 1){
            readMember(member,count);
        }else if(menu == 2){
            count = addMember(member,count);
        }else if(menu == 3){
            updateMember(member,count);
        }else if(menu == 4){
            count = deleteMember(member,count);
        }else if(menu == 5){
            searchMember(member,count);
        }else if(menu == 6){
            caculateTotal(member,count);
        }else if(menu == 7){
            saveData(member,count);
        }else break;
    }
}