Cerinta:
https://ocw.cs.pub.ro/courses/poo-is/tema2

Siniuc_Robert-Valentin-321AA
    
    -Constructori/Destructor ==> 99% goale , considerand ca nu am vreun char nu prea am ce sa initializez sau sa sterg 
    
    -Constructori cu parametrii/operatori =  ===> parametru x = valoare y

    -Functii get ==> dau return la parametrul cerut (la functiile cu get_price_after_discount doar maiface calculul de aplicare de discount inainte)
    ///Functia get____type ==> returneaza numele clasei\\\


    -Functiile set ==> parametru = valoare 

    
                    
                                                    ___SHOPPING CART___

                -Add product ==> creeaza un pair <int  ,int> cu parametrii dati si il insereaza in mapa de produse
                
                -Raise/lower quantity ==> cauta produsul in map , iar dupa ce il gaseste ii creste valoarea in quantity (Functia presupune ca am testat deja existenta respectivei cantitati pe "raft"/in cos)

                -Delete product ==> cauta si sterge produsul
                
                                                   




                                                        ___SERVER___



                -Set set__UserID__ProductsCart__ ==> trece prin toti useri din usr si pt fiecare creeaza un pair cu idul lor si un nou shopping_cart si il introduce in mapa __UserID__ProductsCart__
                



                            -Request_add_prodct/delete_product 
                
                                    /- mai intai verifica existenta userului si a produsului , vede daca cantitatea produsului cerut este <= 0 deasemenea verifica daca are pe raft sau in cos cantitatea ceruta
                                    //- cautam userul si ii luam cosul de cumparaturi
                                    ///-cautam produsul in cos /- daca nu exista:
                                                                                     /->Pentru adaugare , introducem acest produs in cos 
                                                                                    //->Pentru scoatere , direct FAIL nu stam la discutii
                                                               
                                
                                                                //- daca exista:
                                                                                    /->Pentru adaugare , folosim functia raiseQuantity , ca sa ii crestem cantitatea in cos
                                                                                    //->Pentru scoatere , folosim functia lowerQuantity , ca sa ii scadem cantitatea in cos


                                  ////- daca realizarea actiunii a fost posibila crestem sau scadem cantitatea produsului in lista de produse



                                                         

                                                            ___3A___

                   -Parcurg lista de produse si verific fiecare produs daca este esspresor si daca este de tip discounted product 
                   -Daca ambele reguli se aplica il adauga intr o lista de Esspresoare cu discount 
                   -Returnez lista creata



                                                            ___3B___

                                                            
                   -Parcurg lista de useri si verific fiecare user daca are costul de transport mai mic de 11.5 LEI si daca este basic User
                   -Daca ambele reguli se aplica il adauga intr o lista de Useri cu sot transport redus 
                   -Returnez lista creata



                                                            ___3C___
                                                           
                   -Parcurg lista de produse si verific daca produsul este resigilat
                   -Daca este resigilat , atunci verific motivul de returnare (folosesc dynamic_cast pentru a pute utiliza functia getReason)
                   -Daca motivul este "lipsa acesorii" il adaug intr o lista de produse resigilate fara acesorii
                   -Sortez lista cu functia sort 
                   -Dau ca parametru functiei sort o functie ce compara pretul a doua produse 
                   -La final returnez lista creata                 



                                                            ___3D___
                    
                   -Iau lista de produse si imi fac o copie 
                   -Eu vreau ca produsele sa fie sortate dupa nume->tara->pret
                   -Asa ca eu sortez toata lista odata in sens invers pret->tara->nume (Astfel de exemplu cand ar venii vorba de doua produse din aceeasi tara ele sunt deja sortate dupa pret)
                   -Returnez lista de produse sortate
              Bonus-Nu plang dupa ce am incercat sa le sortez pe bucati si nu mai intelegeam nimic din cod ......macar am realizat ca nu e o metoda buna si ca acum imi merge :D 



                                                            ___3E___
                                                           
                   -Iau lista de useri si imi fac o copie
                   -Ii ordonez dupa numele judetului (Ca sa nu am nevoie de o lista de numar de useri/judet)
                   -Trec prin lista ordonata (tinand minte judetul cu cei mai multi useri si numarul lor) si la fiecare user cresc numarul  de useri dint judetul curent (Totodata verific cand dau de alt judet pentru a face o pauza 
                                                                                                                                                                                        si inainte sa il numar pe user realizez CHECKUL)
                   
                   -CHECKUL===>vad daca numarul de useri din judetul curent este mai mare decat SUPER_NR de useri din SUPER_JUDET->daca este atunci Super judetul devine judetul acela si copiez si noul numar de useri
                                                                                                                            ->in caz cuntrar ..... nu e un judet SUPER asa ca bum bum bum 3 de nu trecem mai departe , fara plans fara zbierat 
                   -Am gasit un judet nou deci numarul de useri din judetul curent revine la 0 si judetul curent se schimba
                   -La final raman cu Adevaratul SUPER_JUDET si cu SUPER_NR de useri 
                   -Imi iau intr o noua lista doar pe acesti useri DOAR DACA (pam pam pam castor uimit) stau la casa (verificare simpla prin functia get_delivery_data si functia get_block si verificam daca este "-")
                   -Noua lista o sortez dupa Id (functia sort cu parametru un return getid < getid)
                   -La final returnam lista finala





                                                            ___3F___                            

                   -Iau mai intai din  lista de produse toate imprimantele si telefoanele
                   -Iau apoi din lista de Useri pe cei care au tipul "PremiumUser" 
                   -Trec prin userii premium si verfic daca vreun cupon deal lor este pentru vreunul dintre produsele retinute:
                                                                                                                                ->Daca gasesc atunci copiezu userul intr-o lista finala
                                                                                                                                ->Daca nu atunci introducem un Gandalf.... you shall not pass si trecem mai departe
                   -La final returnez lista finala



                                                           ____LRU_CACHE___


                   -Trec prin lista requestsNo 
                   -Verific daca numarul este deja in lru:
                                                            ->Daca da atunci il stergem pe acela si il reinseram la inceput 
                                                            ->In caz contrar il introduc la inceput si atat
                   -(Folosesc insert(lru.begin() , aux)  pentru a introduce elementul nou la inceputul listei)
                   -Verific dupa fiecare adaugare daca marimea lui lru este mai mare decat capacitatea:
                                                                                                        ->In caz ca este sarit de capacitatea maxima sterg elementul de la coada
                                                                                                        ->Daca nu trec mai departe

                   -La sfarsit returnez Lru in forma lui finala




                                                            ____CONCLUZIE____

                     Din perspectiva mea tema a fost una folositoare , am inteles mai bine munca depusa in cadrul unui proiect si in ce consta aceasta.

		             Considerand ca nu am facut nimic special , imi vad implementarea ca fiind una basic .










                                    
                                          
