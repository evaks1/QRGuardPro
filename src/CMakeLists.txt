add_library(QRGuardPro STATIC DataHarvester.cpp DataHarvester.h MainWindow.cpp MainWindow.h QRCodeGenerator.cpp QRCodeGenerator.h QRCodeScanner.cpp QRCodeScanner.h SafetyEvaluator.cpp SafetyEvaluator.h)
target_include_directories(QRGuardPro PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(QRGuardPro main.cpp)
target_link_libraries(QRGuardPro PRIVATE QRGuardPro Qt6::Widgets Qt6::Network ${OpenCV_LIBS} ${QRENCODE_LIBRARY} ${CURL_LIBRARIES})









