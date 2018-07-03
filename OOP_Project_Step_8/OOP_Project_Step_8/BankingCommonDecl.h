#pragma once
#include <iostream>
#include <string>
#include "AccountHandler.h"

using std::cout;
using std::cin;
using std::endl;

enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOWINFO, EXIT };
enum { LEV_A = 7, LEV_B = 4, LEV_C = 2 };
enum { NORMAL = 1, CREDIT = 2 };