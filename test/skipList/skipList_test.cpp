#include "../catch.hpp"
#include "../../src/skiplist.h"
#include <cstdlib>
#include <chrono>
#include <memory>

class Runtime {
    std::chrono::high_resolution_clock::time_point time_start, time_end;
public:
    void start(){
        time_start = std::chrono::high_resolution_clock::now();
    }
    void end(){
        time_end = std::chrono::high_resolution_clock::now();
    }
    void print_result(){
        auto total_time = time_end - time_start;
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(total_time).count();//<<" us ";
    }
};

TEST_CASE("Running Skip List to random set of 256 elements","[skipList]"){
    std::cout << "Insert 256 (us),Delete(us)\n";
    for (int k = 0; k < 30; ++k) {
        SkipList s; // Initialize an empty Skip_list object
        std::srand(0); //initialize random
        //initialize timer structures
        std::unique_ptr<Runtime> runtime = std::unique_ptr<Runtime>(new Runtime());
        runtime->start(); //initi time stamp
        for (int i = 0; i < 256; ++i){ // insert 256 elements
            s.insert(std::rand());
        }
        runtime->end();
        runtime->print_result();
        std::cout << ",";
        runtime->start();
        for (int i = 0; i < 51; ++i){ //erase 20%
            s.remove_first();
        }
        runtime->end();
        runtime->print_result();
        std::cout << "\n";
    }
    std::cout << "\nInsert 4096 (us),Delete(us)\n";
    for (int k = 0; k < 30; ++k) {
        SkipList s; // Initialize an empty Skip_list object
        std::srand(0); //initialize random
        //initialize timer structures
        std::unique_ptr<Runtime> runtime = std::unique_ptr<Runtime>(new Runtime());
        runtime->start(); //initi time stamp
        for (int i = 0; i < 4096; ++i){ // insert 4096 elements
            s.insert(std::rand());
        }
        runtime->end();
        runtime->print_result();
        std::cout << ",";
        runtime->start();
        for (int i = 0; i < 819; ++i){ //erase 20%
            s.remove_first();
        }
        runtime->end();
        runtime->print_result();
        std::cout << "\n";
    }
    std::cout << "\nInsert 65536 (us),Delete(us)\n";
    for (int k = 0; k < 30; ++k) {
        SkipList s; // Initialize an empty Skip_list object
        std::srand(0); //initialize random
        //initialize timer structures
        std::unique_ptr<Runtime> runtime = std::unique_ptr<Runtime>(new Runtime());
        runtime->start(); //initi time stamp
        for (int i = 0; i < 65536; ++i){ // insert 65536 elements
            s.insert(std::rand());
        }
        runtime->end();
        runtime->print_result();
        std::cout << ",";
        runtime->start();
        for (int i = 0; i < 13107; ++i){ //erase 20%
            s.remove_first();
        }
        runtime->end();
        runtime->print_result();
        std::cout << "\n";
    }
    std::cout << "\n";
}

TEST_CASE("Running Skip List to random set of more elements","[extra]"){
    std::cout << "Insert 2176 (us),Delete(us)\n";
    for (int k = 0; k < 30; ++k) {
        SkipList s; // Initialize an empty Skip_list object
        std::srand(0); //initialize random
        //initialize timer structures
        std::unique_ptr<Runtime> runtime = std::unique_ptr<Runtime>(new Runtime());
        runtime->start(); //initi time stamp
        for (int i = 0; i < 2176; ++i){ // insert 2176 elements
            s.insert(std::rand());
        }
        runtime->end();
        runtime->print_result();
        std::cout << ",";
        runtime->start();
        for (int i = 0; i < 435; ++i){ //erase 20%
            s.remove_first();
        }
        runtime->end();
        runtime->print_result();
        std::cout << "\n";
    }
    std::cout << "\nInsert 34816 (us),Delete(us)\n";
    for (int k = 0; k < 30; ++k) {
        SkipList s; // Initialize an empty Skip_list object
        std::srand(0); //initialize random
        //initialize timer structures
        std::unique_ptr<Runtime> runtime = std::unique_ptr<Runtime>(new Runtime());
        runtime->start(); //initi time stamp
        for (int i = 0; i < 34816; ++i){ // insert 34816 elements
            s.insert(std::rand());
        }
        runtime->end();
        runtime->print_result();
        std::cout << ",";
        runtime->start();
        for (int i = 0; i < 6963; ++i){ //erase 20%
            s.remove_first();
        }
        runtime->end();
        runtime->print_result();
        std::cout << "\n";
    }
    std::cout << "\n";
}
