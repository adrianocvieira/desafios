
set(src_files
  pokemon.cpp
  pokemon.h
)

add_library(src ${src_files})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} src)
