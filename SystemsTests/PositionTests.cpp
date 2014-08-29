#include "stdafx.h"

#include "../Systems/Position.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace SystemsTests
{
	[TestClass]
	public ref class PositionUnitTest
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void Origin_HorizontalStraight()
		{
			//
			// TODO: Add test logic here
			//
			Survive::Position test(0, 0);
			for (int i = 0; i < 10; i++)
			{
				Survive::Position target(i, 0);
				Assert::AreEqual(i, test.RangeTo(target));
			}
		};

		[TestMethod]
		void Origin_VerticalStraight()
		{
			Survive::Position test(0, 0);
			for (int i = 0; i < 10; i++)
			{
				Survive::Position target(0, i);
				Assert::AreEqual(i, test.RangeTo(target));
			}
		}

		[TestMethod]
		void Origin_Diagonal()
		{
			Survive::Position test(0, 0);
			for (int i = 0; i < 10; i++)
			{
				Survive::Position target(i, i);
				Assert::AreEqual(i, test.RangeTo(target));
			}
		}

		[TestMethod]
		void Origin_IsoTris_3_4_5()
		{
			int a = 3, b = 4, c = 5;
			Survive::Position test(0, 0);
			Survive::Position target(a, b);
			Assert::AreEqual(c, test.RangeTo(target));
		}

		[TestMethod]
		void Origin_IsoTris_5_12_13()
		{
			int a = 5, b =12, c =13;
			Survive::Position test(0, 0);
			Survive::Position target(a, b);
			Assert::AreEqual(c, test.RangeTo(target));
		}

		[TestMethod]
		void Origin_IsoTris_6_8_10()
		{
			int a = 6, b = 8, c =10;
			Survive::Position test(0, 0);
			Survive::Position target(a, b);
			Assert::AreEqual(c, test.RangeTo(target));
		}

		[TestMethod]
		void Origin_IsoTris_8_15_17()
		{
			int a = 8, b =15, c =17;
			Survive::Position test(0, 0);
			Survive::Position target(a, b);
			Assert::AreEqual(c, test.RangeTo(target));
		}

		[TestMethod]
		void NonOrigin_HorizontalStraight()
		{
			//
			// TODO: Add test logic here
			//
			Survive::Position test(6, 3);
			for (int i = 0; i < 10; i++)
			{
				Survive::Position target(6 + i, 3);
				Assert::AreEqual(i, test.RangeTo(target));
			}
		};

		[TestMethod]
		void NonOrigin_VerticalStraight()
		{
			Survive::Position test(2, 5);
			for (int i = 0; i < 10; i++)
			{
				Survive::Position target(2, 5 + i);
				Assert::AreEqual(i, test.RangeTo(target));
			}
		}

		[TestMethod]
		void NonOrigin_Diagonal()
		{
			Survive::Position test(8, 10);
			for (int i = 0; i < 10; i++)
			{
				Survive::Position target(8 + i, 10 + i);
				Assert::AreEqual(i, test.RangeTo(target));
			}
		}

		[TestMethod]
		void NonOrigin_IsoTris_3_4_5()
		{
			int a = 3, b = 4, c = 5;
			int center_x = 3, center_y = 12;
			Survive::Position test(center_x, center_y);
			Survive::Position target(a + center_x, b + center_y);
			Assert::AreEqual(c, test.RangeTo(target));
		}

		[TestMethod]
		void NonOrigin_IsoTris_5_12_13()
		{
			int a = 5, b = 12, c = 13;
			int center_x = 3, center_y = 12;
			Survive::Position test(center_x, center_y);
			Survive::Position target(a + center_x, b + center_y);
			Assert::AreEqual(c, test.RangeTo(target));
		}

		[TestMethod]
		void NonOrigin_IsoTris_6_8_10()
		{
			int a = 6, b = 8, c = 10;
			int center_x = 3, center_y = 12;
			Survive::Position test(center_x, center_y);
			Survive::Position target(a + center_x, b + center_y);
			Assert::AreEqual(c, test.RangeTo(target));
		}

		[TestMethod]
		void NonOrigin_IsoTris_8_15_17()
		{
			int a = 8, b = 15, c = 17;
			int center_x = 3, center_y = 12;
			Survive::Position test(center_x, center_y);
			Survive::Position target(a + center_x, b + center_y);
			Assert::AreEqual(c, test.RangeTo(target));
		}

	};
}
