#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
bool verificationLettre(string lettre);
POINT verificationPosition (string motAdeviner, string lettre, POINT position);



int main()
{
    int lettreTrouve = 0;
    int nombreEssai = 10;
    string motAdeviner;
    string underscore;
    string enregistrement;
    bool correct = false;
    bool lettreOK = false;
    bool verificationstring = true;
    POINT position;

    // Entrer le mot

    cout << "Jeu du PENDU" <<endl <<endl;

    while(!correct)
    {
        cout << "Entrez le mot a deviner" <<endl;
        cin >> motAdeviner;
        correct = verificationLettre(motAdeviner);
    }
    correct = false;

    cout << motAdeviner << " Il y a " << motAdeviner.size() << " lettres dans votre mot :)" <<endl;
    Sleep(2000);
    system("cls");


   while(nombreEssai!=0 && lettreTrouve < motAdeviner.size())
   {
       string lettre;

        cout << "Le mot que tu dois deviner a " << motAdeviner.size()<<endl;
        for (unsigned int i = 0; i < motAdeviner.size(); i++)
        {
            underscore += '_';
            cout << underscore[i] << " ";
        }

        while(lettre.size()!= 1 || !correct || verificationstring == true)
        {
            cout << endl <<"Maintenant entrer une lettre pour trouver le mot mystere" <<endl;
            cin >> lettre;
            correct = verificationLettre(lettre);
            position = {0,0};
            position = verificationPosition(enregistrement,lettre,position);
            if(lettre.size()>1)
            {
                cout << "Mauvaise entree" <<endl;
            }
            else if(!correct)
            {
                cout << "Que des lettres" <<endl;
            }
            else
            {
                if(position.x <= enregistrement.size()&& position.y <= lettre.size())
                {
                    cout << "Cette lettre " <<lettre << " a deja ete utilise"  <<endl;
                    verificationstring = true;
                }
                else
                {
                    verificationstring = false;
                }


            }
        }

        enregistrement += lettre;
        position = {0,0};

        while(position.x <= motAdeviner.size())
        {
            position = verificationPosition(motAdeviner,lettre,position);

            if (position.x > motAdeviner.size() && position.y > lettre.size()&& !lettreOK)
            {
                nombreEssai-- ;
                cout << "MAUVAISE LETTRE" <<endl;
                cout << "Il te reste " << nombreEssai <<endl;

            }
            else if(position.x < motAdeviner.size() && position.y < lettre.size())
            {
                underscore[position.x] = lettre[position.y];
                lettreOK = true;
                lettreTrouve++;
            }
            position.x++;


        }
        lettreOK = false;
    }

    if (nombreEssai > 0)
    {
        cout << "Bravo, tu as gagne!!!" <<endl << endl;
    }
    else
    {
        cout << "Tu as perdu" <<endl;
    }
    cout << "Le mot etait "<< motAdeviner <<endl;



    system("pause");
    return 0;
}




bool verificationLettre(string lettre)
{
    for (int i =0; i < lettre.size(); i++)
    {
        if(!(((lettre[i] >= 'A' ) && (lettre[i] <= 'Z' )) || ((lettre[i] >= 'a' ) && (lettre[i] <= 'z')))) //si mon car est pas bon
        {
            return false;
        }

    }
    return true;
}



POINT verificationPosition (string motAdeviner, string lettre, POINT position)
{
    for(position.x;position.x<motAdeviner.size();position.x++)
    {
        for(position.y = 0;position.y<lettre.size();position.y++)
        {
            if (motAdeviner[position.x]== lettre[position.y] || motAdeviner[position.x]==lettre[position.y]+32 ||motAdeviner[position.x]==lettre[position.y]-32)
            {
                return position;
            }

        }

    }

    return position = {motAdeviner.size() + 1,lettre.size() + 1};
}


