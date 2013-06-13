CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

IF ("${SOURCE_ROOT}" STREQUAL "")
   SET(SOURCE_ROOT .)
ENDIF("${SOURCE_ROOT}" STREQUAL "")

ADD_LIBRARY(hashkit SHARED
            libhashkit/algorithm.c
            libhashkit/behavior.c
            libhashkit/crc32.c
            libhashkit/fnv.c
            libhashkit/digest.c
            libhashkit/function.c
            libhashkit/hashkit.c
            libhashkit/jenkins.c
            libhashkit/ketama.c
            libhashkit/md5.c
            libhashkit/one_at_a_time.c
            libhashkit/strerror.c)
SET_TARGET_PROPERTIES(hashkit PROPERTIES SOVERSION 1.0.0)
SET_TARGET_PROPERTIES(hashkit PROPERTIES
                      COMPILE_FLAGS -DBUILDING_HASHKIT=1)

ADD_LIBRARY(lmemcached SHARED
            libmemcached/allocators.c libmemcached/analyze.c
            libmemcached/auto.c libmemcached/behavior.c
            libmemcached/byteorder.c libmemcached/connect.c
            libmemcached/delete.c libmemcached/do.c
            libmemcached/dump.c libmemcached/fetch.c
            libmemcached/flush.c libmemcached/flush_buffers.c
            libmemcached/get.c libmemcached/hash.c
            libmemcached/hosts.c libmemcached/io.c libmemcached/key.c
            libmemcached/memcached.c libmemcached/parse.c
            libmemcached/purge.c libmemcached/quit.c
            libmemcached/response.c libmemcached/result.c
            libmemcached/server.c libmemcached/server_list.c
            libmemcached/stats.c libmemcached/string.c
            libmemcached/storage.c
            libmemcached/strerror.c libmemcached/verbosity.c
            libmemcached/version.c)

SET_TARGET_PROPERTIES(lmemcached PROPERTIES SOVERSION 6.1.0)
SET_TARGET_PROPERTIES(lmemcached PROPERTIES
                      COMPILE_FLAGS "-std=gnu99")

IF (WIN32)
    INCLUDE_DIRECTORIES(BEFORE ${SOURCE_ROOT}
                               ${SOURCE_ROOT}/win32)
ELSE (WIN32)
    INCLUDE_DIRECTORIES(BEFORE ${SOURCE_ROOT})
    TARGET_LINK_LIBRARIES(hashkit m)
ENDIF (WIN32)

INSTALL(FILES
        libhashkit/algorithm.h libhashkit/behavior.h
        libhashkit/configure.h libhashkit/digest.h
        libhashkit/function.h libhashkit/hashkit.h
        libhashkit/strerror.h libhashkit/types.h
        libhashkit/visibility.h
        DESTINATION include/libhashkit)

INSTALL(FILES
        libmemcached/allocators.h libmemcached/analyze.h
        libmemcached/auto.h libmemcached/behavior.h
        libmemcached/callback.h libmemcached/configure.h
        libmemcached/constants.h libmemcached/delete.h
        libmemcached/dump.h libmemcached/exception.hpp
        libmemcached/fetch.h libmemcached/flush.h
        libmemcached/flush_buffers.h libmemcached/get.h
        libmemcached/hash.h libmemcached/memcached.h
        libmemcached/memcached.hpp
        libmemcached/memcached/protocol_binary.h libmemcached/parse.h
        libmemcached/platform.h libmemcached/quit.h
        libmemcached/result.h libmemcached/sasl.h
        libmemcached/server.h libmemcached/server_list.h
        libmemcached/stats.h libmemcached/storage.h
        libmemcached/strerror.h libmemcached/string.h
        libmemcached/types.h libmemcached/verbosity.h
        libmemcached/version.h libmemcached/visibility.h
        libmemcached/watchpoint.h
        DESTINATION include/libmemcached)

INSTALL(TARGETS hashkit lmemcached
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
