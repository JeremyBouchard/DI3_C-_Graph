/**************************************************
Titre: Classe pour la gestion des exceptions
***************************************************
Auteur	:	J.Bouchard, T.Lallement
Version	:	1.0
Date	:	04/04/2016
***************************************************
Corps de la Classe CException
Permet de créer des objets remontés lors de
la levée d'exceptions.
**************************************************/

#include "Exception.h"

/**************************************************
* CException
* *************************************************
* Constructeur par défaut permettant
* l'initialisation d'un objet
* *************************************************
* Entrée:
* Pré-condition:
* Sortie:
* Post-condition: Exception initialisée à FAUX
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
* Entrée: uiValeur, la valeur associée à l'exception
* Pré-condition:
* Sortie:
* Post-condition: Exception initialisé à la valeur
* passé en paramètre
* ************************************************/
CException::CException(unsigned int uiValeur)
{
	uiEXCvaleur = uiValeur;
}
