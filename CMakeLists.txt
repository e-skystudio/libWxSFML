cmake_minimum_required(VERSION 3.23)
project(WxSFML)

set(CMAKE_CXX_STANDARD 23)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(wxWidgets CONFIG REQUIRED)


add_library(WxSFML STATIC src/wxSFMLCanvas.cpp)
target_link_libraries(WxSFML PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
target_link_libraries(WxSFML PRIVATE wx::core wx::base)