#ifndef	__STRUCTS__
#define	__STRUCTS__

#define MAX_LEN 100
#define STR_LEN 30

typedef struct _Point{
    int balance;
    int usable; // Yes : 1, No : 0
}Point;

typedef struct _Member{
    char name[STR_LEN]; // 이름
    int mnum; // 회원 번호
    char phone[STR_LEN]; // 연락처
    int totalSpend; // 총 소비량
    int level; // index of level (0~4)
    Point point;
}Member;

#endif