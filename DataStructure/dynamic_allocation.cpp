#include <iostream>
using namespace std;

int main(){
    int row,col;
    
    cin >> row >> col;
    int** dp = new int* [row];
    for(int i=0; i<row; i++){
        dp[i] = new int[col];
        for(int j=0; j<col; j++){
            dp[i][j] = i*col + j;
            cout << dp[i][j] << '\t';
        }
        cout << endl;
    }

    // deleting
    for(int i=0; i<row; i++){
        delete []dp[i];
    }
    delete []dp;
}