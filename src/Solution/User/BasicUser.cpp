#include "BasicUser.h"

using namespace std;

BasicUser::BasicUser()
{
	
}

BasicUser::BasicUser(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf, const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl, int id, const string &nume, const string &prenume, const string &email, float costTransport) : User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
{
	this->costTransport = costTransport;
}

BasicUser::BasicUser(const BasicUser &unp) : User(unp)
{	
	billingData = unp.billingData;

	deliveryData = unp.deliveryData;

	lastName = unp.lastName;
		
	firstName = unp.firstName;
	 	
	email = unp.email;
		
	UserID = unp.UserID;

	costTransport = unp.costTransport;
}

BasicUser &BasicUser::operator=(const BasicUser &unp)
{
	billingData = unp.billingData;

	deliveryData = unp.deliveryData;

	lastName = unp.lastName;
		
	firstName = unp.firstName;
	 	
	email = unp.email;
		
	UserID = unp.UserID;

	costTransport = unp.costTransport;

	return *this;
}

void BasicUser::setTransportCost(int cost)
{
	costTransport = cost;
}

float BasicUser::getTransportCost()
{
	return costTransport;
}

void BasicUser::displayUser()
{
	throw("undefined");
}

string BasicUser::getUserType()
{
	return "BasicUser";
}

json BasicUser::toJSON()
{
	return json(*this);
}
