set(SOURCES)
set(HEADERS)
set(UIS)

set(CLIENT_MODULES ui)

foreach(X ${CLIENT_MODULES})
	file(GLOB ${X}_SOURCES "${X}/*.cpp")
	file(GLOB ${X}_HEADERS "${X}/*.h")
	file(GLOB ${X}_UIS "${X}/*.ui")
	qt5_wrap_ui(${X}_UIS_H ${${X}_UIS})
	list(APPEND SOURCES ${${X}_SOURCES})
	list(APPEND HEADERS ${${X}_HEADERS})
	list(APPEND UIS ${${X}_UIS})
	add_module("${CMAKE_CURRENT_SOURCE_DIR}/${X}")
endforeach()

find_package(Qt5Multimedia)
find_package(Qt5MultimediaWidgets)
configure_file(Deploy.in.h Deploy.h)

add_library(client STATIC ${SOURCES} ${HEADERS} ${UIS})
target_include_directories(client PRIVATE "${PROJECT_BINARY_DIR}")
target_include_directories(client PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")
target_link_libraries(client PUBLIC Qt5::Core Qt5::Widgets Qt5::Svg Qt5::Multimedia Qt5::MultimediaWidgets)
target_link_libraries(client PUBLIC core server)

add_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME}
		PRIVATE project_options
		PUBLIC client server
		project_warnings
		CONAN_PKG::docopt.cpp
		CONAN_PKG::fmt
		CONAN_PKG::spdlog)
target_link_options(${APP_NAME} PUBLIC "-Wl,--disable-new-dtags")
target_link_options(${APP_NAME} PUBLIC "-Wl,-z,origin")

