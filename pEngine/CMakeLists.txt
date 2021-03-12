

file(GLOB_RECURSE src_pEngine_code 
./src/pEngine/*.cpp
)

file(GLOB_RECURSE header_pEngine_code 
./src/*.h
)

#thirdParty
file(GLOB_RECURSE thirdSrc_pEngine_code
./thirdParty/spdlog/src/*.cpp
)

file(GLOB_RECURSE thirdHeader_pEngine_code 
./thirdParty/spdlog/include
)

#ºê
add_definitions( -DPLATEFORM_WINDOWS -DBUILD_DLL)

include_directories(
./src
./src/pEngine
./thirdParty/spdlog/include)

add_library(pEngine SHARED 
${src_pEngine_code}
${header_pEngine_code}
)

source_group("src\\pEngine" FILES ${src_pEngine_code} ${header_pEngine_code})
source_group("src" FILES ./src/pEngine.h)

set_target_properties(pEngine PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
install(TARGETS pEngine RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/Debug/bin)
