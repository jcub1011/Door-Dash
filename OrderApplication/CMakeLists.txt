cmake_minimum_required(VERSION 3.19)
project(OrderApplication)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(OrderApplication main.cpp Models/Item.h Models/Order.h Models/OrderApp.h Models/CommonFunc.h Models/Checkout.h)