#include "stdafx.h"
#include "SampleClassA.h"

using namespace SampleLibrary;

SampleClassA::SampleClassA(void)
{
}

void SampleClassA::SetValue(int value) 
{
	value_ = value;
}

int SampleClassA::GetValue()
{
	return value_;
}
