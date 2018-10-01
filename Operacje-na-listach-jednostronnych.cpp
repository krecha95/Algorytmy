#include "function.cpp"

using namespace std;

int main()
{

    cout<<"Operacje na listach jednostronnie wiazanych"<<endl;
    cout << "-----------------------------------------"<<endl;

    cout<<"Aktualna lista jest nastepujaca:"<<endl;
    node *H = NULL;
	H = new node;
	H->val = 8;
	H->next = NULL;
    showlist(H);

    bool exit = false;

    do {
        cout<<endl<<"Menu:"<<endl;
        cout << "1. Wyswietl liste"<<endl;
        cout << "2. Dodaj nowy element - przed glowe"<<endl;
        cout << "3. Dodaj nowy element - na drugie miejsce przed glowe"<<endl;
        cout << "4. Usun element - sprzed glowy"<<endl;
        cout << "5. Usuniecie co 2 elementu listy"<<endl;
        cout << "6. Usuwanie wybranego elementu"<<endl;
        cout << "7. Dodanie wybranego elementu na koniec listy"<<endl;
        cout << "8. Dodanie elementu przed podany"<<endl;
        cout << "9. Przeniesienie ostatniego elementu listy na pierwsze miejsce - przed glowe"<<endl;
        cout << "10.Zamiana elementu pierwszego z drugim"<<endl;
        cout << "11.Zamiana elementu o podanym kluczu ze swoim nastepnikim"<<endl;
        cout << "12.Zamiana elementu o podanym kluczu ze swoim poprzednikiem"<<endl;
        cout << "13.Zamiana pierwszego elementu z ostatnim"<<endl;
        cout << "14.Kopiowanie kazdego elementu z listy"<<endl;
        cout << "15.Odwracanie listy"<<endl;
        cout << "16.Kopiowanie za siebie listy odwroconej"<<endl;
        cout << "17.Kopiowanie za siebie listy 1 razy"<<endl;
        cout << "18.Kopiowanie elemnetu o jego wartosci"<<endl;
        cout << "19.Usuwanie wybranego elementu"<<endl;
        cout << "20.Dodanie 10 losowych liczb z przedziaiu 1-50"<<endl;
        cout << "21.Usuwanie elementow parzystych"<<endl;

        cout << "-------------------------------\n";

        int wybierz = 0;
        cout << "Wybierz dzialanie: ";
        cin >> wybierz;

        if (wybierz >= 1 && wybierz <=21) {

            switch (wybierz) {
                    case 1: {
                        showlist(H);
                        break;
                    }

                    case 2: {
                        int x;
                        cout<<"podaj wartosc"<<endl;
                        cin >> x;
                        AddToList(H,x);
                        break;
                        }

                    case 3: {
                        int x;
                        cout<<"podaj wartosc"<<endl;
                        cin >> x;
                        AddToList(H->next, x);
                        break;
                        }
                    case 4: {
                        DeleteList(H);
                        break;
                    }
                    case 5: {
                        DelEverySecondElement(H);
                        break;
                    }
                    case 6: {
                        int x;
                        cout<<"podaj wartosc"<<endl;
                        cin >> x;
                        DelNodex(H,x);
                        break;
                    }
                    case 7: {
                        int x;
                        cout<<"podaj wartosc"<<endl;
                        cin >> x;
                        AddToEnd(H, x);
                        break;
                    }
                    case 8: {
                        int x;
                        cout<<"podaj wartosc ktora chcesz dodac"<<endl;
                        cin >> x;
                        int y;
                        cout<<"podaj wartosc przed ktora ma byc dodana liczba"<<endl;
                        cin >> y;
                        AddToAfterx(H, x, y);
                        break;
                    }
                    case 9: {
                        AddLastToFirst(H);
                        break;
                    }
                    case 10: {
                        ChangeFirstElements(H);
                        break;
                    }
                    case 11: {
                        int x;
                        cout<<"podaj wartosc "<<endl;
                        cin >> x;
                        ChangexToNext(H, x);
                        break;
                    }
                    case 12: {
                        int x;
                        cout<<"podaj wartosc "<<endl;
                        cin >> x;
                        ChangexToPrev(H, x);
                        break;
                    }
                    case 13: {
                        ChangeLastToFirst(H);
                        break;
                    }
                    case 14: {
                        CopyEveryElements(H);
                        break;
                    }
                     case 15: {
                        InverseList(H);
                        break;
                    }
                     case 16: {
                        CopyInverseListBehind(H);
                        break;
                    }
                     case 17: {
                        CopyListBehind(H);
                        break;
                    }
                    case 18: {
                        CopyEqualVal(H);
                        break;
                    }
                    case 19: {
                        int x;
                        cout<<"podaj wartosc "<<endl;
                        cin >> x;
                        DelNodex(H,x);
                        break;
                    }
                    case 20: {
                        Add10RandNumb(H);
                        break;
                    }
                    case 21: {
                        DelEvenNumb(H);
                        break;
                    }

                    }
        }
        else {
            system ("cls");
            cout << "Wprowadziles bledny numer.\n";

            cout << "Czy chcesz wyjsc z programu?(t/n)\n";
            char wybor;
            cin >> wybor;

            if (wybor == 't')
            {
                system ("cls");
                exit = true;
            }
            else if (wybor == 'n')
            {
                system ("cls");
            }
            else
            {
                system ("cls");
                exit = true;
            }
        }
    } while (exit!=true);

    return EXIT_SUCCESS;

	return 0;
}
