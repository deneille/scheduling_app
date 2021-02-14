#include "tasks.hpp"

Task::Task(std::string name, time_t sTime){
    taskName = name;
    scheduledTime = sTime;
}

Task::Task(std::string name, time_t sTime, char* prog, char* file){
    taskName = name;
    scheduledTime = sTime;
    strcpy(program, prog);
    strcpy(destFile, file);
}


std::string Task::getName(){
    std::string name = taskName;
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

void Task::editName(std::string name){
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
