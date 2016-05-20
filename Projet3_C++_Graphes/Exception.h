/**************************************************
Titre: Classe pour la gestion des exceptions
***************************************************
Auteur	:	J.Bouchard, T.Lallement
Version	:	1.0
Date	:	04/04/2016
***************************************************
Interface de la Classe CException
Permet de cr�er des objets remont�s lors de
la lev�e d'exceptions.
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
* Constructeur par d�faut permettant
* l'initialisation d'un objet
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : Exception initialis� � FAUX
* ************************************************/
	CException();

/**************************************************
* CException
* *************************************************
* Constructeur avec l'initialisation de uiEXCvaleur
* *************************************************
* Entr�e: uiVleur, la valeur associ�e � l'exception
* Pr�-condition :
* Sortie :
* Post-condition : Exception initialis� � la valeur
* pass� en param�tre
* ************************************************/
	CException(unsigned int uiValeur);

/**************************************************
* ~CException
* *************************************************
* Destructeur de la classe
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : Exception d�truite
* ************************************************/
	~CException() {}

//Methode
public :

/**************************************************
* EXCmodifier_valeur
* *************************************************
* Modifier valeur de l'exception
* *************************************************
* Entr�e: uiValeur, la valeur � affecter
* Pr�-condition :
* Sortie :
* Post-condition : valeur de l'exception �gale a 
* la valeur du param�tre 
* ************************************************/
	void EXCmodifier_valeur(unsigned int uiValeur);

/**************************************************
* EXClire_valeur
* *************************************************
* Permet de lire la valeur de l'exception
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie : la valeur de l'exception
* Post-condition : la valeur de l'exception
* est retourn�e
* ************************************************/
	unsigned int EXClire_valeur();

};



/**************************************************
* EXCmodifier_valeur
* *************************************************
* Modifier valeur de l'exception
* *************************************************
* Entr�e: uiValeur, la valeur � affecter
* Pr�-condition :
* Sortie :
* Post-condition : valeur de l'exception �gale a 
* la valeur du param�tre 
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
* Entr�e:
* Pr�-condition :
* Sortie : la valeur de l'exception
* Post-condition : la valeur de l'exception
* est retourn�e
* ************************************************/
inline unsigned int CException::EXClire_valeur()
{
	return uiEXCvaleur;
}

#endif