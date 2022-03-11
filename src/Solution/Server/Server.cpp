#include "Server.h"

using namespace std;

/* NU MODIFICATI */
Server::Server(){}

/* NU MODIFICATI */
Server *Server::GetInstance()
{
	if (!instance)
	{
		instance = new Server; 
	}

	return instance;
}

/* NU MODIFICATI */
Server::~Server()
{
	if (instance != NULL)
		instance = NULL;

	if (!__UserID__ProductsCart__.empty())
		__UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__()
{
		for(list<User *>::iterator aux_user = usr.begin() ; aux_user != usr.end() ; aux_user++)
			{ShoppingCart *aux_cart;
				
						aux_cart = new ShoppingCart;

				int ID = (*aux_user)->getUserID();

				pair<int , ShoppingCart*> aux(ID , aux_cart);

				__UserID__ProductsCart__.insert(aux);
				
			}

}

list<Product *> &Server::getProductsList()
{
	return prod;
}

list<User *> &Server::getUsersList()
{
	return usr;
}

map<int, ShoppingCart *> Server::get__UserID__ProductsCart__()
{
	return __UserID__ProductsCart__;
}

bool Server::requestAddProduct(int userID, int productID, int quantity)
{
	/////Direct afara nu stam la discutii

	if(quantity <= 0)
		return false;

	bool test = false;
	
	for(list<Product*>::iterator aux = prod.begin() ; aux != prod.end() ; aux++)
		{
			if((*aux)->getId() == productID && (*aux)->checkQuantity(quantity) )
				test = true;		
		}

	if(test == false)
			return false;

	test = false;

	for(list<User*>::iterator aux = usr.begin() ; aux != usr.end() ; aux++)
		{
			if((*aux)->getUserID() == userID)
				test = true;		
		}

	if(test == false)
			return false;

			///////Finish

	ShoppingCart* aux_cart;

		aux_cart = new(ShoppingCart);

		//Il cautam pe nea User si ii furam cosu

	aux_cart = (__UserID__ProductsCart__).find(userID)->second;
	
		map<int , int> aux_doar_carut;

		aux_doar_carut = aux_cart->getShoppingCart();

		//ne uitam in cos si vedem daca are produsul pe care il vrea


		if(aux_doar_carut.find(productID) == aux_doar_carut.end() )
			{
				aux_cart->addProduct(productID , quantity);

				//tai din el ....ca mna am luat de pe raft

				for(list<Product*>::iterator aux = prod.begin() ; aux != prod.end() ; aux++)
						{
							if((*aux)->getId() == productID)
								(*aux)->decreaseQuantity(quantity);		
						}

			}

		else
			{
					aux_cart->raiseQuantity(productID , quantity);

					//tai din el ....ca mna am luat de pe raft

				for(list<Product*>::iterator aux = prod.begin() ; aux != prod.end() ; aux++)
						{
							if((*aux)->getId() == productID)
								(*aux)->decreaseQuantity(quantity);		
						}

			}

		
	return true;
}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
	/////Direct afara nu stam la discutii

	if(quantity <= 0)
		return false;

	bool test = false;
	
	for(list<Product*>::iterator aux = prod.begin() ; aux != prod.end() ; aux++)
		{
			if((*aux)->getId() == productID)
				test = true;		
		}

	if(test == false)
			return false;

	test = false;

	for(list<User*>::iterator aux = usr.begin() ; aux != usr.end() ; aux++)
		{
			if((*aux)->getUserID() == userID)
				test = true;		
		}

	if(test == false)
			return false;

			///////Finish

		ShoppingCart* aux_cart;

		aux_cart = new(ShoppingCart);

		//Il cautam pe nea User si ii furam cosu

	aux_cart = (__UserID__ProductsCart__).find(userID)->second;
	
		map<int , int> aux_doar_carut;

		aux_doar_carut = aux_cart->getShoppingCart();

		//ne uitam in cos si vedem daca are produsul pe care il vrea


		if(aux_doar_carut.find(productID) == aux_doar_carut.end() )
			{
				return false;
			}

		else if(aux_doar_carut.find(productID) != aux_doar_carut.end() && aux_doar_carut.find(productID)->second > quantity)
			{
					aux_cart->lowerQuantity(productID , quantity);

					//tai din el ....ca mna am luat de pe raft

				for(list<Product*>::iterator aux = prod.begin() ; aux != prod.end() ; aux++)
						{
							if((*aux)->getId() == productID)
								(*aux)->increaseQuantity(quantity);		
						}

			}

		else if(aux_doar_carut.find(productID) != aux_doar_carut.end() && aux_doar_carut.find(productID)->second == quantity)
			{
					aux_cart->deleteProduct(productID);

					//tai din el ....ca mna am luat de pe raft

				for(list<Product*>::iterator aux = prod.begin() ; aux != prod.end() ; aux++)
						{
							if((*aux)->getId() == productID)
								(*aux)->increaseQuantity(quantity);		
						}

			}		
		
		else
		{
			return false;
		}
		
		
	return true;

		
}

/* NU MODIFICATI */
void Server::populateProducts(const json &input)
{
	prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

/* NU MODIFICATI */
void Server::populateUsers(const json &input)
{
	usr = ObjectFactory::getUserList(input["useri"]);
}