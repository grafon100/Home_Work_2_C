//
//  main.cpp
//  Home_Work_2_9
//
//  Created by grafon100 on 06/12/2021.
//

#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int **creatArr(int row, int col){
    int **arr = new int *[row];
    for(int i = 0; i<row; i++){
        arr[i] = new int [col];
    }
    return arr;
}


void fillArr(int **arr, int row, int col){
    for (int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++){
            arr[i][j] = rand()%10+1;
        }
    }
}


void printArr(int **arr, int row, int col){
    for (int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


void deleteArr(int **arr, int row){
    for(int i = 0; i<row; i++){
        delete [] arr[i];
    }
    delete [] arr;
}



int main(int argc, const char * argv[]) {
    srand(time(0));
    int rows, cols;
    int **arr1;
    
    cout<<"Input rows: ";
    cin>>rows;
    cout<<"Input cols: ";
    cin>>cols;
    
    arr1 = creatArr(rows, cols);
    fillArr(arr1, rows, cols);
    printArr(arr1, rows, cols);
    
    
    
    for(int i = 0; i<rows; i++){
        for (int j = 0; j<cols; j++) {
            //int num = arr1[i][j];
            
            
        }
    }
    
    
    
    
    
    
    
    
    
    deleteArr(arr1, rows);
    
    
    
    return 0;
}
