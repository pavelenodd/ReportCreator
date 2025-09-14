

cmake_minimum_required(VERSION 4.0)

set(PROJECT_NAME ReportCreatorApp)

string(LENGTH ${PROJECT_NAME} PROJECT_NAME_LENGTH)
math(EXPR MODULE_NAME_LENGTH "${PROJECT_NAME_LENGTH} - 3")
string(SUBSTRING ${PROJECT_NAME} 0 ${MODULE_NAME_LENGTH} MODULE_NAME)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 
set(QT_QML_GENERATE_QMLLS_INI ON)
set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/qml)

# Авто-MOC/UIC/RCC 
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Qml QuickControls2)

# Политика Qt — убрать нудный warning про политику сборки
qt_policy(SET QTP0001 NEW)

# ------------------- Исполняемый файл приложения ---------------------------------
qt_add_executable(${PROJECT_NAME}
    Src/main.cpp           
)

# ------------------- QML-модуль приложения ---------------------------------------
qt_add_qml_module(${PROJECT_NAME}
    URI ${MODULE_NAME}  # например "ReportCreator"
    VERSION 1.0         # версия модуля
    QML_FILES
        Main.qml        
)

# Линковка Qt модулей
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt6::Quick
        Qt6::Qml
        Qt6::QuickControls2
)
