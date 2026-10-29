#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.3it/Lab_07.3it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest731
{
    TEST_CLASS(UnitTest731)
    {
    public:
        TEST_METHOD(TestCountColsWithoutZero)
        {
            int r0[4] = { 1, 0, 3, 4 };
            int r1[4] = { 5, 6, 0, 8 };
            int* a[2] = { r0, r1 };
            Assert::AreEqual(2, CountColsWithoutZero(a, 2, 4));
        }

        TEST_METHOD(TestRowCharacteristic)
        {
            int r0[5] = { 4, -6, 7, 10, 0 };
            int* a[1] = { r0 };
            Assert::AreEqual(14, RowCharacteristic(a, 0, 5));
        }

        TEST_METHOD(TestSortRows)
        {
            int r0[3] = { 8, 2, 1 };    // 10
            int r1[3] = { -4, 3, 0 };   // 0
            int r2[3] = { 6, 5, -2 };   // 6
            int* a[3] = { r0, r1, r2 };
            SortRowsByCharacteristic(a, 3, 3);
            Assert::AreEqual(-4, a[0][0]);
            Assert::AreEqual(6, a[1][0]);
            Assert::AreEqual(8, a[2][0]);
        }
    };
}
