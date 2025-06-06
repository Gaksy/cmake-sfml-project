cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Util/Camera.cpp
        src/Util/Timer.cpp
        src/Util/Platform.cpp
        src/Util/MainDrawUtil.cpp
        src/ResourcesUnit/Atlas.cpp
        src/ResourcesUnit/Animation.cpp
        src/ResourcesUnit/ResourcesUtils.cpp
        src/ResourcesUnit/SoundManager.cpp
        src/Scene/Scene.cpp
        src/Scene/MenuScene.cpp
        src/Scene/GameScene.cpp
        src/Scene/SceneManager.cpp
        src/Scene/SelectorScene.cpp
        src/include/Player/Player.cpp
        src/include/Player/Player.h
)
target_include_directories(${PROJECT_NAME} PUBLIC src/include)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics SFML::Audio)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/resources
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)