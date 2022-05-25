#!/bin/bash
g++ -lpthread -lmodbus -Wno-format -o p_jhonny main.cpp -Wno-deprecated-declarations -Wno-format-security -lm `pkg-config --cflags --libs gtkmm-3.0` -rdynamic 

