// Threads.cpp : Defines the entry point for the console application.
//

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


// ajmo probati da više threadova pristupa jednoj listi!
long long sumPartialVector(vector<int> &vec, int start, int end, long long *outSum)
{
		cout << "Started thread" << endl;
		long long s = accumulate(vec.begin()+start, vec.begin()+end, 0LL);

		*outSum = s;

		return s;
}

tuple<int, int> testThreadsWithVector(int inNumThreads, int inNumElems)
{
		tuple<int, int> results;

		cout << "Preparing vector ..." << endl;
		vector<int> vecNums(inNumElems);

		for(int i=0; i<inNumElems; i++ )		vecNums[i] = rand() % 1000;

		// idemo sinkrono izračunati zbroj
		auto t1 = std::chrono::system_clock::now();

		long long s = accumulate(vecNums.begin(), vecNums.end(), 0LL);

		auto t2 = std::chrono::system_clock::now();
		auto dms = std::chrono::duration_cast<milliseconds>(t2-t1);

		cout << "Single thread duration = " << dms.count() << " milliseconds" << endl << "Sum = " << s << endl;

		get<0>(results) = dms.count();

		vector<long long> sums(inNumThreads);
		long numsPerThread = inNumElems / inNumThreads;
		std::vector<std::thread> threads;

		cout << "And go ... " << endl;

		// a sad idemo to probati multithreaded
		t1 = std::chrono::system_clock::now();

		for(int i = 0; i < inNumThreads; ++i){
        threads.push_back(std::thread(sumPartialVector, ref(vecNums), i*numsPerThread, (i+1) * numsPerThread, &sums[i]));
    }

    for(auto& thread : threads){
        thread.join();
    }

		t2 = std::chrono::system_clock::now();
		dms = std::chrono::duration_cast<milliseconds>(t2-t1);

		cout << "Multi thread duration with " << inNumThreads << " threads = " << dms.count() << " milliseconds" << endl << "Sum = " << accumulate(sums.begin(), sums.end(), 0LL) << endl;

		get<1>(results) = dms.count();

		return results;
}

int main()
{
	int cnt1 = 0, cnt2 = 0;

	for( int i=0; i<10; i++ )
	{
		tuple<int, int> res = testThreadsWithVector(4, 50000000);
		cnt1 += get<0>(res);
		cnt2 += get<1>(res);
	}

	cout << "Single threaded : " << cnt1 / 10 << endl;
	cout << "Multi threaded : " << cnt2 / 10 << endl;

    return 0;
}