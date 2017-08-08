g++ -o main $(pkg-config --cflags --libs gtkmm-3.0) src/main.cpp -rdynamic -Ofast
