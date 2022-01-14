//
//  main.cpp
//  Table
//
//  Created by grafon100 on 08/01/2022.
//

#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    
    int ** myArr = new int *[7];
    for (int i = 0; i<7; i++) {
//        int size;
//        if(i%2 == 0){
//            size = 4;
//        } else {
//            size = 2;
//        }
//        myArr[i] = new int [size];
        myArr[i] = new int [4-2*(i%2)];
    }
    
    
    for(int i = 0; i<7; i++){
        if(i%2==0){
            for (int j = 0; j<4; j++) {
                //rand%(b-a)+a  a=-14; b=31
                myArr[i][j] = rand()%(31+14)-14;
            }
        } else {
            for (int j = 0; j<2; j++) {
                //rand%(b-a)+a  a=-14; b=31
                myArr[i][j] = rand()%(31+14)-14;
            }
            
        }
    }
    
    for(int i = 0; i<7; i++){
        if(i%2==0){
            for (int j = 0; j<4; j++) {
                cout<<setw(3)<<myArr[i][j]<<" ";
            }
        } else {
            for (int j = 0; j<2; j++) {
            
                cout<<setw(3)<<myArr[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    
    
    
    
    for(int i = 0; i<7; i++){
        delete [] myArr[i];
    }
    delete [] myArr;
    
    return 0;
}
