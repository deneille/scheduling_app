g++ appOpener.cpp -c
g++ tasks.cpp -c
g++ testmain.cpp appOpener.o tasks.o 
del *.o
rm -f *.o