#!/bin/bash
gcc -Wno-format -o final main.cpp -Wno-deprecated-declarations -Wno-format-security -lm `pkg-config --cflags --libs gtkmm-3.0` -rdynamic

