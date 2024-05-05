cmake_minimum_required(VERSION 3.10)

project(PencilDraw)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCES
    main.cpp
    PencilDrawWidget.cpp
)

set(HEADERS
    PencilDrawWidget.h
)

# Generate moc files
qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

add_executable(PencilDraw ${SOURCES} ${MOC_SOURCES})

target_link_libraries(PencilDraw Qt5::Widgets)
