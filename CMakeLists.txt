cmake_minimum_required(VERSION 3.10)

# Projektname festlegen
project(SDL2Game)

# C++ Standard auf 11 setzen
set(CMAKE_CXX_STANDARD 11)

# SDL2 Konfiguration
set(SDL2_DIR "third_party/SDL2-2.30.1")

# ImGui Konfiguration
set(IMGUI_DIR "third_party/imgui")

# Include-Verzeichnisse hinzufügen
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/Engine/include
    ${PROJECT_SOURCE_DIR}/Engine/Core/include
    "third_party/SDL2-2.30.1/include"
    "third_party/imgui"
)

# Quelldateien festlegen
file(GLOB SOURCES "src/*.cpp")
file(GLOB ENGINE_SOURCES "Engine/src/*.cpp")
file(GLOB CORE_ENGINE_SOURCES "Engine/Core/src/*.cpp")
file(GLOB IMGUI_SOURCES "third_party/imgui/*.cpp")

# Timer-Dateien hinzufügen
set(TIMER_SOURCES "Engine/src/Timer.cpp")

# Assets kopieren
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Ausführbare Datei erstellen
add_executable(${PROJECT_NAME} ${SOURCES} ${ENGINE_SOURCES} ${CORE_ENGINE_SOURCES} ${IMGUI_SOURCES} ${TIMER_SOURCES})

# Verknüpfen der SDL2-Bibliotheken
target_link_libraries(${PROJECT_NAME} 
    "${PROJECT_SOURCE_DIR}/third_party/SDL2-2.30.1/lib/x64/SDL2.lib"
    "${PROJECT_SOURCE_DIR}/third_party/SDL2-2.30.1/lib/x64/SDL2main.lib"
    "${PROJECT_SOURCE_DIR}/third_party/SDL2-2.30.1/lib/x64/SDL2_mixer.lib"
    "${PROJECT_SOURCE_DIR}/third_party/SDL2-2.30.1/lib/x64/SDL2_ttf.lib"
    "${PROJECT_SOURCE_DIR}/third_party/SDL2-2.30.1/lib/x64/SDL2_image.lib"
)
