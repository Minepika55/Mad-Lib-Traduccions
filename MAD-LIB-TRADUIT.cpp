#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void mostra_vector(const vector<string>&);

string askText(string q);// String per preguntar text al jugador.
int askNumber(string q);// String per preguntar un numero al jugador.
void TellStory(string name, string noun, int number, string bodyPart, string verb);// Void on s'explica l'historia.
string idiomaactual = "CA";

int main()
{

    cout << "Benvingut a Mad Lib, un programa per crear la teva propia historia personalitzada." << endl;
    cout << "Quin idioma voldras? Pots triar un dels seguents:" << endl;// Demano al jugador quin idioma vol.

    ifstream fich("Traduccio.txt");//Obro el fitxer amb els idiomes.
    int NumIdiomes, NumParaules;
    fich >> NumIdiomes;
    fich >> NumParaules;

    vector <string> llengues;
    vector <string> frases;

    llengues.reserve(NumIdiomes);
    for (int i = 0; i < NumIdiomes; ++i)//Vaig llegint tots els idiomes del fitxer.
    {
        string valor;
        fich >> valor;
        llengues.push_back(valor);//Els guardo en un valor.
        
        for (int i = 0; i < NumParaules - 1; ++i)//Ara ho faig un segon cop per la resta d'idiomes.
        {
            string valor;
            fich >> valor;
            frases.push_back(valor);//Els guardo en un valor.
        }

    }
    mostra_vector(llengues);//Mostro per pantalla tots els idiomes a escollir,

    cin >> idiomaactual;//Guardo l'idioma que ha triat el jugador.

    ifstream fich2("Traduccio2.txt");//Obro el fitxer amb el salut del narrador amb les seves traducions corresponents.
    
    string salut;//Faig un string que guardara el salut en si.

    while (getline(fich2, salut)) {
        if (salut.find(idiomaactual) == 0) {
            cout << salut.substr(idiomaactual.length()) << endl;
            break;
        }
    }

    fich2.close();

    cout << "Avui presentem una historia d'accio, necessito unes quantes dades." << endl;

    // Faig preguntes a l'usuari.
    string name = askText("Donam un nom:");
    string noun = askText("Donam un nom en plural:");
    int number = askNumber("Donam un numero:");
    string bodyPart = askText("Digue'm una part del cos:");
    string verb = askText("Digue'm un verb:");

    TellStory(name, noun, number, bodyPart, verb);// Utilitzem les dades introduides per utilitzar l'historia.

    return 0;
}

// Aqui es demana i es guarden preguntes que demanain text.
string askText(string q)
{
    string response1;
    cout << q << endl << "Introdueix la teva resposta:";
    cin >> response1;
    return response1;
}

// Aqui es demana i es guarden preguntes que demanin numeros.
int askNumber(string q)
{
    int response2;
    cout << q << endl << "Introdueix el numero que vols:";
    cin >> response2;
    return response2;
}

void TellStory(string name, string noun, int number, string bodyPart, string verb)// Aqui s'explica l'historia.
{
    cout << "Benvingut, " << name << "." << endl;

    cout << name << ", aquesta sera la teva historia..." << endl;

    cout << "Fa milenis, les terres eren verdes i plenes de vida" << endl;

    cout << "Aquestes terres eren protegides per " << number << " guerrers" << endl;

    cout << "Liderats per la persona mes heroica de totes; " << name << endl;

    cout << "Pero aquesta pau va durar poc, el temps no es para per cap persona, ni per els mes grans herois" << endl;

    cout << "Un rei d'un regne proper va ser consumit per l'enveja i en la seva bojeria va comencar una gran guerra" << endl;

    cout << "Aquesta gran guerra va causar una gran escasetat de " << noun << endl;

    cout << "I la qualitat de vida dels dos regnes va disminuir considerablement" << endl;

    cout << "La guerra va durar decades amb mes de " << number << " mil morts i grans danys al ecosistema dels regnes" << endl;

    cout << "L'unic record que va quedar dels herois va ser una part del mes gran dels herois la qual va ser momificada" << endl;

    cout << "La gran reliquia " << bodyPart << " Ara es una gran reliquia i la llegenda diu que un dia l'heroi tornara a per ella i restaurara la pau als regnes" << endl;

    cout << "Mentres esperen la tornada de " << name << " els habitants " << verb << " en el seu honor inspirant a les noves generacions a creure en la llegenda." << endl;

    cout << "I aixi s'esperen, durant mes de " << number << " milions d'anys a que l'heroi torni, veient lentament com el mon s'esfondra." << endl;

    cout << "Els habitants sempre continuarant creient i " << verb << " fins que l'heroi retorni a buscar el que es seu." << endl;
}

void mostra_vector(const vector<string>& v)
{
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}
