#ifndef SAMPLE_LIBRARY_SAMPLE_CLASS_A_H
#define SAMPLE_LIBRARY_SAMPLE_CLASS_A_H

#ifdef _WIN32
	#define DLLEXPORT __declspec(dllexport)
#else
	#ifndef DLLEXPORT
		#define DLLEXPORT
	#endif
#endif

namespace SampleLibrary
{
	class DLLEXPORT SampleClassA
	{
	public:
		SampleClassA(void);
		void SetValue(int value);
		int GetValue();
	private:
		int value_;
	};
}

#endif