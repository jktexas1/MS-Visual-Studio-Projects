// Programming Assignment 2
// Queue Simulation for XYZ Airlines
// Jacob Kapusta
// 2/25/2013

#include "Queue.h"
#include<iostream>
#include<string>
using namespace std;

class Simulator
{
private:
	DynIntQueue FrequentFlyer;
	DynIntQueue RegularPassenger;
	int FFAPH; //Frequent flyer arrivals per hour
	int RPAPH; //Regular passenger arrivals per hour
	int MAX_FREQUENT_FLYERS; //Max frequent flyers served before regular passengers
	int MAX_ServiceTime_Min; //Max service time in minutes
	int simulation_time; //Time interval to simulate
	string display;
	//int clock;

	int customerNo;

public:
	Simulator(int F, int R, int MFF, int MSM, int ST, string D)
	{
		FFAPH = F;
		RPAPH = R;
		MAX_FREQUENT_FLYERS = MFF;
		simulation_time = ST;
		MAX_ServiceTime_Min = MSM;
		display = D;
		customerNo = 0;
	}
	
	void frequentFlyerArrival()
	{
		FrequentFlyer.UCenqueue(customerNo);
		customerNo++;
	}
	void regularPassengerArrival()
	{
		RegularPassenger.UCenqueue(customerNo);
		customerNo++;
	}

	void serveFrequentFlyer()
	{
		int one; 
		FrequentFlyer.UCdequeue(one);
	}
	void serveRegularPassenger()
	{
		int one;
		RegularPassenger.UCdequeue(one);
	}
	int getFFAPH()
	{
		return FFAPH;
	}
	int getRPAPH()
	{
		return RPAPH;
	}
	int getMAX_FREQUENT_FLYERS()
	{
		return MAX_FREQUENT_FLYERS;
	}
	int getSimulationTime()
	{
		return simulation_time;
	}
	string getDisplay()
	{
		return display;
	}
	int getMaxServiceTime()
	{
		return MAX_ServiceTime_Min;
	}
	int getCustomerNo()
	{
		return customerNo;
	}
	void simulate()
	{
		bool flagServiceTimeFF = false; //finds out when frequent flyers start waiting
		bool flagServiceTimeRP = false; //finds out when regular flyers start waiting
		int actualTimeSpentWaitingFF = 0; //counts time spent waiting in frequent flyer queue
		int actualTimeSpentWaitingRP = 0; //counts time spent waiting in regular passenger queue
		bool inService = false; //tracks whether a passenger is being served or not
		int Reg_Person_Rate = 60/getRPAPH(); //reg person rate
		int Freq_Person_Rate = 60/getFFAPH(); //freq flyer rate
		int Freq_Persons_Served = 0; //tracks frequent flyers served
		int Reg_Persons_Served = 0; //tracks regular passengers served
		int regClock = 0; //tracks when to enqueue potential regular passenger
		int freqClock = 0; //tracks when to enqueue potential frequent flyer
		int timeServed = getMaxServiceTime(); //constant service time per passenger
		int frequentFlyersServed = 0; //tracks number of frequent flyers served
		int regularPassengersServed = 0; //tracks number of regular passengers served
		int tracker = 0; //tracks frequent flyers served for before regular passenger service
		int trackerTimeServed = 0; //tracks amount of time spent serving a passenger

		cout << "Expected number of frequent flyer arrivals per hour: " << getFFAPH() << endl;
		cout << "Expected number of regular passenger arrivals per hour: " << getRPAPH() << endl;
		cout << "Enter the maximum number of frequent flyers\n";
		cout << "served between regular passengers: " << getMAX_FREQUENT_FLYERS() << endl;
		cout << "Enter the maximum service time in minutes: " << getMaxServiceTime() << endl;
		cout << "Enter the total simulation time in minutes: " << getSimulationTime() << endl;
		cout << "Display minute-by-minute trace of simulation (Y or N): " << getDisplay() << endl;

		for(int i = 0; i < getSimulationTime(); i++)
		{
			//Both queues empty
			if(FrequentFlyer.UCisEmpty() && RegularPassenger.UCisEmpty())
			{
				cout << "Time Unit: " << i << " -Both queues are empty.\n";
			}
			//Enqueue regular passenger
			if(regClock == Reg_Person_Rate)
			{
				cout << "Time Unit: " << i << " -Regular Passenger Queue gained one person with stamp: " << getCustomerNo() << endl;
				regularPassengerArrival();
				regClock = 0;
				flagServiceTimeRP = true;
			}
			//Enqueue frequent flyer
			if(freqClock == Freq_Person_Rate)
			{
				cout << "Time Unit: " << i << " -Frequent Flyer Queue gained one person with stamp: " << getCustomerNo() << endl;
				frequentFlyerArrival();
				freqClock = 0;
				flagServiceTimeFF = true;
			}
			//Serve regular passenger if no frequent flyers and noone being serviced
			if(FrequentFlyer.UCisEmpty() && !RegularPassenger.UCisEmpty() && (inService == false))
			{
				cout << "Time Unit: " << i << " -Regular Passenger with stamp: " << RegularPassenger.UCPeek() << " is being served.\n";
				serveRegularPassenger();
				regularPassengersServed++;
				inService = true;
			}
			//Serve regular passenger or Frequent flyer depending on FFs served if both queues occupied
			if(!FrequentFlyer.UCisEmpty() && !RegularPassenger.UCisEmpty() && inService == false)
			{
				if(tracker < getMAX_FREQUENT_FLYERS())
				{
					cout << "Time Unit: " << i << " -Frequent Flyer with stamp: " << FrequentFlyer.UCPeek() << " is being served.\n";
					serveFrequentFlyer();
					frequentFlyersServed++;
					tracker++;
					inService = true;
					trackerTimeServed = 0;
				}
				if(tracker == getMAX_FREQUENT_FLYERS())
				{
					cout << "Time Unit: " << i << " -Regular Passenger with stamp: " << RegularPassenger.UCPeek() << " is being served.\n";
					serveRegularPassenger();
					regularPassengersServed++;
					tracker = 0;
					inService = true;
				}
			}
			
			
			if(trackerTimeServed == getMaxServiceTime()) inService = false;
			if(inService == false) trackerTimeServed = 0;
			if(inService == true) trackerTimeServed++;
			if(flagServiceTimeRP == true) actualTimeSpentWaitingRP++;
			if(flagServiceTimeFF == true) actualTimeSpentWaitingFF++;
			regClock++;
			freqClock++;
		}
		double RPwait = actualTimeSpentWaitingRP/regularPassengersServed; //calculates avg RP wait time
		double FFwait = actualTimeSpentWaitingFF/frequentFlyersServed; //calculates avg FF wait time

		cout << "Number of regular passengers served was: " << regularPassengersServed << endl;
		cout << " with an average wait time of: " << RPwait << endl;
		cout << "Number of frequent flyers served was: " << frequentFlyersServed << endl;
		cout << " with an average wait time of: " << FFwait << endl;
		cout << "Passengers in frequent flyer queue: " << FrequentFlyer.UCgetSize() << endl;
		cout << "Passengers in regular passenger queue: " << RegularPassenger.UCgetSize() << endl;
	}
};
