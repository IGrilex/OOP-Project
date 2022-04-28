cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_BUILD_TYPE Debug)

project(OOP-Project)

add_executable(executable Games.cpp Games.h main.cpp Player.h Player.cpp Random.h Random.cpp Settings.h Supervisor.cpp Supervisor.h User.cpp User.h)
