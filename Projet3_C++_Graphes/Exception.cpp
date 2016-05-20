/**************************************************
Titre: Classe pour la gestion des exceptions
***************************************************
Auteur	:	J.Bouchard, T.Lallement
Version	:	1.0
Date	:	04/04/2016
***************************************************
Corps de la Classe CException
Permet de cr�er des objets remont�s lors de
la lev�e d'exceptions.
**************************************************/

#include "Exception.h"

/**************************************************
* CException
* *************************************************
* Constructeur par d�faut permettant
* l'initialisation d'un objet
* *************************************************
* Entr�e:
* Pr�-condition:
* Sortie:
* Post-condition: Exception initialis�e � FAUX
* ************************************************/
CException::CException()
{
	uiEXCvaleur = 0;
}

/**************************************************
* CException
* *************************************************
* Constructeur avec l'initialisation de uiEXCvaleur
* *************************************************
* Entr�e: uiValeur, la valeur associ�e � l'exception
* Pr�-condition:
* Sortie:
* Post-condition: Exception initialis� � la valeur
* pass� en param�tre
* ************************************************/
CException::CException(unsigned int uiValeur)
{
	uiEXCvaleur = uiValeur;
}
