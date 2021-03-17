

#core
file(GLOB_RECURSE src_pEngine_core
./src/pEngine/core/*.cpp
./src/pEngine/core/*.h
)

#event
file(GLOB src_pEngine_event
./src/pEngine/Event/*.cpp
./src/pEngine/Event/*.h
)

#head
file(GLOB head_pEngine
./src/*.h
)

message(STATUS ${head_pEngine})
#...

#thirdParty
file(GLOB_RECURSE thirdSrc_pEngine_code
./thirdParty/spdlog/src/*.cpp
./thirdParty/spdlog/include/*.h
)

add_definitions( 
-DPLATEFORM_WINDOWS 
-DBUILD_DLL 
-DSPDLOG_COMPILED_LIB     #spdlog
)

include_directories(
./src
./src/pEngine/core
./src/pEngine/event
./thirdParty/spdlog/include)

add_library(pEngine SHARED 
${src_pEngine_core}
${src_pEngine_event}
${thirdSrc_pEngine_code}
)

source_group("src\\pEngine\\core" FILES ${src_pEngine_core})
source_group("src\\pEngine\\event" FILES ${src_pEngine_event})
source_group("src\\" FILES ${head_pEngine})

#thirdParty
source_group("thirdParty\\spdlog" FILES ${thirdSrc_pEngine_code})

set_target_properties(pEngine PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
install(TARGETS pEngine RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/Debug/bin)
