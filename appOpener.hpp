#ifndef APPOPNER_H
#define APPOPENER_H


/**
 * @brief runs an application when given the filepath to the .exe
 *        with an additional parameter which goes into the application call
 *        example: runProgram("C:\Program Files\Google Chrome\chrome.exe", "google.com");
 * 
 * @return int: error code. 1 if failed and 0 on success. 
 */
int runProgram(char*, char*);

/**
 * @brief runs an application when given the filepath to the .exe
 * 
 * @return int: error code. 1 if failed and 0 on success. 
 */
int runProgram(char*);


#endif