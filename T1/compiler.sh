g++ -o main $(pkg-config --cflags --libs gtkmm-3.0) Main.cpp src/Viewport.cpp src/Menu.cpp src/Interface.cpp src/DisplayFile.cpp src/DObject.cpp src/Window.cpp -rdynamic -Ofast -std=c++11
