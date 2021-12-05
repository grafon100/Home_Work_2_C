//
//  main.cpp
//  home_work_2_1
//
//  Created by grafon100 on 28/11/2021.
//  Napisz program umożliwiający obliczanie i wyświetlanie podanych działań na macierzach kwadratowych (prostokątnych) o podanym przez użytkownika wymiarze n (n × m) wypełnionej losowo w zakresie <1,100> :

//• sumy dwóch macierzy;

#include <iostream>
#include <iomanip>
#include <time.h>


using namespace std;




int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    int row,col;
    cout<<"Input value rows:\t";
    cin>>row;
    cout<<"Input value colums:\t";
    cin>>col;
    
    
    int myMatrix1[row][col];
    int myMatrix2[row][col];
    int resultMatrix[row][col];
    
    //fill matrix
    for (int i = 0; i<row; i++) {
        for (int j = 0; j<col; j++) {
            myMatrix1[i][j] = rand()%100+1;
        }
    }

    for (int i = 0; i<row; i++) {
        for (int j = 0; j<col; j++) {
            myMatrix2[i][j] = rand()%100+1;
        }
    }
    
    
    for (int i = 0; i<row; i++) {
        for (int j = 0; j<col; j++) {
            resultMatrix[i][j] = myMatrix1[i][j] + myMatrix2[i][j];
        }
    }
    
    
    //output matrix
    cout<<"===============================\n";
    cout<<"The first matrix:\n";
    for (int i = 0; i<row; i++) {
        for (int j = 0; j<col; j++) {
            cout<<setw(4)<<myMatrix1[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"\nThe second matrix:\n";
    for (int i = 0; i<row; i++) {
        for (int j = 0; j<col; j++) {
            cout<<setw(4)<<myMatrix2[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    cout<<"\nResult add first matrix to second matrix:\n";
    for (int i = 0; i<row; i++) {
        for (int j = 0; j<col; j++) {
            cout<<setw(4)<<resultMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    
    
    cout<<endl;
    return 0;
}
