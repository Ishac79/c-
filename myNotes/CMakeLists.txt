cmake_minimum_required(VERSION 3.10)

project(myNotes)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCES
    main.cpp
    HighlightAnnotationWidget.cpp
    AnnotationDialog.cpp
)

set(HEADERS
    HighlightAnnotationWidget.h
    AnnotationDialog.h
)

add_executable(myNotes ${SOURCES} ${HEADERS})

qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

target_sources(myNotes PRIVATE ${MOC_SOURCES})

target_link_libraries(myNotes Qt5::Widgets)
