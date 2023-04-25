cmake_minimum_required(VERSION 3.14)

project(bv_reports LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_SOURCE_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_SOURCE_DIR}/conan.cmake")
endif()
configure_file("${CMAKE_SOURCE_DIR}/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake" COPYONLY)
include("${CMAKE_BINARY_DIR}/conan.cmake")

conan_cmake_run(CONANFILE conanfile.py BASIC_SETUP CMAKE_TARGETS)

set(CMAKE_PREFIX_PATH "/opt/Qt5.12.12/5.12.12/gcc_64/lib/cmake/Qt5")
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

set(PROJECT_SOURCES
        resources/qml.qrc
        application/main.cpp
        application/GraphicId.cpp
        application/GraphicId.hpp
        application/HeaderBarModel.cpp
        application/HeaderBarModel.hpp
        common/Constants.cpp
        common/Constants.hpp
        common/ViewModelDependencies.cpp
        common/ViewModelDependencies.hpp
        common/BaseViewModel.cpp
        common/BaseViewModel.hpp
        mainWindow/MainWindowViewModel.cpp
        mainWindow/MainWindowViewModel.hpp
        userSettings/UserSettingsItem.hpp
        userSettings/UserSettingsItemModel.cpp
        userSettings/UserSettingsItemModel.hpp
        userSettings/UserSettingsContext.cpp
        userSettings/UserSettingsContext.hpp
        userSettings/UserSettingsViewModel.cpp
        userSettings/UserSettingsViewModel.hpp
        firstUse/FirstUseViewModel.cpp
        firstUse/FirstUseViewModel.hpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(bv_reports
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET bv_reports APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(bv_reports SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(bv_reports
          ${PROJECT_SOURCES}
        )
    endif()
endif()

target_compile_definitions(bv_reports
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(bv_reports
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)
target_link_libraries(bv_reports PRIVATE CONAN_PKG::nlohmann_json)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(bv_reports)
    qt_finalize_executable(bv_reports)
endif()
