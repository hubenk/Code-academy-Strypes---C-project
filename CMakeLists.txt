add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Warcraft)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/StarCraft)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/CounterStrike)

cmake_minimum_required(VERSION 3.16)
project(Final_projects)

set(_WARCRAFT_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Warcraft/src)
set(_STARCRAFT_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/StarCraft/src)
set(_CS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/CounterStrike/src)

set(_WARCRAFT_HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Warcraft/include)
set(_STARCRAFT_HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/StarCraft/include)
set(_CS_HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/CounterStrike/include)

add_executable(
	${PROJECT_NAME}

	${_WARCRAFT_SRC_DIR}/main.c
	${_WARCRAFT_SRC_DIR}/Hero.c
	${_WARCRAFT_SRC_DIR}/SpellCast.c

	${_CS_SRC_DIR}/main.c
	${_CS_SRC_DIR}/BattleField.c

	${_STARCRAFT_SRC_DIR}/main.c
	${_STARCRAFT_SRC_DIR}/BattleField.c
	${_STARCRAFT_SRC_DIR}/Vector.c
	${_STARCRAFT_SRC_DIR}/ProtossCarrier.c
	${_STARCRAFT_SRC_DIR}/ProtossPhoenix.c
	${_STARCRAFT_SRC_DIR}/TerranViking.c
	${_STARCRAFT_SRC_DIR}/TerranBCruiser.c
	${_STARCRAFT_SRC_DIR}/Ships.c
)


target_include_directories(
			${PROJECT_NAME} 
			PRIVATE
			${PROJECT_SOURCE_DIR}/Warcraft/include
			${PROJECT_SOURCE_DIR}/StarCraft/include
			${PROJECT_SOURCE_DIR}/CounterStrike/include)