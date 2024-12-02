# Enable testing
enable_testing()


# Include FetchContent for GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add test executable for QRCodeScanner
add_executable(test_QRCodeScanner
    test_QRCodeScanner.cpp
    ${CMAKE_SOURCE_DIR}/src/QRCodeScanner.cpp
)

# Add test executable for QRCodeGenerator
add_executable(test_QRCodeGenerator
    test_QRCodeGenerator.cpp
    ${CMAKE_SOURCE_DIR}/src/QRCodeGenerator.cpp
)

# Include directories
target_include_directories(test_QRCodeScanner PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)
target_include_directories(test_QRCodeGenerator PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

# Link libraries
target_link_libraries(test_QRCodeScanner PRIVATE
    GTest::gtest
    GTest::gtest_main
    Qt6::Widgets
    Qt6::Network
    ${OpenCV_LIBS}
)

target_link_libraries(test_QRCodeGenerator PRIVATE
    GTest::gtest
    GTest::gtest_main
    Qt6::Widgets
    Qt6::Network
    ${OpenCV_LIBS}
    ${QRENCODE_LIBRARY}
)

# Include GoogleTest CMake functions
include(GoogleTest)

# Discover and register tests with CTest
gtest_discover_tests(test_QRCodeScanner)
gtest_discover_tests(test_QRCodeGenerator)
