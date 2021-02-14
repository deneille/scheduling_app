#ifndef TASKS_H
#define TASKS_H

#include <filesystem>
#include <ctime>
#include <string>
#define MAX_PATH   260 //in windows max path length is 260 characters but idk where its defined so i made this


class Task {
  public:
    Task(std::string, time_t);
    Task(std::string, time_t, char*, char*);

    std::string getName();
    time_t getSTime();
    char* getProgram();
    char* getFilename();

    void editName(std::string);
    void editSTime(time_t);
    void editProgram(char*);
    void editFilename(char*);

  private:
    std::string taskName;
    time_t scheduledTime;
    char program[MAX_PATH];
    char destFile[MAX_PATH]; //this is the file that the program can be executed on
};

#endif