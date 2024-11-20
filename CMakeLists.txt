# CMakeLists.txt
cmake_minimum_required(VERSION 3.14)

# Project Name and Version
project(QRGuardPro VERSION 1.0 LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Automatic MOC, UIC, and RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Specify Qt6 installation path if necessary
# set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt@6/lib/cmake") # Uncomment and set if Qt6 is installed in a non-standard path

# Find Qt6 Components (Add Network here)
find_package(Qt6 COMPONENTS Widgets Network REQUIRED)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Find libqrencode
find_library(QRENCODE_LIBRARY qrencode)

if(NOT QRENCODE_LIBRARY)
    message(FATAL_ERROR "libqrencode not found. Please install it using Homebrew: brew install qrencode")
endif()

# Find CURL
find_package(CURL REQUIRED)

if(NOT CURL_FOUND)
    message(FATAL_ERROR "CURL not found. Please install it using Homebrew: brew install curl")
endif()

# Include Directories (Qt provides include directories via targets, so no need to manually include Qt includes)
include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${CURL_INCLUDE_DIRS}
)

# Add Qt Resources
qt6_add_resources(QRGuardPro_RESOURCES rgguardpro.qrc)

# Source Files
set(SOURCES
    main.cpp
    MainWindow.cpp
    QRCodeScanner.cpp
    QRCodeGenerator.cpp
    DataHarvester.cpp
    SafetyEvaluator.cpp
)

set(HEADERS
    MainWindow.h
    QRCodeScanner.h
    QRCodeGenerator.h
    DataHarvester.h
    SafetyEvaluator.h
)

# Add Executable
add_executable(QRGuardPro
    ${SOURCES}
    ${HEADERS}
    ${QRGuardPro_RESOURCES}
)

# Link Libraries (Add Qt6::Network here)
target_link_libraries(QRGuardPro PRIVATE
    Qt6::Widgets
    Qt6::Network    # Added Network module
    ${OpenCV_LIBS}
    ${QRENCODE_LIBRARY}
    ${CURL_LIBRARIES}
)


# Doxygen
find_package(Doxygen REQUIRED)

set(DOXYGEN_IN ${CMAKE_SOURCE_DIR}/docs/Doxyfile.in)
set(DOXYGEN_OUT ${CMAKE_BINARY_DIR}/Doxyfile)

configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

add_custom_target(
    Doxygen ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Generating Doxygen documentation"
    VERBATIM
)

# Sphinx
find_program(SPHINX_BUILD sphinx-build REQUIRED)

set(SPHINX_SOURCE ${CMAKE_SOURCE_DIR}/docs/source)
set(SPHINX_BUILD_DIR ${CMAKE_BINARY_DIR}/docs/sphinx)

add_custom_target(
    Sphinx ALL
    COMMAND ${SPHINX_BUILD} -b html ${SPHINX_SOURCE} ${SPHINX_BUILD_DIR}
    COMMENT "Generating Sphinx documentation"
    VERBATIM
)