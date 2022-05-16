#pragma once
#include "Time.h"
#include "Cargo.h"
#include "LinkedQueue.h"

class Company
{
private:
	int VIPpriority;
	Time deliveryInterval;
	int furthestCargoDistance;
	Time cargoWaitTime;
	Time cargoDeliveryTime;
	int truckUtilization;

public:


	LinkedQueue<Cargo*> waitingNormalCargo = LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> waitingSpecialCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> waitingVIPCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> deliveredNormalCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> deliveredSpecialCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> deliveredVIPCargo= LinkedQueue<Cargo*>();
	LinkedQueue<Cargo*> cancelledCargo= LinkedQueue<Cargo*>();
	
	Time calculateDeliveryInterval()
	{
		//furthest cargo / truck speed + Truck capacity*load unload time + return time
	}
	int calculateFurthestCargo()
	{
		//traverse the queue comparing cargo.distance and returning a furthest distance
	}
	Time calculateWaitTime()
	{
		//Preparation time is the time the cargo is created using the preparation event
		//Move time is the time the truck starts to move which is in phase 2
	}
	Time calculateCargoDeliveryTime()
	{
		// move time + cargo distance/truck speed + cargo load and unload time
	}
	int calculateTruckUtilization()
	{
		//total cargos delivered/(truck capacity*total delivery journeys) * (total truck active time/total sim time)
	}
	int calculateVIPpriority()
	{
		//VIPpriority = (max distance / cargo distance) * 100 + (2 * cost / max cost) * 100 + (min prep time / prep time) * 100
	}
	/*void moveToDelivered()
	{
		Cargo* c1;
		Cargo* c2;
		Cargo* c3;
		
		waitingNormalCargo.dequeue(c1);
		
		deliveredNormalCargo.enqueue(c1);

		waitingSpecialCargo.dequeue(c2);

		deliveredSpecialCargo.enqueue(c2);

		waitingVIPCargo.dequeue(c3);

		deliveredSpecialCargo.enqueue(c3);
	}*/
};
