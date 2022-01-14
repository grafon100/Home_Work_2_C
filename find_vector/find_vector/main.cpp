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
        for(int i=k+1;i<n;i++) {
            arrL[i][k]=myArr[i][k]/arrU[k][k];
            arrU[k][i]=myArr[k][i];
        }
      
        for(int i=k+1;i<n;i++) {
            for(int j=k+1;j<n;j++){
                myArr[i][j]=myArr[i][j]-arrL[i][k]*arrU[k][j];
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

    for(int k = 0; k<1; k++){
        vectY[k][k]= resultArr[k][k]/arrL[k][k];
        cout<<vectY[k][k]<<endl;
        
        vectY[1][k] = (resultArr[1][0] - arrL[1][1]) / arrL[][];
        cout<<vectY[1][k]<<endl;
        
        vectY[2][k] = (resultArr[2][k] - arrL[1][k]) / arrL[1][k];
        cout<<vectY[1][k]<<endl;
            
        
            
    }
    



    
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
