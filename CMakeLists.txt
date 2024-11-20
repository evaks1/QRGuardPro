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

# Optionally, specify include directories for third-party libraries
# include_directories(/path/to/thirdparty/include)
# target_link_libraries(QRGuardPro PRIVATE /path/to/thirdparty/lib)
