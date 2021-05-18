#file(GLOB SOURCES
#    "core/*.cpp"
#    "html/*.cpp"
#    "json/*.cpp"
#    "soap/*.cpp"
#    "xml/*.cpp"
#    "serialization/*.cpp"
#    )

add_subdirectory(core)
add_subdirectory(html)
add_subdirectory(json)
add_subdirectory(serialization)
add_subdirectory(xml)
add_subdirectory(soap)

file(GLOB HEADERS ${HEADERS})
add_library(tooska STATIC ${SOURCES} ${HEADERS})
#include_directories("src")
find_package (Threads)

target_include_directories (${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

