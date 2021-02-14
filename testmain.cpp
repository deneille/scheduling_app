#include "appOpener.hpp"
#include "tasks.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <thread>


using namespace std;
using namespace chrono;

time_t parseTime(string time24);
int timeCheck(vector<Task*> tdl);
void executeLoop(vector<Task*>);


int main(){

    vector<Task*> todo = vector<Task*>();
    

    char firefox[] = "\"..\\..\\..\\..\\..\\Program Files\\Mozilla Firefox\\firefox.exe\"";
    char google[] = "google.com";
    char zoom[] = "C:\\Users\\Jarred\\AppData\\Roaming\\Zoom\\bin\\Zoom.exe";

    Task *openGoogle = new Task("open google", parseTime("03:01"), firefox, google);
    todo.push_back(openGoogle);
    Task *zoomTask = new Task("zoom lecture !", parseTime("03:00"), zoom);
    todo.push_back(zoomTask);

    thread timeMonitorThread(executeLoop, todo);

    this_thread::sleep_for (std::chrono::minutes(5));

    return 0;
}

void executeLoop(vector<Task*> todo){
    int index;
    while(!todo.empty()){
    index = timeCheck(todo);
    runProgram(todo[index]->getProgram(), todo[index]->getFilename());
    todo.erase(todo.begin()+index);
    }
}

int timeCheck(vector<Task*> tdl){
    bool match = false;
    double seconds; //no guarantee when its checked so i want a 2 minute safety net
    time_t currTime;
    int i;
    time_t stime;
    do{
        time(&currTime);
        for (i = 0; i != tdl.size() && !match; i++){
            seconds = difftime(currTime, tdl[i]->getSTime());
            if(seconds > 0 && seconds < 120){
                match = true;
                return i;
            }
        }
    }while(1);

}

time_t parseTime(string time24){
    size_t idx = 0;
    int hrs = stoi(time24, &idx, 10);
    idx = 3;
    int mins = stoi(time24.substr(idx) , &idx, 10);
    time_t now;

    time(&now);
    struct tm* tm = localtime(&now);
    tm->tm_hour += hrs - tm->tm_hour;
    tm->tm_min += mins - tm->tm_min;
    tm->tm_sec = 0;
    return mktime(tm);
}


  

