#include "appOpener.hpp"
#include "tasks.hpp"
#include <stdio.h>
#include <vector>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

time_t parseTime(string time24, TimePoint_s ref1, TimePoint ref2);
Task* timeCheck(vector<Task> tdl);


int main(){

    TimePoint_s referenceTime1 = systemClock::now();
    TimePoint referenceTime2 = Clock::now();
    
    char firefox[] = "\"C:\\Program Files\\Mozilla Firefox\\firefox.exe\"";
    char google[] = "google.com";
    char zoom[] = "C:\\Users\\Jarred\\AppData\\Roaming\\Zoom\\bin\\Zoom.exe";

    Task *openGoogle = new Task("open google", parseTime("22:15", referenceTime1, referenceTime2), firefox, google);

    Task *zoomTask = new Task("zoom lecture !", parseTime("22:15", referenceTime1, referenceTime2), zoom);

    runProgram(firefox, google);

    runProgram(zoom);

    time_t ten;
    time_t currTime;
    time(&currTime);
    
    ten = parseTime("23:00", referenceTime1, referenceTime2);
    printf("the parsed eleven o'clock would be %s", ctime(&ten));
    printf("it is currently %s", ctime(&currTime));

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

time_t parseTime(string time24, TimePoint_s ref1, TimePoint ref2){
    size_t idx = 0;
    Clock::duration hrs = hours(stoi(time24, &idx, 10));
    Clock::duration mins = minutes(stoi(time24, &idx, 10));
    Clock::duration secs = duration_cast<seconds>(hrs) + duration_cast<seconds>(mins);
    TimePoint desiredTime(secs);
    return  systemClock::to_time_t(systemClock::now() + duration_cast<systemClock::duration>(desiredTime - Clock::now()));;;
}