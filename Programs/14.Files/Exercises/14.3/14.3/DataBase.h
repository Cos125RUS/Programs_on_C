#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <cassert>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <cstring>
#include <csetjmp>
#include <exception>
#include <stdexcept>
#include <new>
#include <stdlib.h>
#include <memory>
#include <fstream>
#include "ClientData.h"

using namespace std;

#pragma once
class DataBase
{
public:
	DataBase(const char*, const char*, const char*);
	void readOldMaster();
	void readTrans();
	void writeNewMaster(const ClientData& clientData);
private:
	ifstream inOldMaster;
	ifstream inTransaction;
	ofstream outNewMaster;
};

