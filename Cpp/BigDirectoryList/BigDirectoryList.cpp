// BigDirectoryList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <filesystem>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
using namespace std::tr2::sys;

long long directorySize(path  inPath)
{
	auto start_path = inPath;
	long long totalSize = 0;

	for (auto it = directory_iterator(start_path); it != directory_iterator(); ++it)
	{
		const auto& file = it->path();

		auto fileRes = inPath / file ;

		if (is_regular_file(fileRes) )
		{
			// cout << file.filename() << put_time(localtime(&last_write), "%Y/%m/%d %H:%M:%S") << endl;
			totalSize += file_size(fileRes);
		}
		else if( is_directory(fileRes) )
		{
			totalSize += directorySize(fileRes);
			//cout << "Directory - " << fileRes << " = " << totalSize << endl;
		}
	}
	return totalSize;
}

void file_info(path inPath)
{
	if (exists(inPath))    // does p actually exist?
	{
		if (is_regular_file(inPath))        // is p a regular file?   
			cout << inPath << " size is " << file_size(inPath) << '\n';

		else if (is_directory(inPath))      // is p a directory?
			cout << inPath << " is a directory\n";

		else
			cout << inPath << " exists, but is neither a regular file nor a directory\n";
	}
	else
		cout << inPath << "does not exist\n";
}

long long listBigDirs(path  inPath, vector<string> &dirs, long long reqSize, int level)
{
	auto start_path = inPath;
	long long totalSize = 0;

	for (auto it = directory_iterator(start_path); it != directory_iterator(); ++it)
	{
		const auto& file = it->path();			// relative path

		auto fileRes = inPath / file ;

		if (is_regular_file(fileRes) )
		{
			totalSize += file_size(fileRes);
		}
		else if( is_directory(fileRes) )
		{
			long long subDirSize = listBigDirs(fileRes, dirs, reqSize, level+1);

			if( subDirSize >= reqSize )
			{
				string indent(level * 2, ' ');
				string sFileName = indent + fileRes.filename();
				string sSize = " - " + to_string(subDirSize >> 20) + " MB";
				cout << setw(30 - level*2) << left << sFileName << sSize << endl;
				
				dirs.push_back(sFileName + sSize);
			}

			totalSize += subDirSize;
		}
	}
	return totalSize;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// path p ((char *) argv[1]);   // p reads clearer than argv[1] in the following code
	path p ("D:\\Users\\Zvone\\_FER");   // p reads clearer than argv[1] in the following code

	long long totalSize = directorySize(p);
	cout << "Total size for directory: " << p << " is " << (totalSize) << " Mb" << endl;

	vector<string> vecDirs;
	listBigDirs(p, vecDirs, 50000000, 1);

	// sad treba 
	return 0;
}

