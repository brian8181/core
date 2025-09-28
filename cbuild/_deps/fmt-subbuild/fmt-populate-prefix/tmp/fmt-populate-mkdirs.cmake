# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/brian/src/core/cbuild/_deps/fmt-src"
  "/home/brian/src/core/cbuild/_deps/fmt-build"
  "/cygdrive/c/Users/brian/src/core/cbuild/_deps/fmt-subbuild/fmt-populate-prefix"
  "/cygdrive/c/Users/brian/src/core/cbuild/_deps/fmt-subbuild/fmt-populate-prefix/tmp"
  "/cygdrive/c/Users/brian/src/core/cbuild/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp"
  "/cygdrive/c/Users/brian/src/core/cbuild/_deps/fmt-subbuild/fmt-populate-prefix/src"
  "/cygdrive/c/Users/brian/src/core/cbuild/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/cygdrive/c/Users/brian/src/core/cbuild/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/cygdrive/c/Users/brian/src/core/cbuild/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
