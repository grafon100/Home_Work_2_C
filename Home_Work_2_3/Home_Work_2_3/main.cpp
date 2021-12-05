//
//  main.cpp
//  Home_Work_2_3
//
//  Created by grafon100 on 04/12/2021.
//

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    int rows, cols;
    cout<<"Input rows: ";
    cin>>rows;
    cout<<"Input cols: ";
    cin>>cols;
    
    int **myArr1 = new int *[rows];
    for (int i = 0; i<rows; i++) {
        myArr1[i] = new int [cols];
    }
    
    int **myArr2 = new int *[rows];
    for (int i = 0; i<rows; i++) {
        myArr2[i] = new int [cols];
    }
    
    int **myArr3 = new int *[rows];
    for (int i = 0; i<rows; i++) {
        myArr3[i] = new int [cols];
    }
    
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<cols; j++) {
            myArr1[i][j] = rand()%5+1;
        }
    }

    
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<cols; j++) {
            myArr2[i][j] = rand()%5+1;
        }
    }
    
    
    
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<cols; j++) {
            int result = 0;
            int y1 = 0;
            int x2 = 0;

                while(x2<rows && y1<cols){
                result += myArr1[i][y1] * myArr2[x2][j];
            
                y1++;
                x2++;
                }
          
            myArr3[i][j] = result;
        }
    }
    
    
    
    cout<<"==================================\n";
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<cols; j++) {
            cout<<setw(3)<<myArr1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------------\n";
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<cols; j++) {
            cout<<setw(3)<<myArr2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"==================================\n";
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<cols; j++) {
            cout<<setw(3)<<myArr3[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    
    
    for (int i = 0; i<rows; i++) {
        delete [] myArr1[i];
    }
    delete []myArr1;
    
    for (int i = 0; i<rows; i++) {
        delete [] myArr2[i];
    }
    delete []myArr2;
    
    for (int i = 0; i<rows; i++) {
        delete [] myArr3[i];
    }
    delete []myArr3;
    
    return 0;
}
