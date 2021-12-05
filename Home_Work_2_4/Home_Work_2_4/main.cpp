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
    
    //fil
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            arr[i][j] = random()%10+1;
        }
    }
    
    
    //print
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            cout<<setw(3)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    
    //del
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            arr[i][j] = random()%10+1;
        }
    }
    
    
    for(int i = 0; i<rows; i++){
        delete [] arr[i];
    }
    delete [] arr;
    
    
    
    
    return 0;
}
