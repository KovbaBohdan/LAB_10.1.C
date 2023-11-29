#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include "../LAB_10.1.C/lab_10.1.C.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const char* filename = "test.txt";
            FILE* testFile;
            
            if ((testFile = fopen(filename, "w")) == NULL) {
                Assert::Fail(L"Failed to create test file");
            }

            const char* testData = "aaaabbbbccccdddd"; 

            fprintf(testFile, "%s", testData);
            fclose(testFile);

            int result;

            result = Count(testFile);

            fclose(testFile);

            Assert::AreEqual(4, result);
		}
	};
}
