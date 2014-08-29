#include "Survivor.h"
#include "Constants.h"
#include <random>
#include <ctime>

namespace Survive
{
	Survive::SurvivorPtr Survivor::CreateSurvivor()
	{
		Survive::SurvivorPtr created(new Survivor());

		// Seed with a real random value, if available
		std::random_device rd;

		// Choose a random mean between 1 and 6
		std::default_random_engine e1(rd());
		std::uniform_int_distribution<int> uniform_dist(1, 6);
		
		created->_body = uniform_dist(e1);
		created->_strength = uniform_dist(e1);

		created->_intuition = uniform_dist(e1);
		created->_willpower = uniform_dist(e1);

		int positive = uniform_dist(e1);
		int negative = uniform_dist(e1) * -1;
		while (positive + negative == 0)
		{
			positive = uniform_dist(e1);
			negative = uniform_dist(e1)  * -1;
		}
		created->_positiveTrait = (Survive::SurvivorTraits)positive;
		created->_negativeTrait = (Survive::SurvivorTraits)negative;

		created->_currentHealth = created->GetStat(Survive::SurvivorStat::Health);

		return created;
	}

	Survivor::Survivor()
	{
		_body = _strength = _intuition = _willpower = 0;
	}


	Survivor::~Survivor()
	{
	}

	int Survivor::GetStat(SurvivorStat stat) const
	{		
		int value = 0;
		switch (stat)
		{
			case Survive::Body:
				value = _body; break;
			case Survive::Strength:
				value = _strength; break;
			case Survive::Intuition: 
				value = _intuition; break;
			case Survive::Willpower:
				value = _willpower; break;
			case Survive::Health:
				value = _body 
					 + _willpower 
					 + (_positiveTrait == SurvivorTraits::Tough    ? Survive::Constants::PositiveTraitValue : 0)
					 + (_negativeTrait == SurvivorTraits::ThinSkin ? Survive::Constants::NegativeTraitValue : 0); break;
			case Survive::Speed:
				value = _body
					 + _strength 
					 + (_positiveTrait == SurvivorTraits::Quick		 ? Survive::Constants::PositiveTraitValue : 0)
					 + (_negativeTrait == SurvivorTraits::Overweight ? Survive::Constants::NegativeTraitValue : 0); break;
				
			case Survive::Endurance:
				value = _strength + _willpower; break;
			case Survive::Resistance:
				value = _body + _intuition; break;
			case Survive::Reflex:
				value = _strength
					 + _intuition 
					 + (_positiveTrait == SurvivorTraits::Catlike  ? Survive::Constants::PositiveTraitValue : 0)
					 + (_negativeTrait == SurvivorTraits::Sluggish ? Survive::Constants::NegativeTraitValue : 0); break;
				
			case Survive::Aim:
				value = _intuition
					 + _willpower 
					 + (_positiveTrait == SurvivorTraits::Bullseye ? Survive::Constants::PositiveTraitValue : 0) 
					 + (_negativeTrait == SurvivorTraits::OneEye ? Survive::Constants::NegativeTraitValue : 0); break;
				
			default:
				return -1;
		}
		return std::fmax(1, value);
	}

	void Survivor::Injure(int damage)
	{
		_currentHealth = (int)std::fmax(0, _currentHealth - damage);		
	}

	void Survivor::Heal()
	{
		int maxHealth = GetStat(Health);
		_daysLeftToRest = maxHealth - _currentHealth;
		_currentHealth = maxHealth; 
	}

	void Survivor::Rest()
	{
		_daysLeftToRest = std::fmax(0, _daysLeftToRest - 1);
	}

}