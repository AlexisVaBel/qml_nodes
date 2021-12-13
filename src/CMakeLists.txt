option(CPP_STARTER_USE_QT "Enable compilation of QT sample" OFF)


# Generic test that uses conan libs
add_executable(qml_nodes main.cpp)
target_link_libraries(
  intro
  PRIVATE project_options
          project_warnings
          CONAN_PKG::docopt.cpp
          CONAN_PKG::fmt
          CONAN_PKG::spdlog)
