//
//  main.cpp
//  Home_Work_2_4
//
//  Created by grafon100 on 05/12/2021.
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
    
    int ** arr = new int *[rows];
    for(int i = 0; i<rows; i++){
        arr[i] = new int[cols];
    }
    
    int ** arrResult = new int *[cols];
    for(int i = 0; i<cols; i++){
        arrResult[i] = new int[rows];
    }
    
    //fill
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            arr[i][j] = random()%10+1;
        }
    }
    
    
    //fill result;
    for (int i = 0; i<cols; i++) {
        for(int j = 0; j<rows; j++){
            arrResult[i][j] = arr[j][i];
        }
    }
    
    
    
    
    //print
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            cout<<setw(3)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"-------------------------\n";
    
    for (int i = 0; i<cols; i++) {
        for(int j = 0; j<rows; j++){
            cout<<setw(3)<<arrResult[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    
    //del
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            arr[i][j] = random()%10+1;
        }
    }
    
    //del
    for(int i = 0; i<cols; i++){
        delete [] arrResult[i];
    }
    delete [] arrResult;
    
    
    for(int i = 0; i<rows; i++){
        delete [] arr[i];
    }
    delete [] arr;
    
    
    
    
    return 0;
}
