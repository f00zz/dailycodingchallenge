set(ASSET_DIR "${CMAKE_CURRENT_SOURCE_DIR}/shaders")
set(DEST_ASSETS "${CMAKE_CURRENT_BINARY_DIR}/shaders")
 
add_custom_command(
    OUTPUT ${DEST_ASSETS}
    COMMAND ln -s ${ASSET_DIR} ${DEST_ASSETS}
    DEPENDS ${ASSET_DIR})

add_executable(slices main.cc ${DEST_ASSETS})

target_link_libraries(
    slices
    PUBLIC
    ${OPENGL_LIBRARIES}
    ${GLFW3_LIBRARY}
    ${GLEW_LIBRARIES}
    common)

target_include_directories(
    slices
    PUBLIC
    "${PROJECT_SOURCE_DIR}/common")
