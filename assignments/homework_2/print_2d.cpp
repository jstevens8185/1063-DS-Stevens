#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    int  i =0, j=0, k=1;
    int Nums[15][15];

    for(i=0;i<15;i++){
        for(j=0;j<15;j++){
            Nums[i][j]=k;
            k++;
            //cout << setw(3) << Nums[j][i] << " ";
        }
        //cout << endl;
    }
     for(i=0;i<15;i++){
        for(j=0;j<15;j++){
           cout << setw(3)<< Nums[j][i]<< " ";
        }
        cout << endl;
     }

 }