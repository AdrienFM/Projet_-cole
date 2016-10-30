#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>


void outputArray(int tableau[], int tailleTableau)
{
        for (int i = 0; i < tailleTableau; i++)
            std::cout << tableau[i] << std::endl;
}


void fillArrayWithRandom(int tableau[], int tailleTableau, int minTableau, int maxTableau)
{
    srand(time(0));
    for (int i = 0; i < tailleTableau; i++)
    {
        tableau[i] = rand() % 5000 + 1;
    }
}

void fillArrayWithRandom(std::vector<int>&tableau, int tailleTableau, int minTableau, int maxTableau)
{
    int temp = 0;

    for (int i =0; i < tailleTableau; i++)
    {
         temp = rand() % 5000 + 1;
         tableau.push_back(temp);
    }

}

bool searchArrayForNumber(int tableau[],int taille, int number)
{
    for(int i = 0; i < taille; i++)
    {
        if (tableau[i] == number)
        {
            return true;
        }
    }

    return false;
}

void sortArray( int tab[], int tab_size, bool croissant)
{
  int i=0;
  int tmp=0;
  int j=0;

  for(i = 0; i < tab_size; i++)
    {
      for(j = i+1; j < tab_size; j++)
        { if (croissant)
            {
                if(tab[j] < tab[i])
                {
                  tmp = tab[i];
                  tab[i] = tab[j];
                  tab[j] = tmp;
                }

            }
            else
            {
                if(tab[j] > tab[i])
                {
                  tmp = tab[i];
                  tab[i] = tab[j];
                  tab[j] = tmp;
                }
            }
        }
    }
}

void sortArray(std::vector <int> &tableau, int tableau_size)
{
  int i=0;
  int tmp=0;
  int j=0;

  for(i = 0; i < tableau_size; i++)
    {
      for(j = i+1; j < tableau_size; j++)
      {
                if(tableau[j] < tableau[i])
                {
                  tmp = tableau[i];
                  tableau[i] = tableau[j];
                  tableau[j] = tmp;
                }

        }
    }
}

void fusionArray (std::vector<int> tableau1, std::vector<int> tableau2,std::vector<int>tableauFusion, bool fusion_choix)
{
    unsigned int tailleFusion =0;
    bool pasTrie =false;

    tailleFusion = tableau1.size() + tableau2.size();

    for (int i = 1; i < tableau1.size();i++)
    {
        if (tableau1[0]>tableau1[i])
        {
            pasTrie=true; // true pas trié
        }
    }
    for (int i = 1; i < tableau2.size();i++)
    {
        if (tableau2[0]>tableau2[i])
        {
            pasTrie=true;
        }
    }

    for (unsigned int i =0; i != tailleFusion; i++)
    {
        if(i<tableau1.size())
            tableauFusion.push_back(tableau1[i]);
        else
            tableauFusion.push_back(tableau2[i-tableau1.size()]);
    }

    if(!pasTrie)
        sortArray(tableauFusion,tableauFusion.size());

    for (int i =0;i < tableauFusion.size();i++)
    {
        std :: cout << i+1 << ") " << tableauFusion[i] << std::endl;
    }


}

