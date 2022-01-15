//
//  main.cpp
//  Home_Work_2
//
//  Created by grafon100 on 02/12/2021.
//

#include <iostream>
#include <time.h>
#include <iomanip>
#include <math.h>

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


//1 ----- sumy dwóch macierzy
void sumArrays(int **arr1, int **arr2, int **arrResult, int row, int col){
    for(int i = 0; i<row; i++){
        for (int j = 0; j<col; j++) {
            arrResult[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

//2.  ---- różnicy dwóch macierzy
void subArrays(int **arr1, int **arr2, int **arrResult, int row, int col){
    for(int i = 0; i<row; i++){
        for (int j = 0; j<col; j++) {
            arrResult[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    
}

//3. ---- iloczynu dwóch macierzy
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

//4. ---- transpozycji jednej macierzy
void transportArray(int **arr, int **arrResult, int row, int col){
    for(int i = 0; i<col; i++){
        for (int j = 0; j<row; j++) {
            arrResult[i][j] = arr[j][i];
        }
    }
}

//5. ---- zerowania elementów na głównej przekątnej danej macierzy
void zeroArrays(int **arr, int **arrResult, int row, int col){
    for(int i = 0; i<row; i++){
        for (int j = 0; j<col; j++) {
            if(i != j){
                arrResult[i][j] = arr[i][j];
            } else {
                arrResult[i][j] = 0;
            }
        }
    }
}

//6. ---- iloczynu odwrotności wszystkich niezerowych elementów
double prodRecip(int **arr, int row, int col){
    double result = 1;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            if(arr[i][j] != 0){
                result *= (1.0/arr[i][j]);
            }
        }
    }
    return result;
}

//7. ---- średniej arytmetycznej podanych liczb
double averageArith(int **arr, int row, int col){
    double result = 0;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            result += arr[i][j];
        }
    }
    result /= (row*col);
    
    return result;
}


//8. ---- średniej geometrycznej wartości bezwzględnej podanych liczb
double geometricMean(int **arr, int row, int col){
    double result = 1;
    double count = row*col;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            result *= abs(arr[i][j]);
        }
    }
    result = pow(result, 1.0/count);
    return result;
}


//Start Task ---- 9. częstości występowania każdej wartości

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

void checkAndOutput(int **arr1, int rows, int cols){
    int **arrTest = nullptr;
    int sizeArrTest = 0;
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            int timeRepit = 0;
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
                arrTest = creat2Darr(sizeArrTest, 2);
                arrTest[0][0] = num;
                arrTest[0][1] = timeRepit;
                
            } else if (checkRepitEl(num, arrTest, sizeArrTest)){
                addElement(arrTest, sizeArrTest, num, timeRepit);
            }
        }
    }
    printTestArr(arrTest, sizeArrTest, 2);
    
    arrayDelete(arrTest, sizeArrTest);
}
//End Task ---- 9



int main(int argc, const char * argv[]) {
    srand(time(NULL));

    int rows, cols;
    int **myArray1;
    int **myArray2;
    int **resultArray;
    
    int type;
    
    bool repeat = true;
  
    
    
    while(repeat){
        
        bool answer = true;
        
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
                //1 -sumy dwóch macierzy
                cout<<"===========================\n";
    
                resultArray = creat2Darr(rows, cols);
                sumArrays(myArray1, myArray2, resultArray, rows, cols);
                
                cout<<"Sum First and Second array\n";
                cout<<"===========================\n";
                printArray(resultArray, rows, cols);
                
                arrayDelete(resultArray, rows);
                break;
            case 2:
                //2 -różnicy dwóch macierzy
                resultArray = creat2Darr(rows, cols);
                subArrays(myArray1, myArray2, resultArray, rows, cols);
                
                cout<<"First array sub Second array\n";
                printArray(resultArray, rows, cols);
                
                arrayDelete(resultArray, rows);
                break;
            case 3:
                //3 -iloczynu dwóch macierzy
                cout<<"Mult First and Second array\n";
                if(rows == cols){
                    resultArray = creat2Darr(rows, cols);
                    multArrays(myArray1, myArray2, resultArray, rows, cols);
                    
                    printArray(resultArray, rows, cols);
                    arrayDelete(resultArray, rows);
                } else {
                    cout<<"Такие матрицы нельзя перемножить, так как количество столбцов матрицы А не равно количеству строк матрицы В.\n";
                    cout<<"Try again  >>>>>>>>>>>>>>>>>>>>>>\n";
                    answer = false;
                    break;
                }
                break;
            case 4:
                //-transpozycji jednej macierzy
                resultArray = creat2Darr(cols, rows);
            
                transportArray(myArray1, resultArray, rows, cols);
        
                cout<<"Tarnsport First array\n";
                printArray(resultArray, cols, rows);
                arrayDelete(resultArray, cols);
                break;
            case 5:
                //5 -zerowania elementów na głównej przekątnej danej macierzy
                cout<<"===========================\n";
                if(rows == cols){
                resultArray = creat2Darr(rows, cols);
                

                zeroArrays(myArray1, resultArray, rows, cols);
                
                cout<<"Sum First and Second array\n";
                cout<<"===========================\n";
                printArray(resultArray, rows, cols);
                
                arrayDelete(resultArray, rows);
                } else {
                    cout<<"Выбраная матрица не явлется квадратичной не возможно обнаружить диагональ!\n";
                    cout<<"Try again  >>>>>>>>>>>>>>>>>>>>>>\n";
                    answer = false;
                    break;
                }
                break;
                
            case 6:
                //6 -iloczynu odwrotności wszystkich niezerowych elementów
                double resultProdArr1;
                double resultProdArr2;
                
                resultProdArr1 = prodRecip(myArray1, rows, cols);
                cout<<"Average first array = "<<resultProdArr1<<endl;
                
                resultProdArr2 = prodRecip(myArray2, rows, cols);
                cout<<"Average second array = "<<resultProdArr2<<endl;

                break;
                

                
            case 7:
//              7 -średniej arytmetycznej podanych liczb
                double resultAverageArr1;
                double resultAverageArr2;
                
                resultAverageArr1 = averageArith(myArray1, rows, cols);
                cout<<"Average first array = "<<resultAverageArr1<<endl;
                
                resultAverageArr2 = averageArith(myArray2, rows, cols);
                cout<<"Average second array = "<<resultAverageArr2<<endl;
                break;

                
            case 8:
//              8 -średniej geometrycznej wartości bezwzględnej podanych liczb
                double resultGeometricArr1;
                double resultGeometricArr2;
                
                resultGeometricArr1 = geometricMean(myArray1, rows, cols);
                cout<<"Average first array = "<<resultGeometricArr1<<endl;
                
                resultGeometricArr2 = geometricMean(myArray2, rows, cols);
                cout<<"Average second array = "<<resultGeometricArr2<<endl;
        
                break;
                
            case 9:
//              9 -częstości występowania każdej wartości
                cout<<"~~ ~~ ~~ ~~ ~~\n";
                cout<<"First array\n";
                checkAndOutput(myArray1, rows, cols);
                cout<<"~~ ~~ ~~ ~~ ~~\n";
                cout<<"Second array\n";
                checkAndOutput(myArray2, rows, cols);
                
                break;
            default:
                cout<<"Wrong poosition!"<<endl;
                break;
        }
    
        


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
