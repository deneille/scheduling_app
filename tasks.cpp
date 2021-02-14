#include <cstring>
#include "tasks.hpp"

Task::Task(string name, time_t sTime){
    taskName = name;
    scheduledTime = sTime;
}

Task::Task(string name, time_t sTime, char* prog, char* file){
    taskName = name;
    scheduledTime = sTime;
    strcpy(program, prog);
    strcpy(destFile, file);
}

Task::Task(string name, time_t sTime, char* prog){
    taskName = name;
    scheduledTime = sTime;
    strcpy(program, prog);
    strcpy(destFile, "\0");
}


string Task::getName(){
    string name = taskName;
    return name;
}

time_t Task::getSTime(){
    return scheduledTime;
}
char* Task::getProgram(){
    return program;
}
char* Task::getFilename(){
    return destFile;
}

void Task::editName(string name){
    taskName = name;
}
void Task::editSTime(time_t sTime){
    scheduledTime = sTime;
}
void Task::editProgram(char* prog){
    strcpy(program, prog);
}
void Task::editFilename(char* file){
    strcpy(destFile, file);
}
