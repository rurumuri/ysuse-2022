cmake_minimum_required(VERSION 3.26)
project(aWDLogisticsManagementSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(aWDLogisticsManagementSystem main.cpp
        arrayWDigraph.h
        node.h
        edge.h
        graph.h
        vertexIterator.h
        arrayWDigraph_basic.tpp
        arrayWDigraph_file_io.tpp
        arrayWDigraph_init.tpp
        arrayWDigraph_path.tpp
)
