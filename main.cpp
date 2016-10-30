#include <iostream>
#include "fonction_Tableau.h"

using namespace std;

int main()
{
    int tailleTableau1 = 0;
    int tailleTableau2 = 0;
    vector<int> tableau1(tailleTableau1);
    vector<int> tableau2(tailleTableau2);
    vector<int> tableauFusion;
    bool choix = false;

    cout << "Entrer la taille du tableau 1" <<endl;
    cin >> tailleTableau1;
    cout << "Entrer la taille du tableau 2" <<endl;
    cin >> tailleTableau2;
    cout << "Le voulez-vous croissant ou non? oui(1) non(0)" <<endl;
    cin >> choix;

    fillArrayWithRandom(tableau1,tailleTableau1, 1 , 500);
    fillArrayWithRandom(tableau2,tailleTableau2, 1 , 500);



    if (choix == 1)
    {
        sortArray(tableau1,tableau1.size());
        sortArray(tableau2,tableau2.size());
    }
 for(int i= 0; i != tableau1.size(); i++)
    {
        cout << tableau1[i] <<endl;
    }
    for(int i= 0; i != tableau2.size(); i++)
    {
        cout << tableau2[i] <<endl;
    }

    fusionArray(tableau1,tableau2,tableauFusion,choix);

    for(int i= 0; i != tableauFusion.size(); i++)
    {
        cout << tableauFusion[i] <<endl;
    }


    return 0;
}
