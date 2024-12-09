cmake_minimum_required(VERSION 3.10)

project(QtOpenCV)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 11)



find_package(Qt6 REQUIRED COMPONENTS Widgets)

find_package(OpenCV REQUIRED)

add_executable(QtOpenCV main.cpp   MainWindow.ui MainWindow.cpp)


target_link_libraries(QtOpenCV Qt6::Widgets ${OpenCV_LIBS})

