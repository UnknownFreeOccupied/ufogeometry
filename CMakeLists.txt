cmake_minimum_required(VERSION 3.5...3.16)

project(ufogeometry
	VERSION 2.0.0
	DESCRIPTION "The UFO geometry library"
	LANGUAGES CXX
)

Include(FetchContent)

FetchContent_Declare(
  ufomath
  GIT_REPOSITORY https://github.com/UnknownFreeOccupied/ufomath
  GIT_TAG        main
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(ufomath)

add_library(ufogeometry INTERFACE)
add_library(UFO::Geometry ALIAS ufogeometry)

set_target_properties(ufogeometry PROPERTIES
	VERSION ${PROJECT_VERSION}
	SOVERSION ${PROJECT_VERSION_MAJOR}
	CXX_STANDARD 17
	CXX_EXTENSIONS OFF
)

target_link_libraries(ufogeometry INTERFACE UFO::Math)

target_include_directories(ufogeometry INTERFACE
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

target_compile_features(ufogeometry INTERFACE cxx_std_17)

include(GNUInstallDirs)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Only enable tests when we're the root project
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  add_subdirectory(tests)
endif()

install(TARGETS ufogeometry
	EXPORT ufogeometryTargets
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(EXPORT ufogeometryTargets
	FILE "ufogeometryTargets.cmake"
	NAMESPACE UFO::
	DESTINATION lib/cmake/${PROJECT_NAME}
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
	"${PROJECT_SOURCE_DIR}/cmake/ufogeometryConfig.cmake.in"
	"${CMAKE_CURRENT_BINARY_DIR}/ufogeometryConfig.cmake"
	INSTALL_DESTINATION lib/cmake/${PROJECT_NAME}
)

write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/ufogeometryConfigVersion.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion
)

INSTALL(
	FILES
	"${CMAKE_CURRENT_BINARY_DIR}/ufogeometryConfig.cmake"
	"${CMAKE_CURRENT_BINARY_DIR}/ufogeometryConfigVersion.cmake"
	DESTINATION lib/cmake/${PROJECT_NAME}
)

install(
	DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION include
)