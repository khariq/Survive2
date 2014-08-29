#include "stdafx.h"

#include "../Systems/MobileObject.h"
#include "../Systems/Position.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace SystemsTests
{
	[TestClass]
	public ref class MobileObjectTets
	{
	public: 

		[TestMethod]
		void MobileObject_MoveTo_Atomic()
		{
			Survive::MobileObject test;
			test.MoveTo(0, 0);

			Assert::AreEqual(0, test.GetPosition().GetX());
			Assert::AreEqual(0, test.GetPosition().GetY());

			test.MoveTo(10, 5);
			Assert::AreEqual(10, test.GetPosition().GetX());
			Assert::AreEqual(5, test.GetPosition().GetY());

		}

		[TestMethod]
		void MobileObject_MoveTo_Reference()
		{
			Survive::MobileObject test;
			Survive::Position start(0, 0);
			test.MoveTo(start);

			Assert::AreEqual(0, test.GetPosition().GetX());
			Assert::AreEqual(0, test.GetPosition().GetY());

			Survive::Position destination(10, 5);
			test.MoveTo(destination);
			Assert::AreEqual(10, test.GetPosition().GetX());
			Assert::AreEqual(5, test.GetPosition().GetY());
		}

		[TestMethod]
		void MobileObject_MoveTo_Pointer()
		{
			Survive::MobileObject test;
			Survive::Position* start = new Survive::Position(0, 0);
			test.MoveTo(start);

			Assert::AreEqual(0, test.GetPosition().GetX());
			Assert::AreEqual(0, test.GetPosition().GetY());

			Survive::Position* destination = new Survive::Position(10, 5);
			test.MoveTo(destination);
			Assert::AreEqual(10, test.GetPosition().GetX());
			Assert::AreEqual(5, test.GetPosition().GetY());
		}
	};
}
