cmake_minimum_required(VERSION 3.19)
project(BankappQt LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(BankappQt
    WIN32 MACOSX_BUNDLE
    main.cpp



    ../bank_app/BankBrain.h
    BankBrain.cpp
    mainwindow.h BankBrain.h mainwindow.cpp
    mainwindow.ui










)


target_link_libraries(BankappQt
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS BankappQt
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET BankappQt
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
