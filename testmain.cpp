#include "appOpener.hpp"
#include "tasks.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

time_t parseTime(string time24);
Task* timeCheck(vector<Task> tdl);


int main(){

    TimePoint_s referenceTime1 = systemClock::now();
    TimePoint referenceTime2 = Clock::now();
    
    char firefox[] = "\"..\\..\\..\\..\\..\\Program Files\\Mozilla Firefox\\firefox.exe\"";
    char google[] = "google.com";
    char zoom[] = "C:\\Users\\new22\\AppData\\Roaming\\Zoom\\bin\\Zoom.exe";

    // Task *openGoogle = new Task("open google", parseTime("22:15"), firefox, google);

    // Task *zoomTask = new Task("zoom lecture !", parseTime("22:15"), zoom);

    runProgram(firefox, google);

    runProgram(zoom);

    time_t timeTest;
    time_t currTime;
    time(&currTime);

    string eleven45 = "23:45";
    cout << "passing " << eleven45 << " \n";
    timeTest = parseTime(eleven45);
    printf("the parsed eleven thirty would be %s", ctime(&timeTest));
    printf("it is currently %s", ctime(&currTime));

    // char MSWord[] = "\"C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE\"";
    // char file[] = "\"D:\\UBC Accessibility.docx\"";


    // runProgram(MSWord, file);

    return 0;
}


Task* timeCheck(vector<Task> tdl){
    bool match = false;
    double seconds; //no guarantee when its checked so i want a 2 minute safety net
    time_t currTime;
    vector<Task>::iterator it;
    do{
        time(&currTime);
        for (it = tdl.begin() ; it != tdl.end(); ++it){
            seconds = difftime(currTime, it->getSTime());
            if(seconds > 0 && seconds < 120){
                match = true;
            }
        }
    }while(!match);
    return &(*it);
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


  

