cmake_minimum_required(VERSION 3.17)
project(LINAL_Eindopdracht)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(RUN_TESTS FALSE) # Enable or disable tests

list(APPEND CMAKE_PREFIX_PATH "external/SDL2")
list(APPEND CMAKE_PREFIX_PATH "external/SDL2_image")
list(APPEND CMAKE_PREFIX_PATH "external/SDL2_ttf")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

if(RUN_TESTS)
    Include(FetchContent)
    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG        v2.13.1)

    FetchContent_MakeAvailable(Catch2)

    set(CATCH2_LIBRARIES Catch2::Catch2)
endif()

add_executable(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
        "${SDL2_INCLUDE_DIRS}"
        "${SDL2_IMAGE_INCLUDE_DIRS}"
        "${SDL2_TTF_INCLUDE_DIRS}"
        )
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${CATCH2_LIBRARIES})

include("${CMAKE_CURRENT_SOURCE_DIR}/src/CMakeLists.txt")

if(RUN_TESTS)
    include("${CMAKE_CURRENT_SOURCE_DIR}/src/tests/CMakeLists.txt")
endif()

if(WIN32)
    list(GET SDL2_LIBRARIES 0 HEAD_SDL2_LIBRARIES)
    get_filename_component(SDL2_DLL_DIR ${HEAD_SDL2_LIBRARIES} DIRECTORY CACHE)
    file(GLOB SDL2_DLLS "${SDL2_DLL_DIR}/*.dll")

    list(GET SDL2_IMAGE_LIBRARIES 0 HEAD_SDL2_IMAGE_LIBRARIES)
    get_filename_component(SDL2_IMAGE_DLL_DIR ${HEAD_SDL2_IMAGE_LIBRARIES} DIRECTORY CACHE)
    file(GLOB SDL2_IMAGE_DLLS "${SDL2_IMAGE_DLL_DIR}/*.dll")

    list(GET SDL2_TTF_LIBRARIES 0 HEAD_SDL2_TTF_LIBRARIES)
    get_filename_component(SDL2_TTF_DLL_DIR ${HEAD_SDL2_TTF_LIBRARIES} DIRECTORY CACHE)
    file(GLOB SDL2_TTF_DLLS "${SDL2_TTF_DLL_DIR}/*.dll")

    add_custom_target(dependencies ALL
            COMMAND ${CMAKE_COMMAND} -E copy

            ${SDL2_DLLS}
            ${SDL2_IMAGE_DLLS}
            ${SDL2_TTF_DLLS}

            ${CMAKE_BINARY_DIR}
            )

    add_dependencies(${PROJECT_NAME} dependencies)
endif()

add_custom_target(assets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/assets"
        "${CMAKE_BINARY_DIR}/assets")
