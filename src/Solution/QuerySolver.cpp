#include "QuerySolver.h"

using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver() 
{
  server = Server::GetInstance();
}

/* NU MODIFICATI */ 
QuerySolver::~QuerySolver()
{
  if (server != nullptr) 
  {
    server = nullptr;
  }
}

list<Product*> QuerySolver::Query_3a()
{
   list<Product*> esspresso_redus;

    for(    list<Product*>::iterator aux = server->getProductsList().begin() ; aux != server->getProductsList().end() ; aux++)
      {
          if((*aux)->getCategory() == "espressor" && (*aux)->getProductType() == "DiscountedProduct")

                      esspresso_redus.push_back(*aux);
        }

    return esspresso_redus;

}

list<User*> QuerySolver::Query_3b()
{
  list<User*> User_transport_redus;

    for(    list<User*>::iterator aux = server->getUsersList().begin() ; aux != server->getUsersList().end() ; aux++)
      {
          if((*aux)->getTransportCost() < 11.5 && (*aux)->getUserType() == "BasicUser")

                      User_transport_redus.push_back(*aux);
        }

    return User_transport_redus;
}

list<Product*> QuerySolver::Query_3c()
{
  list<Product*> produse;

    for(    list<Product*>::iterator aux = server->getProductsList().begin() ; aux != server->getProductsList().end() ; ++aux)
      {
 

      if((*aux)->getProductType() == "ResealedProduct")
        {
           ReturnedProduct  *rea_prod  = new(ReturnedProduct);
        
        rea_prod = dynamic_cast<ResealedProduct*>(*aux);

          if( rea_prod->getReason() == "lipsa_accesorii" )
                      produse.push_back(rea_prod);        
        }
        }

    produse.sort([](Product *A , Product *B) {
      
      NonFoodProduct *aux_non_foodA = new(NonFoodProduct);
      NonFoodProduct *aux_non_foodB = new(NonFoodProduct);

      aux_non_foodA = dynamic_cast<NonFoodProduct*>(A);

      aux_non_foodB = dynamic_cast<NonFoodProduct*>(B);

      return aux_non_foodA->getPrice() < aux_non_foodB->getPrice();});

    return produse;

}

list<Product*> QuerySolver::Query_3d()
{
  list<Product*> produse;

      for( list<Product*>::iterator aux = server->getProductsList().begin() ; aux != server->getProductsList().end() ; aux++)
      { 
        if( (*aux)->getProductType() == "FoodProduct")
                    produse.push_back(*aux);        
                        
      }

    produse.sort([](Product *A , Product *B) {
      
      FoodProduct *aux_foodA = new(FoodProduct);
      FoodProduct *aux_foodB = new(FoodProduct);

      aux_foodA = dynamic_cast<FoodProduct*>(A);

      aux_foodB = dynamic_cast<FoodProduct*>(B);

      return aux_foodA->getLeiPerKg() < aux_foodB->getLeiPerKg();});
    
    produse.sort([](Product *A , Product *B) {
      
      FoodProduct *aux_foodA = new(FoodProduct);
      FoodProduct *aux_foodB = new(FoodProduct);

      aux_foodA = dynamic_cast<FoodProduct*>(A);

      aux_foodB = dynamic_cast<FoodProduct*>(B);

      return aux_foodA->getCountryOfOrigin() < aux_foodB->getCountryOfOrigin();});

      produse.sort([](Product *A , Product *B) {
      
      FoodProduct *aux_foodA = new(FoodProduct);
      FoodProduct *aux_foodB = new(FoodProduct);

      aux_foodA = dynamic_cast<FoodProduct*>(A);

      aux_foodB = dynamic_cast<FoodProduct*>(B);

      return aux_foodA->getName() < aux_foodB->getName();});


    return produse;

}

list<User*> QuerySolver::Query_3e()
{
  list<User*> useri;

  list<User*> Useri_multi_la_casa;

  for( list<User*>::iterator aux = server->getUsersList().begin() ; aux != server->getUsersList().end() ; aux++)
      {
         useri.push_front(*aux);                          
      }


  useri.sort([] (User* A , User* B) {return A->getDeliveryData().getCounty() < B->getDeliveryData().getCounty();});

    string super_judet = (*useri.begin())->getDeliveryData().getCounty();
      string curent_judet = super_judet;

    int super_nr = 0;
      int nr_curent  = 0;


  for(list<User*>::iterator aux = useri.begin() ; aux != useri.end() ; aux++)  
      {
          if((*aux)->getDeliveryData().getCounty() != curent_judet)
                {
                  nr_curent = 0;

                  curent_judet = (*aux)->getDeliveryData().getCounty();
                }

              nr_curent++;

        if(nr_curent > super_nr )
              {
                  super_nr = nr_curent;

                  super_judet = (*aux)->getDeliveryData().getCounty();

              }
      }

    for(list<User*>::iterator aux = useri.begin() ; aux != useri.end() ; aux++)  
      {
          if((*aux)->getDeliveryData().getCounty() == super_judet)
                  Useri_multi_la_casa.push_back(*aux);

      }

      list<User*> Useri_multi_la_casa_fin;

      for(list<User*>::iterator aux = Useri_multi_la_casa.begin() ; aux != Useri_multi_la_casa.end() ; aux++)
        {
            if((*aux)->getBillingData().getBlock() == "-")
                Useri_multi_la_casa_fin.push_back(*aux);


        }

        Useri_multi_la_casa_fin.sort([] (User* A , User* B) {return A->getUserID() < B->getUserID();});


return Useri_multi_la_casa_fin;
}

list<User*> QuerySolver::Query_3f()
{      

  list<User*> Users;
  list<User*> Users_final;

    //iau lista de produse(logic numai telefoane si imprimante)
        list<Product*> produse;

         for( list<Product*>::iterator aux =  server->getProductsList().begin() ; aux != server->getProductsList().end() ; aux++)
      { 
            if((*aux)->getCategory() == "telefon" || (*aux)->getCategory() == "imprimanta")
                    produse.push_back(*aux);                          
      }

  for(list<User*>::iterator aux = server->getUsersList().begin() ; aux != server->getUsersList().end() ; aux++)
       {
          if((*aux)->getUserType() == "PremiumUser")
              Users.push_back(*aux);
       }
       

      for(list<User*>::iterator aux = Users.begin() ; aux != Users.end() ; aux++)
       {
            bool tester = false;

          map<int , int> aux_discount;

            PremiumUser *aux_sec = new(PremiumUser);
            
            aux_sec = dynamic_cast<PremiumUser*>(*aux);

            //Verific daca sunt telefoane sau imprimante

            for(map<int , int>::iterator aux_map = aux_sec->getDiscounts().begin() ; aux_map != aux_sec->getDiscounts().end() ; aux_map++)
                  {
                      for(list<Product*>::iterator aux_mom = produse.begin() ; aux_mom != produse.end() ; aux_mom++)
                        {
                            if((*aux_mom)->getId() == aux_map->first)
                                  tester = true;

                        }

                  }
            if(tester == true)
              Users_final.push_back(*aux);

       }


  return Users_final;
}
