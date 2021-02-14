#ifndef TASKS_H
#define TASKS_H

#include <filesystem>
#include <chrono>
#include <string>
#define MAX_PATH   260 //in windows max path length is 260 characters but idk where its defined so i made this

using namespace std;
using namespace chrono;


class Task {
  public:
    Task(string, time_t);
    Task(string, time_t, char*, char*);
    Task(string, time_t, char*);

    string getName();
    time_t getSTime();
    char* getProgram();
    char* getFilename();

    void editName(string);
    void editSTime(time_t);
    void editProgram(char*);
    void editFilename(char*);

  private:
    string taskName;
    time_t scheduledTime;
    char program[MAX_PATH];
    char destFile[MAX_PATH]; //this is the file that the program can be executed on
};

#endif