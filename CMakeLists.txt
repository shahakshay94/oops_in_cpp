cmake_minimum_required(VERSION 3.10)
project(a4)

set(CMAKE_CXX_STANDARD 11)

add_executable(a4 ShapeTestDriver.cpp Canvas.cpp Oblique.cpp Rectangle.cpp
        Rhombus.cpp RightAngle.cpp Shape.cpp Triangle.cpp

        Canvas.h Oblique.h Rectangle.h
        Rhombus.h RightAngle.h Shape.h Triangle.h)