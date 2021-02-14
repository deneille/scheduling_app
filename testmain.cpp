#include "appOpener.hpp"
#include "tasks.hpp"
#include <stdio.h>
#include <vector>
#include <chrono>
#include <string>

time_t parseTime(std::string time24, TimePoint_s ref1, TimePoint ref2);
Task* timeCheck(std::vector<Task> tdl);


int main(){

    TimePoint_s referenceTime1 = systemClock::now();
    TimePoint referenceTime2 = Clock::now();
    
    char firefox[] = "\"C:\\Program Files\\Mozilla Firefox\\firefox.exe\"";
    char google[] = "google.com";
    // char zoom[] = "..\\AppData\\Roaming\\Zoom\\bin\\Zoom.exe";
    char zoom[] = "C:\\Users\\new22\\AppData\\Roaming\\Zoom\\bin\\Zoom.exe";

    Task *openGoogle = new Task("open google", parseTime("22:15", referenceTime1, referenceTime2), firefox, google);

    Task *zoomTask = new Task("zoom lecture !", parseTime("22:15", referenceTime1, referenceTime2), zoom);

    runProgram(firefox, google);

    runProgram(zoom);

    time_t currTime;

    time(&currTime);
    printf("the current date/time is %s", ctime(&currTime));

    char MSWord[] = "\"C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE\"";
    char file[] = "\"D:\\UBC Accessibility.docx\"";


    runProgram(MSWord, file);

    return 0;
}


Task* timeCheck(std::vector<Task> tdl){
    bool match = false;
    double seconds; //no guarantee when its checked so i want a 2 minute safety net
    time_t currTime;
    std::vector<Task>::iterator it;
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

time_t parseTime(std::string time24, TimePoint_s ref1, TimePoint ref2){
    size_t idx = 0;
    Clock::duration hours = std::chrono::hours(stoi(time24, &idx, 10));
    Clock::duration mins = std::chrono::minutes(stoi(time24, &idx, 10));
    Clock::duration secs = std::chrono::duration_cast<std::chrono::seconds>(hours) + std::chrono::duration_cast<std::chrono::seconds>(mins);
    TimePoint desiredTime(secs);
    return  systemClock::to_time_t(systemClock::now() + std::chrono::duration_cast<systemClock::duration>(desiredTime - Clock::now()));;;
}