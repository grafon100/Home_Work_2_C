//
//  main.cpp
//  Home_Work_3
//
//  Created by grafon100 on 07/12/2021.
//


#include <iostream>
#include <string>



using namespace std;

struct MyDay{
    string date;
    string discrDate;
    int prior;
};


MyDay * taskArray;

MyDay * newTaskArray;

//------------
MyDay *arr;
//------------
MyDay *createNewTaskArray(MyDay *oldArr,int size){
    MyDay *newArr = new MyDay [size+1];
    for(int i = 0; i<size; i++)
        newArr[i] = oldArr[i];
    delete []oldArr;
    return newArr;
}

MyDay *creatFirstTaskArray(int size){
    MyDay *arr = new MyDay [size];
    return arr;
}

void filArr(MyDay *arrFill, int *size){
    int id = *size;
    cout<<"-----------------------\n";
    cout<<"Input day <dd.mm.yyyy> ";
    cin>>taskArray[id-1].date;
    
    fflush(stdin);
    cout<<"Input discrabe your day: ";
    getline(cin, taskArray[id-1].discrDate);
    
    cout<<"Input priotitet (0-9): ";
    cin>>taskArray[id-1].prior;
    cout<<"Task Add\n";
    
    *size += 1;
}









int main(int argc, const char * argv[]) {
    
    int *id = new int;
    *id = 1;
    
   
    
    taskArray = creatFirstTaskArray(*id);
    
    bool repMenu = true;
    
    while(repMenu){
        
        int task;
        cout<<"1 -Add task on Day.\n";
        cout<<"2 -Show on Day.\n";
        cout<<"3 -Delete task on Day.\n";
        cout<<"4 -Delete All task.\n";
        cout<<"5 -Quit from app.\n";
        cout<<"----- Choice your task: ";
        cin>>task;
        
        switch (task) {
            case 1:
                filArr(taskArray, id);
                
                
//                cout<<"-----------------------\n";
//                cout<<"Input day <dd.mm.yyyy> ";
//                cin>>taskArray[*id-1].date;
//
//                fflush(stdin);
//                cout<<"Input discrabe your day: ";
//                getline(cin, taskArray[*id-1].discrDate);
//
//                cout<<"Input priotitet (0-9): ";
//                cin>>taskArray[*id-1].prior;
//                cout<<"Task Add\n";
                
                break;
            case 2:
                cout<<*id;
                for(int i = 0; i<1; i++){
                    cout<<"==================================\n";
                    cout<<i+1<<endl;
                    cout<<"data: "<<taskArray[i].date<<endl;
                    cout<<"task: "<<taskArray[i].discrDate<<endl;
                    cout<<"priorite: "<<taskArray[i].prior<<endl;
                    cout<<"==================================\n";
                }
                break;
            case 3:
                
                break;
            case 5:
                repMenu = false;
                break;
            default:
                break;
        }
        
        
    }
    //-----------------
    delete [] arr;
    //-----------------
    delete [] taskArray;
    delete [] newTaskArray;
    return 0;
}
