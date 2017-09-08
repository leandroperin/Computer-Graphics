reset
g++ -o main $(pkg-config --cflags --libs gtkmm-3.0) Main.cpp src/*.cpp -rdynamic -Ofast -std=c++11
