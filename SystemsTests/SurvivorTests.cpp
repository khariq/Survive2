#include "stdafx.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

#include "../Systems/Survivor.h"
#include "../Systems/Constants.h"

namespace SystemsTests
{
	[TestClass]
	public ref class SurvivorTests
	{
	public: 
		[TestMethod]
		void CreateSurvivor()
		{
			for (int i = 0; i < 50; i++)
			{			
				std::auto_ptr<Survive::Survivor> created = Survive::Survivor::CreateSurvivor();
				Assert::AreNotEqual(0, created->GetStat(Survive::SurvivorStat::Body), "Body");
				Assert::AreNotEqual(0, created->GetStat(Survive::SurvivorStat::Strength), "Strength");
				Assert::AreNotEqual(0, created->GetStat(Survive::SurvivorStat::Willpower), "Willpower");
				Assert::AreNotEqual(0, created->GetStat(Survive::SurvivorStat::Intuition), "Intuition");

				Assert::AreNotEqual(0, created->GetStat(Survive::SurvivorStat::Health));
				Assert::AreNotEqual(0, created->GetStat(Survive::SurvivorStat::Speed));
				Assert::AreNotEqual(0, created->GetStat(Survive::SurvivorStat::Endurance));
				Assert::AreNotEqual(0, created->GetStat(Survive::SurvivorStat::Resistance));
				Assert::AreNotEqual(0, created->GetStat(Survive::SurvivorStat::Reflex));
				Assert::AreNotEqual(0, created->GetStat(Survive::SurvivorStat::Aim));

				Assert::IsTrue(1 <= created->GetStat(Survive::SurvivorStat::Body) && 6 >= created->GetStat(Survive::SurvivorStat::Body), "Body");
				Assert::IsTrue(1 <= created->GetStat(Survive::SurvivorStat::Strength) && 6 >= created->GetStat(Survive::SurvivorStat::Strength), "Strength");
				Assert::IsTrue(1 <= created->GetStat(Survive::SurvivorStat::Willpower) && 6 >= created->GetStat(Survive::SurvivorStat::Willpower), "Willpower");
				Assert::IsTrue(1 <= created->GetStat(Survive::SurvivorStat::Intuition) && 6 >= created->GetStat(Survive::SurvivorStat::Intuition), "Intuition");

				int expected_health = created->GetStat(Survive::SurvivorStat::Body) + created->GetStat(Survive::SurvivorStat::Willpower);
				int expected_speed = created->GetStat(Survive::SurvivorStat::Body) + created->GetStat(Survive::SurvivorStat::Strength);
				int expected_endurance = created->GetStat(Survive::SurvivorStat::Strength) + created->GetStat(Survive::SurvivorStat::Willpower);
				int expected_resistance = created->GetStat(Survive::SurvivorStat::Body) + created->GetStat(Survive::SurvivorStat::Intuition);
				int expected_reflex = created->GetStat(Survive::SurvivorStat::Strength) + created->GetStat(Survive::SurvivorStat::Intuition);
				int expected_aim = created->GetStat(Survive::SurvivorStat::Intuition) + created->GetStat(Survive::SurvivorStat::Willpower);

				switch (created->GetPositiveTrait())
				{
				case Survive::SurvivorTraits::Bullseye:		expected_aim += Survive::Constants::PositiveTraitValue; break;
				case Survive::SurvivorTraits::Quick:		expected_speed += Survive::Constants::PositiveTraitValue; break;
				case Survive::SurvivorTraits::Tough:		expected_health += Survive::Constants::PositiveTraitValue; break;
				case Survive::SurvivorTraits::Catlike:		expected_reflex += Survive::Constants::PositiveTraitValue; break;
				}

				switch (created->GetNegativeTrait())
				{
				case Survive::SurvivorTraits::OneEye:		expected_aim += Survive::Constants::NegativeTraitValue; break;
				case Survive::SurvivorTraits::Overweight:	expected_speed += Survive::Constants::NegativeTraitValue; break;
				case Survive::SurvivorTraits::ThinSkin:		expected_health += Survive::Constants::NegativeTraitValue; break;
				case Survive::SurvivorTraits::Sluggish:		expected_reflex += Survive::Constants::NegativeTraitValue; break;
				}

				if (expected_health <= 0) expected_health = 1;
				if (expected_speed <= 0) expected_speed = 1;
				if (expected_endurance <= 0) expected_endurance = 1;
				if (expected_resistance <= 0) expected_resistance = 1;
				if (expected_reflex <= 0) expected_reflex = 1;
				if (expected_aim <= 0) expected_aim = 1;

				Assert::AreEqual(expected_health, created->GetStat(Survive::SurvivorStat::Health), "Health");
				Assert::AreEqual(expected_speed, created->GetStat(Survive::SurvivorStat::Speed), "Speed");
				Assert::AreEqual(expected_endurance, created->GetStat(Survive::SurvivorStat::Endurance), "Endurance");
				Assert::AreEqual(expected_resistance, created->GetStat(Survive::SurvivorStat::Resistance), "Resistance");
				Assert::AreEqual(expected_reflex, created->GetStat(Survive::SurvivorStat::Reflex), "Reflex");
				Assert::AreEqual(expected_aim, created->GetStat(Survive::SurvivorStat::Aim), "Aim");

				created.release();
			}
		}

		void Injury()
		{
			Survive::SurvivorPtr victim = Survive::Survivor::CreateSurvivor();

			int maxHealth = victim->GetStat(Survive::SurvivorStat::Health);
			Assert::AreEqual(maxHealth, victim->GetCurrentHealth());

			victim->Injure(1);

			Assert::AreEqual(maxHealth - 1, victim->GetCurrentHealth());
		}

		void Kill()
		{
			Survive::SurvivorPtr victim = Survive::Survivor::CreateSurvivor();

			int maxHealth = victim->GetStat(Survive::SurvivorStat::Health);
			Assert::AreEqual(maxHealth, victim->GetCurrentHealth());

			victim->Injure(maxHealth);

			Assert::AreEqual(0, victim->GetCurrentHealth());
		}

		void Overkill()
		{
			Survive::SurvivorPtr victim = Survive::Survivor::CreateSurvivor();

			int maxHealth = victim->GetStat(Survive::SurvivorStat::Health);
			Assert::AreEqual(maxHealth, victim->GetCurrentHealth());

			victim->Injure(1);

			Assert::AreEqual(maxHealth - 1, victim->GetCurrentHealth());
		}

	};
}
