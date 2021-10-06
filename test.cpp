#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("basic, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<"5\n"
                  "10 1 10 3 4\n"
                  "4\n"
                  "1 10\n"
                  "2 9\n"
                  "3 4\n"
                  "2 2\n";
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();
    
    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    REQUIRE(buffer.str() == "5 2 2 0\n");
}

TEST_CASE("all smaller", "[simple]"){
    std::stringstream input, output;
    input<<"5\n"
           "10 1 10 3 4\n"
           "1\n"
           "11 12\n";
    parseFile(input,output);
    REQUIRE(output.str() == "0\n");
}

TEST_CASE("all smaller, L==R", "[simple]"){
    std::stringstream input, output;
    input<<"5\n"
           "10 1 10 3 4\n"
           "1\n"
           "11 11\n";
    parseFile(input,output);
    REQUIRE(output.str() == "0\n");
}

TEST_CASE("all bigger", "[simple]"){
    std::stringstream input, output;
    input<<"5\n"
           "10 2 10 3 4\n"
           "1\n"
           "0 1\n";
    parseFile(input,output);
    REQUIRE(output.str() == "0\n");
}

TEST_CASE("all bigger, L==R", "[simple]"){
    std::stringstream input, output;
    input<<"5\n"
           "10 2 10 3 4\n"
           "1\n"
           "1 1\n";
    parseFile(input,output);
    REQUIRE(output.str() == "0\n");
}

TEST_CASE("one, L==R", "[simple]"){
    std::stringstream input, output;
    input<<"5\n"
           "10 2 10 3 4\n"
           "1\n"
           "2 2\n";
    parseFile(input,output);
    REQUIRE(output.str() == "1\n");
}

TEST_CASE("multiple, L==R on max", "[simple]"){
    std::stringstream input, output;
    input<<"5\n"
           "10 2 10 3 4\n"
           "1\n"
           "10 10\n";
    parseFile(input,output);
    REQUIRE(output.str() == "2\n");
}

TEST_CASE("multiple, L==R on min", "[simple]"){
    std::stringstream input, output;
    input<<"5\n"
           "10 2 10 2 4\n"
           "1\n"
           "2 2\n";
    parseFile(input,output);
    REQUIRE(output.str() == "2\n");
}

TEST_CASE("all", "[simple]"){
    std::stringstream input, output;
    input<<"5\n"
           "10 2 10 2 4\n"
           "1\n"
           "0 11\n";
    parseFile(input,output);
    REQUIRE(output.str() == "5\n");
}

TEST_CASE("all, L==R", "[simple]"){
    std::stringstream input, output;
    input<<"5\n"
           "2 2 2 2 2\n"
           "1\n"
           "2 2\n";
    parseFile(input,output);
    REQUIRE(output.str() == "5\n");
}
