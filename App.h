#pragma once
#include <iostream>
#include "Number.h"
#include "Matrix.h"

class App
{
private:
	number* getArrayValues(Uint);
	int menu();
public:
	App();
	int exec();
};

