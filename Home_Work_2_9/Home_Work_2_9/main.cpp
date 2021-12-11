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
// обязательно нужно проиницилизировать массив что бы
// не оставлять муссор! а когда не нужно то удалить!
int *arrBig;

// функция увеличения массива
int *arrSizePlus(int *arr, int size){
    arrBig = new int [size+1];
    for(int i = 0; i<size; i++){
        arrBig[i] = arr[i];
    }
    delete [] arr;
    return arrBig;
}



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
    cout<<endl;
    
    
//    bool start = true;
//    while(start){
        int num = 0;
        int count = 1;
        int *arrResult;
        for(int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++) {
                
                int colich = 0;
                
                int *arrNew = new int [count];
               
                num = arr1[i][j];
                 
               
                
                
                
                
                for(int i = 0; i<rows; i++){
                    for (int j = 0; j<cols; j++) {
                        if(num == arr1[i][j]){
                            colich++;
                        }
                        
                    }
                }
                
                
                
                
             
                
                delete [] arrNew;
                cout<<num<<": "<<colich<<endl;
            }
            
            
        }
        
        
        
//    }
    
    
    
    
    
    
    
    
    deleteArr(arr1, rows);
    
    delete [] arrResult;
    
    
    delete [] arrBig;
    
    
    
    return 0;
}
