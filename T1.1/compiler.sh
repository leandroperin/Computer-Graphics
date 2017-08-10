g++ -o main $(pkg-config --cflags --libs gtkmm-3.0) Main.cpp src/Menu.cpp src/Interface.cpp src/DrawingArea.cpp src/DisplayFile.cpp src/Object.cpp src/Window.cpp -rdynamic -Ofast -std=c++11
