cmake_minimum_required(VERSION 3.16)

project(StarCraft)

set(_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(
        ${PROJECT_NAME}

        ${_SRC_DIR}/main.c
        ${_SRC_DIR}/BattleField.c
        ${_SRC_DIR}/Vector.c
        ${_SRC_DIR}/ProtossCarrier.c
        ${_SRC_DIR}/ProtossPhoenix.c
        ${_SRC_DIR}/TerranViking.c
        ${_SRC_DIR}/TerranBCruiser.c
        ${_SRC_DIR}/Ships.c
        src/Game.c include/Game.h)


target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

function(set_target_c_standard target standard)
    set_target_properties(
            ${CMAKE_C_COMPILER_TARGET}
            PROPERTIES
            C_STANDARD ${standard}
            C_STANDARD_REQUIRED YES
            C_EXTENSIONS NO
    )
endfunction()

set_target_c_standard(${PROJECT_NAME} 11)

function(enable_target_c_warnings target)
    target_compile_options(
            ${target}
            PRIVATE
            -Wall
            -Wextra
            -Werror
            -Wundef
            -Wuninitialized
            -Wshadow
            -Wpointer-arith
            -Wcast-align
            -Wcast-qual
            -Wunused-parameter
            -Wdouble-promotion
            -Wnull-dereference
    )
endfunction()

enable_target_c_warnings(${PROJECT_NAME})