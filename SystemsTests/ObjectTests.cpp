#include "stdafx.h"

#include "../Systems/Object.h"
#include "../Systems/Position.h"
#include "../Systems/NullRefException.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace SystemsTests
{
	[TestClass]
	public ref class ObjectTests
	{
	public: 
		[TestMethod]
		void Position_GetFromNull()
		{
			/*Survive::Object test;
			
			try
			{
				Survive::Position p = test.GetPosition();
			}
			catch (Survive::NullRefException e)
			{
				const char* expected = "Position has not be set.";
				const char* actual = e.what();
				
				Assert::AreEqual(0, strcmp(expected, actual));
				return;
			}
			
			catch (...)
			{
				Assert::Fail("Unknown Exception thrown");
			}
			
			Assert::Fail("No Exception thrown");*/
			
		}

		[TestMethod]
		void Position_GetFromSet_Atomic()
		{
			Survive::Object test;
			test.SetPosition(0, 0);

			Survive::Position p = test.GetPosition();
			Assert::AreEqual(0, p.GetX());
			Assert::AreEqual(0, p.GetY());

		}

		[TestMethod]
		void Position_GetFromSet_Reference()
		{
			Survive::Object test;
			Survive::Position p2(0, 0);
			test.SetPosition(p2);

			Survive::Position p = test.GetPosition();
			Assert::AreEqual(p2.GetX(), p.GetX());
			Assert::AreEqual(p2.GetY(), p.GetY());

		}

		[TestMethod]
		void Position_GetFromSet_Pointer()
		{
			Survive::Object test;

			Survive::Position* p2 = new Survive::Position(0, 0);

			test.SetPosition(p2);

			Survive::Position p = test.GetPosition();
			Assert::AreEqual(p2->GetX(), p.GetX());
			Assert::AreEqual(p2->GetY(), p.GetY());

		}

	};
}
