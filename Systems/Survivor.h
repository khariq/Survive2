
#pragma once
#include "MobileObject.h"
#include <string>
#include <vector>

namespace Survive
{
	class Survivor;

	typedef	std::auto_ptr<Survivor> SurvivorPtr;

	enum SurvivorStat
	{
		Body,
		Strength,
		Intuition,
		Willpower,
		Health,
		Speed,
		Endurance,
		Resistance,
		Reflex,
		Aim
	};

	enum SurvivorTraits
	{
		Lucky = 1,
		Bullseye = 2,
		Quick = 3,
		Tough = 4,
		Catlike = 5,
		Engineer = 6,

		Clutz = -1,
		OneEye = -2,
		Overweight = -3,
		ThinSkin = -4,
		Sluggish = -5,
		MechanicallyChallenged = -6
	};

	class Survivor : public MobileObject
	{
	protected:

		std::string _name;

		int _body;
		int _strength;
		int _intuition;
		int _willpower;

		int _currentHealth;
		int _daysLeftToRest;
		
		SurvivorTraits _positiveTrait;
		SurvivorTraits _negativeTrait;


		Survivor(int body, int strength, int intuition, int willpower);
		Survivor();

	public:
		virtual ~Survivor();

		static SurvivorPtr CreateSurvivor();

		void SetName(std::string name) { _name = name; }
		std::string GetName() const { return _name; }
		SurvivorTraits GetPositiveTrait() const { return _positiveTrait; }
		SurvivorTraits GetNegativeTrait() const { return _negativeTrait; }

		int GetStat(SurvivorStat stat) const;

		int GetCurrentHealth() const { return _currentHealth; }
		void Injure(int damage);
		void Heal();
		void Rest();
		int  RestRequired() const { return _daysLeftToRest; }

	};

}
