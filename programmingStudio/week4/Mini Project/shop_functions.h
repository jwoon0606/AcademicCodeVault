#include "shop_structs.h"

#ifndef	__FUNCTIONS__
#define	__FUNCTIONS__


int selectMenu(); // select menu
int loadData(Member *m[]); // Load data from file

int findMemberIndex(Member *m[],int cnt); // find Member index
void printOneMember(Member *m[], int index); // print one member

int findLevel(int spend);
int findPointUsable(int balance);

int addMember(Member *m[],int cnt); // Create
void readMember(Member *m[],int cnt); // Read
void updateMember(Member *m[], int cnt); // Update
int deleteMember(Member *m[], int cnt); // Delete

void searchMember(Member *m[], int cnt); // Search Member
void caculateTotal(Member *m[], int cnt); // calculate total won

void saveData(Member *m[],int cnt); // Save data


#endif




