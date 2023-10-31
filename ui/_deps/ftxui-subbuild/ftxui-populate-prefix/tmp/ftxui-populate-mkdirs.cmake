# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/protoman/Programs/TestingDir/TestBranch/ui/_deps/ftxui-src"
  "/home/protoman/Programs/TestingDir/TestBranch/ui/_deps/ftxui-build"
  "/home/protoman/Programs/TestingDir/TestBranch/ui/_deps/ftxui-subbuild/ftxui-populate-prefix"
  "/home/protoman/Programs/TestingDir/TestBranch/ui/_deps/ftxui-subbuild/ftxui-populate-prefix/tmp"
  "/home/protoman/Programs/TestingDir/TestBranch/ui/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp"
  "/home/protoman/Programs/TestingDir/TestBranch/ui/_deps/ftxui-subbuild/ftxui-populate-prefix/src"
  "/home/protoman/Programs/TestingDir/TestBranch/ui/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/protoman/Programs/TestingDir/TestBranch/ui/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/protoman/Programs/TestingDir/TestBranch/ui/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
