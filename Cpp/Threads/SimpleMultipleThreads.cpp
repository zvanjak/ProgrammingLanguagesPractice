#include "stdafx.h"

#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <tuple>

using namespace std;
using namespace std::chrono;

// standardan primjer s više threadova
void hello(){
    std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
}

void testMultipleThreads()
{
    std::vector<std::thread> threads;

    for(int i = 0; i < 5; ++i){
        threads.push_back(std::thread(hello));
    }

    for(auto& thread : threads){
        thread.join();
    }
}
