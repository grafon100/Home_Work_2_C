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


void inputTask(MyDay *&arr,int &count){
    MyDay taskOnDay;
    
    cout<<"Input a Date: ";
    cin>> taskOnDay.date;
    
    //Input line with spaces ---- Super WORK!!! Thanks Indian Man
    cin.ignore();
    cout<<"Input discription your days: ";
    getline(cin,taskOnDay.discrDate);
    //----This is Link: https://youtu.be/AgS9JSzbvtU ------------
    
    cout<<"Input priority this task: ";
    cin>> taskOnDay.prior;
    
    arr[count] = taskOnDay;
    count++;
    
    cout<<"--------------------------------\n";
    cout<<"Task was add successfull!\n";
    cout<<"--------------------------------\n";
}


void addTask(MyDay *&arr, int &count){
    MyDay *newTask = new MyDay[count+1];
    
    for(int i = 0; i<count; i++){
        newTask[i] = arr[i];
    }
    
    delete [] arr;
    
    inputTask(newTask, count);
    
    arr = newTask;
}


void showYourTask(MyDay *arr, const int count){
    cout<<"\tYour days:\n======================\n";
    for(int i = 0; i<count; i++){
        cout<<"Task №: "<<i+1<<"\n-  -  -  -  -  -  -  -  -\n";
        cout<<"Data:     "<<arr[i].date<<endl;
        cout<<"Discribe: "<<arr[i].discrDate<<endl;
        cout<<"Priority: "<<arr[i].prior<<endl;
        cout<<"-----------------------\n";
    }
    cout<<"End List Task\n=========================\n";
}

void deleteAllTask(MyDay *&arr, int &count){
    count = 0;
    MyDay *emptyArr = new MyDay[count+1];
    delete [] arr;
    
    arr = emptyArr;
    
    cout<<"You Task List is EMPTY!"<<endl;
    cout<<"-=o=- -=o=- -=o=- -=o=-"<<endl;
}

void deleteOneTask(MyDay *&arr, int &count, const int numTask){
    if(count != 1){
        count--;
        MyDay *newArr = new MyDay[count];
        for(int i = 0; i<count; i++){
            if(numTask-1 > i){
                newArr[i] = arr[i];
            } else {
                newArr[i] = arr[i+1];
            }
        }

        delete [] arr;

        arr = newArr;
    } else {
        deleteAllTask(arr, count);
    }

}











int main(int argc, const char * argv[]) {
    
    int numDeleteTask;
    int countTask = 0;
    MyDay *arrayTask = new MyDay[countTask+1];
    
    bool repMenu = true;
    while(repMenu){
        if (countTask == 0){
            
            cout<<"You didn't have any Task, please add your first Task!\n";
            cout<<"-----------------------------------------------------\n";
            inputTask(arrayTask, countTask);
        } else {
            int task;
            cout<<"1 -Add task on Day.\n";
            cout<<"2 -Show on Day.\n";
            cout<<"3 -Delete task on Day.\n";
            cout<<"4 -Delete All task.\n";
            cout<<"5 -Quit from app.\n";
            cout<<"-----\n\tChoice your task: ";
            cin>>task;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            
            switch (task) {
                case 1:
                    addTask(arrayTask, countTask);
                    break;
                case 2:
                    showYourTask(arrayTask, countTask);
                    break;
                case 3:
                    showYourTask(arrayTask, countTask);
                    cout<<"Which task did you want delete?: ";
                    cin>>numDeleteTask;
                    deleteOneTask(arrayTask, countTask, numDeleteTask);
                    
                    break;
                    
                case 4:
                    deleteAllTask(arrayTask, countTask);
                    break;
                case 5:
                    repMenu = false;
                    break;
                default:
                    break;
            }
            
            
        }
        
    }
    
    delete [] arrayTask;
    
    return 0;
}
