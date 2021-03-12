
file(GLOB src_test_code
./src/*.cpp
)


add_definitions( -DPLATEFORM_WINDOWS )

add_executable(testBox ${src_test_code})

target_include_directories(testBox PUBLIC
../pEngine/src
../pEngine/thirdParty/spdlog/include
)

target_link_libraries(testBox pEngine)

source_group(src FILES ${src_test_code})
set_target_properties(testBox PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

install(TARGETS testBox RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/Debug/bin)