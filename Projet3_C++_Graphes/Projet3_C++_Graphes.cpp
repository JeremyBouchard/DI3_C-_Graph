// Projet3_C++_Graphes.cpp : définit le point d'entrée pour l'application console.


#include "Projet_C++_Graphes.h"


int main(int argc, char * argv[])
{
	std::cout <<"----------Debut execution---------\n" << std::endl;
	if (argc > 2){

		CChargeurGraphe chargeur;
		try{

			CGraphe* GRASaisie = new CGraphe(*chargeur.CGRLireFichier(argv[1]));
			unsigned int uiBoucle;
			CTraitementGraphe TGRTraitement;
			CSommet ** ppSOMEntrée = GRASaisie->GRALireTabSommet();

			std::cout << "Graphe en entree :" << std::endl;
			GRASaisie->GRAAfficher();

			float * pfBellmanResult = TGRTraitement.TGRBellmanFord(*GRASaisie, std::atoi(argv[2]));
			std::cout<<"Bellman-Ford avec le sommet source numero "<<argv[2]<<" :"<<std::endl;
			for (uiBoucle=0 ; uiBoucle < GRASaisie->GRALireNbSommet() ; uiBoucle++){
				std::cout<<"Disatnce jusqu'au sommet "<<ppSOMEntrée[uiBoucle]->SOMLireNumero() << " vaut " << pfBellmanResult[uiBoucle]<<std::endl;

			}

		}catch(CException e){
			switch(e.EXClire_valeur())
			{
			case ERREUR_ALLOCATION_MEMOIRE_SIMPLE:
				std::cerr << "Une allocation mémoire (malloc) a echoue" << std::endl;
				break;

			case ERREUR_ALLOCATION_MEMOIRE_OBJET:
				std::cerr << "Une allocation mémoire pour un objet (new) a echoue" << std::endl;
				break;

			case SOMMET_DEJA_EXISTANT:
				std::cerr << "Ce sommet existe deja" << std::endl;
				break;

			case SOMMET_INEXISTANT:
				std::cerr << "Impossible de trouver le sommet" << std::endl;
				break;

			case ERREUR_OUVERTURE_FICHIER:
				std::cerr << "Impossible d'ouvrir le fichier" << std::endl;
				break;

			case FICHIER_NON_OUVERT:
				std::cerr << "Parseur : Aucun fichier n'est ouvert" << std::endl;
				break;

			case ARC_DEJA_EXISTANT:
				std::cerr << "Cette arc existe deja" << std::endl;
				break;

			case ARC_INEXISTANT:
				std::cerr << "Impossible de trouver l'arc" << std::endl;
				break;

			case CYCLE_ABSORBANT:
				std::cerr << "Bellman-Ford : Cycle Absorbant -> Pas de solution" << std::endl;
				break;

			default:
				std::cerr << "Erreur inconnue" <<  std::endl;
				break;
			}
		}

	}else{
		std::cerr<< "\n Veuillez fournir un fichier en parametre puis un numero de sommet source\n" << std::endl ;
	}

	std::cout <<std::endl<<"----------Fin execution---------\n\n" << std::endl;


	return 0;
}

