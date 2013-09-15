cmake_minimum_required (VERSION 2.8)

project (LIBLILWRAPPER)

set (LIBLILWRAPPER_NAME "lilwrapper")

set (SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set (INDP_FILES
  "${SOURCE_DIR}/Thread/Mutex.cpp"
  "${SOURCE_DIR}/Thread/ScopedLock.cpp"
  "${SOURCE_DIR}/Thread/Thread.cpp"
  "${SOURCE_DIR}/Thread/ThreadException.cpp"
  )

if (WIN32)
  set (PLATFORM_FILES
    "${SOURCE_DIR}/Thread/Win/MutexImpl.cpp"
    "${SOURCE_DIR}/Thread/Win/ThreadImpl.cpp"
  )
else (WIN32)
  set (PLATFORM_FILES
    "${SOURCE_DIR}/Thread/Unix/MutexImpl.cpp"
    "${SOURCE_DIR}/Thread/Unix/ThreadImpl.cpp"
  )
endif (WIN32)

set (SOURCE_FILES ${INDP_FILES} ${PLATFORM_FILES})
set (INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include")

include_directories (${INCLUDE_DIRS})

if (NOT DYNAMIC OR STATIC)
  # static library `cmake .. -DSTATIC=1` or `cmake ..` (e.g.: libnetsoul.a)
  add_library (${LIBLILWRAPPER_NAME} STATIC ${SOURCE_FILES})
else ()
  # dynamic library `cmake .. -DDYNAMIC=1` (e.g.: libnetsoul.so)
  add_library (${LIBLILWRAPPER_NAME} SHARED ${SOURCE_FILES})
endif()

###############################################################################

enable_testing ()

set (TEST_THREAD_NAME "test_thread")
set (TEST_MUTEX_NAME "test_mutex")
set (TEST_DIR "${PROJECT_SOURCE_DIR}/test")

set (SRC_THREAD_FILES "${TEST_DIR}/thread.cpp" "${TEST_DIR}/mockclass.cpp")
set (SRC_MUTEX_FILES "${TEST_DIR}/mutex.cpp" "${TEST_DIR}/mockclass.cpp")

set (INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include" "${TEST_DIR}")

add_executable (${TEST_THREAD_NAME} ${SRC_THREAD_FILES})
add_executable (${TEST_MUTEX_NAME} ${SRC_MUTEX_FILES})

target_link_libraries (${TEST_THREAD_NAME} ${LIBLILWRAPPER_NAME})
target_link_libraries (${TEST_MUTEX_NAME} ${LIBLILWRAPPER_NAME})

add_test (NAME ${TEST_THREAD_NAME} COMMAND ${TEST_THREAD_NAME})
add_test (NAME ${TEST_MUTEX_NAME} COMMAND ${TEST_MUTEX_NAME})
