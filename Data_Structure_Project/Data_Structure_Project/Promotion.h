#pragma once
#include "Events.h"
#include "Cargo.h"
#include "LinkedQueue.h"

class Promotion : public Events
{
private:

	int ExtraMoney;

public:
	Promotion(int id, const Time& event_time, Company* company, int extra_money)
		: Events(id, event_time, company),
		ExtraMoney(extra_money)
	{
	}

	void Execute()
	{
		Cargo* c;
		getCompany()->waitingNormalCargo.peek(c);
		if (c->getTypeOfCargo() == Normal_Cargo)
		{
			getCompany()->waitingVIPCargo.enqueue(c);
			getCompany()->waitingNormalCargo.dequeue(c);
		}
	}

	/*void Execute(LinkedQueue<Cargo*>* normal, LinkedQueue<Cargo*>* VIP)
	{
		Cargo* c;
		normal->peek(c);
		if (c->getTypeOfCargo() == Normal_Cargo)
		{
			VIP->enqueue(c);
			normal->dequeue(c);
		}
	}*/

	int getExtraMoney() const
	{
		return ExtraMoney;
	}

	void setExtraMoney(int extra_money)
	{
		ExtraMoney = extra_money;
	}

};