#include "stdafx.h"
#include "MyArray.h"
#include <string>

using namespace std;

BOOST_AUTO_TEST_CASE(CreateEmptyArray)
{
	{
		const CMyArray<string> stringArray;
		BOOST_CHECK(stringArray.IsEmpty());
		BOOST_CHECK_EQUAL(stringArray.GetSize(), 0u);
		BOOST_CHECK_THROW(stringArray[0], out_of_range);
	}
	{
		CMyArray<double> numsArray;
		BOOST_CHECK(numsArray.IsEmpty());
		BOOST_CHECK_THROW(numsArray[0], out_of_range);
	}
}

BOOST_AUTO_TEST_CASE(AddNewElement)
{
	{
		CMyArray<string> stringArray;
		string str = "test";
		BOOST_CHECK_NO_THROW(stringArray.Push(str));
		BOOST_REQUIRE_EQUAL(stringArray.GetSize(), 1u);
		BOOST_CHECK_EQUAL(stringArray[0], str);
	}
	{
		CMyArray<double> numsArray;
		double num = 4.5;
		BOOST_CHECK_NO_THROW(numsArray.Push(num));
		BOOST_REQUIRE_EQUAL(numsArray.GetSize(), 1u);
		BOOST_CHECK_EQUAL(numsArray[0], num);
	}
}

BOOST_AUTO_TEST_CASE(TestResizeMethod)
{
	{
		CMyArray<string> stringArray;
		for (int i = 0; i < 5; ++i)
		{
			stringArray.Push(to_string(i));
		}
		BOOST_CHECK(!stringArray.IsEmpty());
		BOOST_CHECK_EQUAL(stringArray.GetSize(), 5u);
		BOOST_CHECK_EQUAL(stringArray[4], "4");
		stringArray.Resize(2);
		BOOST_CHECK_EQUAL(stringArray.GetSize(), 2u);
		BOOST_CHECK_EQUAL(stringArray[1], "1");
		BOOST_CHECK_THROW(stringArray[2], out_of_range);
	}
	{
		CMyArray<double> numsArray;
		for (int i = 0; i < 5; ++i)
		{
			numsArray.Push(i);
		}
		BOOST_CHECK(!numsArray.IsEmpty());
		BOOST_CHECK_EQUAL(numsArray.GetSize(), 5u);
		BOOST_CHECK_EQUAL(numsArray[4], 4);
		numsArray.Resize(100);
		BOOST_CHECK_EQUAL(numsArray.GetSize(), 100u);
		BOOST_CHECK_EQUAL(numsArray[1], 1);
		BOOST_CHECK_EQUAL(numsArray[99], 0);
		BOOST_CHECK_THROW(numsArray[205], out_of_range);
	}
}

BOOST_AUTO_TEST_CASE(TestClearMethod)
{
	{
		CMyArray<string> stringArray;
		for (int i = 0; i < 5; ++i)
		{
			stringArray.Push(to_string(i));
		}
		BOOST_CHECK_EQUAL(stringArray.GetSize(), 5u);
		stringArray.Clear();
		BOOST_CHECK(stringArray.IsEmpty());
		BOOST_CHECK_EQUAL(stringArray.GetSize(), 0u);
	}
	{
		CMyArray<double> numsArray;
		for (int i = 0; i < 5; ++i)
		{
			numsArray.Push(i);
		}
		BOOST_CHECK_EQUAL(numsArray.GetSize(), 5u);
		numsArray.Clear();
		BOOST_CHECK(numsArray.IsEmpty());
		BOOST_CHECK_EQUAL(numsArray.GetSize(), 0u);
	}

}

BOOST_AUTO_TEST_CASE(TestCopyConstructorAndOperatorOfAssignment)
{
	{
		CMyArray<string> stringArray;
		for (int i = 0; i < 5; ++i)
		{
			stringArray.Push(to_string(i));
		}
		{
			CMyArray<string> newArray(stringArray);
			BOOST_REQUIRE_NO_THROW(newArray[4]);
			BOOST_CHECK_EQUAL(newArray[4], stringArray[4]);
		}
		BOOST_REQUIRE_NO_THROW(stringArray[4]);
	}
	{
		CMyArray<string> stringArray;
		CMyArray<string> newArray;
		for (int i = 0; i < 5; ++i)
		{
			stringArray.Push(to_string(i));
		}
		newArray = stringArray;
		BOOST_REQUIRE_NO_THROW(newArray[4]);
		BOOST_CHECK_EQUAL(newArray.GetSize(), 5u);
		BOOST_CHECK_EQUAL(newArray[4], "4");
	}
}


