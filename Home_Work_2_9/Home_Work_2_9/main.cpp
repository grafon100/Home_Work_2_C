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
            cout<<setw(3)<<arr[i][j]<<" ";
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



//push back element
void addElement(int **&arr, int &rows, int value, int timeR){
    rows++;
    int **newArr = new int *[rows];
    for(int i = 0; i<rows; i++){
        newArr[i] = new int [2];
    }
    
    
    for(int i = 0; i<rows-1; i++){
        for(int j = 0; j<2; j++){
            newArr[i][j] = arr[i][j];
        }
    }
    

    newArr[rows-1][0] = value;
    newArr[rows-1][1] = timeR;
    
    for(int i = 0; i<rows-1; i++){
        delete [] arr[i];
    }
    delete [] arr;

    arr = newArr;
}


//check elements wich repit
bool checkRepitEl(int value, int **arrControl, int sizeControl){
    bool notFound = true;
    for(int i = 0; i<sizeControl; i++ ){
        if(arrControl[i][0] == value){
            notFound = false;
        }
    }
    return notFound;
}


void printTestArr(int **arr, int row, int col){
    for (int i = 0; i<row; i++) {
        cout<<arr[i][0]<<"\tis repit: ";
        for(int j = 1; j<col; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}




int main(int argc, const char * argv[]) {
    srand(time(0));
    int rows, cols, timeRepit;
    int **arr1;
    int **arrTest = nullptr;
    int sizeArrTest = 0;
    
    
    cout<<"Input rows: ";
    cin>>rows;
    cout<<"Input cols: ";
    cin>>cols;
    
    arr1 = creatArr(rows, cols);
    fillArr(arr1, rows, cols);
    printArr(arr1, rows, cols);
    cout<<endl;
    
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            timeRepit = 0;
            int num = arr1[i][j];
            
            for(int f = 0; f<rows; f++){
                for(int k = 0; k<cols; k++){
                    if(num == arr1[f][k]){
                        timeRepit++;
                    }
                }
            }
            if(sizeArrTest == 0){
                sizeArrTest++;
                arrTest = creatArr(sizeArrTest, 2);
                arrTest[0][0] = num;
                arrTest[0][1] = timeRepit;
                
            } else if (checkRepitEl(num, arrTest, sizeArrTest)){
                addElement(arrTest, sizeArrTest, num, timeRepit);
            }
        }
    }
    
    
    
    

    
    
    printTestArr(arrTest, sizeArrTest, 2);
    
    
  
    
    
    
    
    deleteArr(arr1, rows);
    deleteArr(arrTest, sizeArrTest);

    
    
    
    return 0;
}
