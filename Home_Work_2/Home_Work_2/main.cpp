//
//  main.cpp
//  Home_Work_2
//
//  Created by grafon100 on 02/12/2021.
//



#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int **creat2Darr(int row, int col){
    int **newArray = new int *[row];
    for(int i = 0; i<row; i++){
        newArray[i] = new int[col];
    }
    
    return newArray;
}

void fillArray(int **arr, int row, int col){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            arr[i][j] = random()%10+1;
        }
    }
}

void printArray(int **arr, int row, int col){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<setw(3)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void arrayDelete(int **arr, int row){
    for(int i = 0; i<row; i++){
        delete [] arr[i];
    }
    delete [] arr;
}

void sumArrays(int **arr1, int **arr2, int **arrResult, int row, int col){
    for(int i = 0; i<row; i++){
        for (int j = 0; j<col; j++) {
            arrResult[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    
}

void subArrays(int **arr1, int **arr2, int **arrResult, int row, int col){
    for(int i = 0; i<row; i++){
        for (int j = 0; j<col; j++) {
            arrResult[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    
}


void multArrays(int **arr1, int **arr2, int **arrResult, int row, int col){
    for(int i = 0; i<row; i++){
        for (int j = 0; j<col; j++) {
            int resultMult = 0;
            int y1 = 0;
            int x2 = 0;
            
            while(y1<col){
                resultMult += arr1[i][y1] * arr2 [x2][j];
                y1++;
                x2++;
            }
            arrResult[i][j] = resultMult;
        }
    }
}

void transportArray(int **arr1, int **arrResult, int row, int col){
    
}



int main(int argc, const char * argv[]) {
    //раскомить!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //srand(time(NULL));
    //раскомить!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    int rows, cols;
    int **myArray1;
    int **myArray2;
    
    int type;
    
    bool repeat = true;
    bool answer = true;
    
    
    while(repeat){
        cout<<"Input your 2D rows: ";
        cin>>rows;
        cout<<"Input your 2D cols: ";
        cin>>cols;
        cout<<"--------------------------------\n";
        cout<<"Choice type operation\n";
        cout<<"1 -sumy dwóch macierzy\n";
        cout<<"2 -różnicy dwóch macierzy\n";
        cout<<"3 -iloczynu dwóch macierzy\n";
        cout<<"4 -transpozycji jednej macierzy\n";
        cout<<"5 -zerowania elementów na głównej przekątnej danej macierzy\n";
        cout<<"6 -iloczynu odwrotności wszystkich niezerowych elementów\n";
        cout<<"7 -średniej arytmetycznej podanych liczb\n";
        cout<<"8 -średniej geometrycznej wartości bezwzględnej podanych liczb\n";
        cout<<"9 -częstości występowania każdej wartości\n";
        cout<<"--------------------------------\n";
        cout<<"Input type operation: ";
        cin>>type;
        cout<<"--------------------------------\n";
        
   
        //creating myArrays
        myArray1 = creat2Darr(rows, cols);
        myArray2 = creat2Darr(rows, cols);
        
        //filling myArrays
        fillArray(myArray1, rows, cols);
        fillArray(myArray2, rows, cols);
        
        //print myArrays
        cout<<"First array\n";
        printArray(myArray1, rows, cols);
        cout<<"Second array\n";
        printArray(myArray2, rows, cols);
        
        
        switch (type) {
            case 1:
                //sum
                cout<<"===========================\n";
                int **resultArray;
                
                resultArray = creat2Darr(rows, cols);
                sumArrays(myArray1, myArray2, resultArray, rows, cols);
                
                cout<<"Sum First and Second array\n";
                cout<<"===========================\n";
                printArray(resultArray, rows, cols);
                
                arrayDelete(resultArray, rows);
                break;
            case 2:
                //sub
                resultArray = creat2Darr(rows, cols);
                subArrays(myArray1, myArray2, resultArray, rows, cols);
                
                cout<<"First array sub Second array\n";
                printArray(resultArray, rows, cols);
                
                arrayDelete(resultArray, rows);
                break;
            case 3:
                //sub
                cout<<"Mult First and Second array\n";
                if(rows == cols){
                    resultArray = creat2Darr(rows, cols);
                    multArrays(myArray1, myArray2, resultArray, rows, cols);
                    
                    //cout<<"Mult First and Second array\n";
                    printArray(resultArray, rows, cols);
                    
                    arrayDelete(resultArray, rows);
                } else {
                    cout<<"Такие матрицы нельзя перемножить, так как количество столбцов матрицы А не равно количеству строк матрицы В.\n";
                    cout<<"Try again  >>>>>>>>>>>>>>>>>>>>>>\n";
                    answer = false;
                    break;
                }
                break;
                
            default:
                break;
        }
        
        
        
        //delete myArrays
        arrayDelete(myArray1, rows);
        arrayDelete(myArray2, rows);


//Вопрос повторить задание или нет
       
        while(answer){
            string choice;
            cout<<"Continue? Y/N \n";
            cin>>choice;
            
            if(choice == "Y" || choice == "y"){
                repeat = true;
                answer = false;
                cout<<"-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
            } else if (choice == "N" || choice == "n"){
                repeat = false;
                answer = false;
            } else {
                cout<<"Wrong simbol, input Y, y, N, n \n";
                answer = true;
            }
        }
        
        
    }
    
    
    
    return 0;
}