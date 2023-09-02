set(TARGET_NAME StateMachine)

add_executable(${TARGET_NAME} main.cpp)

target_link_libraries(${TARGET_NAME}
    PRIVATE Threads::Threads
)

target_include_directories(${TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

install(TARGETS ${TARGET_NAME} RUNTIME DESTINATION bin/${TARGET_NAME})