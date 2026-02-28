set(project_name "clean-duke3d")
add_definitions(-DCHECK_XDUKE_REV)

set(src_files
    duke3d.h
    dukeunix.h
    dukewin.h
    funct.h
    function.h
    game.c
    game.h
    gamedef.c
    gamedefs.h
    global.c
    global.h
    names.h
    player.c
    player.h
    premap.c
    premap.h
    sector.c
    sector.h
    soundefs.h
    types.h
)

set(LIBS
    actors
    audiolib
    automap
    build
    con
    config
    console
    hud
    input
    memory
    menu
    physics
    renderer
    rts
    video
)

foreach(LIB ${LIBS})
    add_subdirectory(${LIB})
endforeach()

if(WIN32)
    set(resource_files cleanDukeResources.rc)
    set(socket_library ws2_32.lib)
endif()

add_executable(${project_name} ${src_files} ${resource_files})
target_include_directories(${project_name} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(${project_name} ${LIBS} ${socket_library} ${SDL2_ALL_LIBRARIES})
