/**************************************************
Titre: Classe pour la gestion des exceptions
***************************************************
Auteur	:	J.Bouchard, T.Lallement
Version	:	1.0
Date	:	04/04/2016
***************************************************
Interface de la Classe CException
Permet de créer des objets remontés lors de
la levée d'exceptions.
**************************************************/

#ifndef Exception_H
#define Exception_H

class CException
{
//Attribut
private:

	unsigned int uiEXCvaleur; 
	//Contient la valeur de l'exception, FAUX par defaut

//Constructeurs et destructeur
public:

/**************************************************
* CException
* *************************************************
* Constructeur par défaut permettant
* l'initialisation d'un objet
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : Exception initialisé à FAUX
* ************************************************/
	CException();

/**************************************************
* CException
* *************************************************
* Constructeur avec l'initialisation de uiEXCvaleur
* *************************************************
* Entrée: uiVleur, la valeur associée à l'exception
* Pré-condition :
* Sortie :
* Post-condition : Exception initialisé à la valeur
* passé en paramètre
* ************************************************/
	CException(unsigned int uiValeur);

/**************************************************
* ~CException
* *************************************************
* Destructeur de la classe
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : Exception détruite
* ************************************************/
	~CException() {}

//Methode
public :

/**************************************************
* EXCmodifier_valeur
* *************************************************
* Modifier valeur de l'exception
* *************************************************
* Entrée: uiValeur, la valeur à affecter
* Pré-condition :
* Sortie :
* Post-condition : valeur de l'exception égale a 
* la valeur du paramètre 
* ************************************************/
	void EXCmodifier_valeur(unsigned int uiValeur);

/**************************************************
* EXClire_valeur
* *************************************************
* Permet de lire la valeur de l'exception
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : la valeur de l'exception
* Post-condition : la valeur de l'exception
* est retournée
* ************************************************/
	unsigned int EXClire_valeur();

};



/**************************************************
* EXCmodifier_valeur
* *************************************************
* Modifier valeur de l'exception
* *************************************************
* Entrée: uiValeur, la valeur à affecter
* Pré-condition :
* Sortie :
* Post-condition : valeur de l'exception égale a 
* la valeur du paramètre 
* ************************************************/
inline void CException::EXCmodifier_valeur(unsigned int uiValeur)
{
	uiEXCvaleur = uiValeur;
}

/**************************************************
* EXClire_valeur
* *************************************************
* Permet de lire la valeur de l'exception
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : la valeur de l'exception
* Post-condition : la valeur de l'exception
* est retournée
* ************************************************/
inline unsigned int CException::EXClire_valeur()
{
	return uiEXCvaleur;
}

#endif