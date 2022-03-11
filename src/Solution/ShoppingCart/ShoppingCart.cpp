#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->payMethod = "-";
}

ShoppingCart::ShoppingCart(const string &payMethod)
{
	this->payMethod = payMethod;
}

string &ShoppingCart::getPayMethod()
{
	return payMethod;
}

void ShoppingCart::setPayMethod(const string &payMethod)
{
	this->payMethod = payMethod;
}

void ShoppingCart::addProduct(int id, int quantity)
{
	pair<int , int> aux(id , quantity);

	shoppingCart.insert(aux);
}

void ShoppingCart::raiseQuantity(int id, int quantity)
{


	if(shoppingCart.find(id) != shoppingCart.end())
		shoppingCart.find(id)->second = shoppingCart.find(id)->second + quantity;
}

void ShoppingCart::lowerQuantity(int id, int quantity)
{

	if(shoppingCart.find(id) != shoppingCart.end())
		shoppingCart.find(id)->second = shoppingCart.find(id)->second - quantity;
		
}

int ShoppingCart::getQuantity(int productID)
{
	

	if(shoppingCart.find(productID) != shoppingCart.end())
		return shoppingCart.find(productID)->second;

	else return -1;
}

void ShoppingCart::deleteProduct(int productID)
{
	shoppingCart.erase(shoppingCart.find(productID));

}

map<int, int> &ShoppingCart::getShoppingCart()
{
	return shoppingCart;
}

void ShoppingCart::displayShoppingCart()
{
		 if (this->shoppingCart.empty()) cout << "Cosul este gol"; 
}

json ShoppingCart::toJSON()
{
  return json(*this);
}