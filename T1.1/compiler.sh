g++ -o main $(pkg-config --cflags --libs gtkmm-3.0) src/main.cpp src/Menu.cpp src/Interface.cpp src/DrawingArea.cpp src/displayFile.cpp src/Object.cpp src/Window.cpp -rdynamic -Ofast -std=c++11
