cmake_minimum_required(VERSION 2.8)
project(calculator)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)


set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "GviDream")
set(CPACK_PACKAGE_CONTACT "xtrant02@stud.fit.vutbr.cz")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A Calculator by GviDream.")
set(CPACK_PACKAGE_VERSION "1.0")


set(CPACK_GENERATOR DEB)
install(DIRECTORY deployment/ DESTINATION /opt/${PROJECT_NAME})
install(FILES linux/${PROJECT_NAME}.desktop DESTINATION share/applications)
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/linux/postinst;")

include(CPack)
