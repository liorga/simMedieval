cmake_minimum_required(VERSION 3.16)
project(ex3_simMedieval)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex3_simMedieval main.cpp Point.cpp Point.h SimObject.cpp SimObject.h Agent.cpp Agent.h Peasant.cpp Peasant.h Thug.cpp Thug.h Knight.cpp Knight.h Structure.cpp Structure.h Farm.cpp Farm.h Castle.cpp Castle.h Model.cpp Model.h View.cpp View.h AgentFactory.cpp AgentFactory.h Controller.cpp Controller.h InputHandler.cpp InputHandler.h)