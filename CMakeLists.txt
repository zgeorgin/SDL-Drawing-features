cmake_minimum_required(VERSION 3.10)

project(DrawingFeaturesLib VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.h)

add_library(DrawingFeatures SHARED ${SOURCES})

target_include_directories(DrawingFeatures
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

find_package(SDL2 REQUIRED)
target_include_directories(DrawingFeatures PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(DrawingFeatures PRIVATE ${SDL2_LIBRARIES})

install(TARGETS DrawingFeatures
    EXPORT DrawingFeaturesTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include/
)

install(DIRECTORY include/
    DESTINATION include/
    FILES_MATCHING PATTERN "*.h"
)

install(EXPORT DrawingFeaturesTargets
    FILE DrawingFeaturesConfig.cmake
    NAMESPACE DrawingFeatures::
    DESTINATION lib/cmake/DrawingFeatures
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    "DrawingFeaturesConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/DrawingFeaturesConfig.cmake"
    INSTALL_DESTINATION "lib/cmake/DrawingFeatures"
)

# Установите конфигурационный файл
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/DrawingFeaturesConfig.cmake"
    DESTINATION "lib/cmake/DrawingFeatures"
)

# Вы создаете шаблон конфигурационного файла
file(WRITE "${CMAKE_CURRENT_SOURCE_DIR}/DrawingFeaturesConfig.cmake.in" "
set(DrawingFeatures_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/include\")
")