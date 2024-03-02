// 25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<random>
using namespace std;
int main()
{
    ifstream f("in.txt");
    vector<string>cuvinte;
    string s;
    int vieti = 7;
    while (f >> s)
    {
        cuvinte.push_back(s);
    }

   /*for (auto i = cuvinte.cbegin(); i != cuvinte.cend(); ++i)
        cout << *i << " ";
    cout << endl;
*/ 
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, cuvinte.size()); // distribution in range [1, 6]

    std::cout << dist6(rng) << std::endl;

    string ghici= cuvinte.at(dist6(rng));
    //cout << ghici << endl;
    for (auto i = 0; i != ghici.length();i++)
        cout << "_ ";
    cout << endl;
    int incercari[26]{};
    char l;
    int ok = 0;
    while (vieti >= 1)
    {
       /*for (char& c : ghici) {
           
            if (incercari[c - 'a'] == 2)ok++;

        }
        if (ok >= ghici.size())cout<<"GATA";
        cout << endl;*/ 
        ok = 0;
        for (std::string::iterator it = ghici.begin(); it != ghici.end(); ++it) {
            if(incercari[*it - 'a']==2)ok++;
        }
        if (ok >= ghici.size()){cout << "GATA";
        cout << endl;
        break;
        }

        cout << "Ai: " << vieti <<" vieti"<< endl;
        cout << "Ghiceste o litera:";
        cin >> l;
        if (incercari[l - 'a'] == 0)
        {
            while (l)

            {  // for (auto i = 0; i != ghici.length() - 1; i++)
                std::size_t found = ghici.find(l);
                if (found != std::string::npos)//found e pozitia primei aparitii a literei
                {
                    incercari[l - 'a']++;
                    cout << "apare pe pozitia: " << found+1;
                    cout << endl;
                    for (auto i = 0; i != found; i++)
                    {
                        
                          if(incercari[ ghici[ i]-'a']==2)cout<<ghici[i];
                          else  cout << "_ ";
                    }
                    cout << l;
                    for (auto i = found + 1; i != ghici.length(); i++)
                    {
                        if (incercari[ghici[i] - 'a'] == 2)cout << ghici[i];
                        else  cout << "_ ";
                    }
                }
                
                else {
                    for (auto i = 0; i != ghici.length(); i++)
                    {
                        if (incercari[ghici[i] - 'a'] == 2)cout << ghici[i];
                        else  cout << "_ ";
                    }
                    vieti--;
                    cout<<endl;
                    cout << "NU apare!";
                    cout << endl;
                    cout << endl;
                }
                cout << endl;
               // cout <<"a" << l - 'a'+1 << "-a litera din alfabet";
                incercari[l - 'a']++;
                l = 0;
            }
        }
        else
            cout << "Incercare invalida";
     /*
     for (char& c : ghici) {

            if (incercari[c - 'a'] == 2)ok++;

        }
        if (ok == ghici.size())cout << "GATA";
        cout << endl;*/   

       
    }
    if (vieti == 0)
    {
        cout << "Nu mai ai vieti, ai pierdut! ;(";
        cout << endl;
        cout << "raspuns" << endl;
        cout << ghici;
    }
    }
   
    

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
