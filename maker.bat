g++ -g -c *.cpp
move *.o src
cd src
g++ -c *.cpp
g++ -o Deader_than_Dead.exe *.o -lmingw32 -lSDLmain -lSDL -lSDL_image -lSDL_ttf
del *.o
move Deader_than_Dead.exe ..
cd ..