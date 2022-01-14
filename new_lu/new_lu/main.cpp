//
//  main.cpp
//  new_lu
//
//  Created by grafon100 on 05/01/2022.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    
   
    int n = 4;
    double arrU[n][n], arrL[n][n];
    
    double myArr[4][4] = {  { 1,  3,  4,  6},
                            { 2,  3,  4,  5},
                            { 2,  1,  2,  1},
                            {-1,  2, -4,  6}
                        };
    
    double resultArr[4][1] = {  {1 },
                                {-2},
                                {3 },
                                {4 }
    };
    
    double vectY[4][1] = {  {0},
                            {0},
                            {0},
                            {0}
    };

    
    
    
    cout<<"myArr ------------------"<<endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<setw(5)<<myArr[i][j]<<" ";
        }
        cout<<endl;
    }
    
   
    //инициализация матриц L и U
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j){
                arrL[i][j]=1.0;
            }else{
                arrL[i][j]=0.0;
                arrU[i][j]=0.0;
                
            }
        }
    }
    //непосредственно разложение
    for(int k=0;k<n;k++) {
        arrU[k][k]=myArr[k][k];
        cout<<"############################################\n";
        cout<<"U["<<k<<"]["<<k<<"]="<<arrU[k][k]<<" --\n";
        for(int i=k+1;i<n;i++) {
            arrL[i][k]=myArr[i][k]/arrU[k][k];
            arrU[k][i]=myArr[k][i];
            cout<<"L["<<i<<"]["<<k<<"]="<<arrL[i][k]<<"\n";
            cout<<"U["<<k<<"]["<<i<<"]="<<arrU[k][i]<<"\n";
        }
        cout<<"############################################\n";
      
        for(int i=k+1;i<n;i++) {
            for(int j=k+1;j<n;j++){
                cout<<"----------//////////////////////////////----------\n";
                cout<<"M["<<i<<"]["<<j<<"]="<<myArr[i][j]<<" -----\n";
                cout<<"L["<<i<<"]["<<k<<"]="<<arrL[i][k]<<" -----\n";
                cout<<"U["<<k<<"]["<<j<<"]="<<arrU[k][j]<<" -----\n";
                myArr[i][j]=myArr[i][j]-arrL[i][k]*arrU[k][j];
                cout<<"\nresult M["<<i<<"]["<<j<<"]="<<myArr[i][j]<<" =======\n";
            }
        }
    }
    
    cout<<"====================\n";
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<setw(5)<<myArr[i][j]<<" ";
        }
        cout<<endl;
    }
//
//    // A*X = B
//    // (L*U)*X = B
//    // L*(U*X) = B    => U*X = Y
//    // L*Y = B
//    // U*X = Y
//
//
//
//
//
//    for(int i = 0; i<n; i++){
//        int y = 0;
//        for(int j = 0; j<n; j++){
//
//            cout<<resultArr[j][0]<<endl;
//            cout<<arrL[i][j]<<"\n=====================\n";
//            if(arrL[i][j] != 0){
//                if(vectY[i][0] == 0){
//                    y += resultArr[j][0] / arrL[i][j];
//                } else {
//                    y += resultArr[j][0] / arrL[i][j];
//                }
//
//
//            }
//
//        }
//        vectY[i][0] = y;
//    }
//
//

//    cout<<"===========================\n";
//    for(int i = 0; i<4; i++){
//        cout<<vectY[i][0]<<endl;
//    }
//
//    cout<<"===========================\n";




   
    cout.precision(2);
    cout<<"arrL ------------------"<<endl;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<setw(5)<<arrL[i][j]<<" ";
        }
        cout<<endl;
    }
    cout.precision(3);
    cout<<"arrU ------------------"<<endl;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<setw(5)<<arrU[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
   
    
    return 0;
}
