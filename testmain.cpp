#include "appOpener.hpp"

int main(){

    char firefox[] = "\"C:\\Program Files\\Mozilla Firefox\\firefox.exe\"";
    char google[] = "google.com";
    char zoom[] = "C:\\Users\\Jarred\\AppData\\Roaming\\Zoom\\bin\\Zoom.exe";


    runProgram(firefox, google);

    runProgram(zoom);

    return 0;
}