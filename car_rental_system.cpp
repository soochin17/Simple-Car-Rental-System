#include <iostream>
// #include <ctime>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

string custname, icno, YoB;
int age, i;
float discount, rentalfee;
int duration, qty_5s, qty_7s, rate_5s, rate_7s;
char res, grade_5s, grade_7s;
char res2;

void mainmenu()
{
  cout << endl;
  cout << "_________________________________________________________________" << endl;
  cout << "\t\t    CAR  RENTAL  SYSTEM " << endl;
  cout << "_________________________________________________________________" << endl;
}

int main()
{
  do
  {
    mainmenu();
    cin.clear();
    cin.sync();
    cout << "Enter you name        : ";
    getline(cin, custname);
    cout << "IC Number [without(-)]: ";
    cin >> icno;

    if (icno[11] == '2' || icno[11] == '4' || icno[11] == '6' || icno[11] == '8' || icno[11] == '0')
    {
      cout << "  Ms " << custname << ", " << endl;
      cout << "`````````````````````````````````````````````" << endl;
    }
    if (icno[11] == '1' || icno[11] == '3' || icno[11] == '5' || icno[11] == '7' || icno[11] == '9')
    {
      cout << "  Mr " << custname << ", " << endl;
      cout << "`````````````````````````````````````````````" << endl;
    }

    // time_t now = time(0);
    // tm *local = localtime(&now);
    // int current_year = local->tm_year;

    YoB = icno.substr(0, 2);
    istringstream convert(YoB);
    convert >> i;
    if (i > 18)
    {
      age = 2022 - 1900 - i;
    }
    else
    {
      age = 2022 - 2000 - i;
    }
    cout << "Age                   : " << age << endl;
    if (age >= 18)

    {
      cout << "Have license? [Y/N]   : ";
      cin >> res2;
      cout << endl;
    }
    else
    {
      cout << "------SORRY, MINIMUM RENTAL AGE IS 18." << endl;
      return 0;
    }
    while (toupper(res2) != 'Y' && toupper(res2) != 'N')
    {
      cout << "  **Invalid response. Please answer again." << endl;
      cout << "Have license? [Y/N]   : ";
      cin >> res2;
      cout << endl;
    }
    if (toupper(res2) == 'N')
    {
      cout << "------SORRY, YOU ARE NOT ALLOWED TO RENT THE CAR-------" << endl;
      return 0;
    }

    cout << " ------HERE IS THE PRICE LIST FOR CAR RENTING-----------" << endl;
    cout << "\t\t________________________________________________________" << endl;
    cout << "\t\t| Price lists                                           |" << endl;
    cout << "\t\t| ``````````````````````````````````````````````````````|" << endl;
    cout << "\t\t| Five-seater       : Grade A - RM 150                  |" << endl;
    cout << "\t\t|                     Grade B - RM 120                  |" << endl;
    cout << "\t\t|                     Grade C - RM  80                  |" << endl;
    cout << "\t\t|_______________________________________________________|" << endl;
    cout << "\t\t| Seven-seater      : Grade A - RM 180                  |" << endl;
    cout << "\t\t|                     Grade B - RM 140                  |" << endl;
    cout << "\t\t|                     Grade C - RM 100                  |" << endl;
    cout << "\t\t|_______________________________________________________|" << endl
         << endl;

    cout << "Quantity of five-seater car you want to rent: ";
    cin >> qty_5s;
    while (cin.fail())
    {
      cin.clear();               // clear input buffer to restore cin to a usable state
      cin.ignore(INT_MAX, '\n'); // ignore last input
      cout << "** You can only enter numbers.\n";
      cout << "Enter quantity for five-seater car: ";
      cin >> qty_5s;
    }

    cout << endl;
    cout << "Quantity of seven-seater car you want to rent: ";
    cin >> qty_7s;
    while (cin.fail())
    {
      cin.clear();               // clear input buffer to restore cin to a usable state
      cin.ignore(INT_MAX, '\n'); // ignore last input
      cout << "** You can only enter numbers.\n";
      cout << "Enter quantity for seven-seater car: ";
      cin >> qty_7s;
    }
    cout << endl;

    if ((qty_5s >= 1) && (qty_7s == 0))
    {
      cout << "What grade of five-seater car [A/B/C]: ";
      cin >> grade_5s;
      cout << endl;
      if (toupper(grade_5s) == 'C')
      {
        rate_5s = 80;
      }
      else if (toupper(grade_5s) == 'B')
      {
        rate_5s = 120;
      }
      else if (toupper(grade_5s) == 'A')
      {
        rate_5s = 150;
      }
      else
      {
        rate_5s = 0;
      }
      while (toupper(grade_5s) != 'C' && toupper(grade_5s) != 'B' && toupper(grade_5s) != 'A')
      {
        cout << " **Please enter five-seater car grade again.**" << endl
             << endl;
        cout << "What grade of five-seater car [A/B/C]: ";
        cin >> grade_5s;
        cout << endl;
        if (toupper(grade_5s) == 'C')
        {
          rate_5s = 80;
        }
        else if (toupper(grade_5s) == 'B')
        {
          rate_5s = 120;
        }
        else if (toupper(grade_5s) == 'A')
        {
          rate_5s = 150;
        }
        else
        {
          rate_5s = 0;
        }
      }
    }
    else if ((qty_5s == 0) && (qty_7s >= 1))
    {
      cout << "What grade of seven-seater car [A/B/C]: ";
      cin >> grade_7s;
      cout << endl;
      if (toupper(grade_7s) == 'C')
      {
        rate_7s = 100;
      }
      else if (toupper(grade_7s) == 'B')
      {
        rate_7s = 140;
      }
      else if (toupper(grade_7s) == 'A')
      {
        rate_7s = 180;
      }
      else
      {
        rate_7s = 0;
      }
      while (toupper(grade_7s) != 'C' && toupper(grade_7s) != 'B' && toupper(grade_7s) != 'A')
      {
        cout << " **Please enter seven-seater car grade again.**" << endl
             << endl;
        cout << "What grade of seven-seater car [A/B/C]: ";
        cin >> grade_7s;
        cout << endl;
        if (toupper(grade_7s) == 'C')
        {
          rate_7s = 100;
        }
        else if (toupper(grade_7s) == 'B')
        {
          rate_7s = 140;
        }
        else if (toupper(grade_7s) == 'A')
        {
          rate_7s = 180;
        }
        else
        {
          rate_7s = 0;
        }
      }
    }
    else if ((qty_5s >= 1) && (qty_7s >= 1))
    {
      cout << "What grade of five-seater car [A/B/C]: ";
      cin >> grade_5s;
      cout << endl;
      if (toupper(grade_5s) == 'C')
      {
        rate_5s = 80;
      }
      else if (toupper(grade_5s) == 'B')
      {
        rate_5s = 120;
      }
      else if (toupper(grade_5s) == 'A')
      {
        rate_5s = 150;
      }
      else
      {
        rate_5s = 0;
      }
      while (toupper(grade_5s) != 'C' && toupper(grade_5s) != 'B' && toupper(grade_5s) != 'A')
      {
        cout << " **Please enter five-seater car grade again.**" << endl
             << endl;
        cout << "What grade of five-seater car [A/B/C]: ";
        cin >> grade_5s;
        cout << endl;
        if (toupper(grade_5s) == 'C')
        {
          rate_5s = 80;
        }
        else if (toupper(grade_5s) == 'B')
        {
          rate_5s = 120;
        }
        else if (toupper(grade_5s) == 'A')
        {
          rate_5s = 150;
        }
        else
        {
          rate_5s = 0;
        }
      }

      cout << "What grade of seven-seater car [A/B/C]: ";
      cin >> grade_7s;
      cout << endl;
      if (toupper(grade_7s) == 'C')
      {
        rate_7s = 100;
      }
      else if (toupper(grade_7s) == 'B')
      {
        rate_7s = 140;
      }
      else if (toupper(grade_7s) == 'A')
      {
        rate_7s = 180;
      }
      else
      {
        rate_7s = 0;
      }
      while (toupper(grade_7s) != 'C' && toupper(grade_7s) != 'B' && toupper(grade_7s) != 'A')
      {
        cout << " **Please enter seven-seater car grade again.**" << endl
             << endl;
        cout << "What grade of seven-seater car [A/B/C]: ";
        cin >> grade_7s;
        cout << endl;
        if (toupper(grade_7s) == 'C')
        {
          rate_7s = 100;
        }
        else if (toupper(grade_7s) == 'B')
        {
          rate_7s = 140;
        }
        else if (toupper(grade_7s) == 'A')
        {
          rate_7s = 180;
        }
        else
        {
          rate_7s = 0;
        }
      }
    }
    else
    {
      cout << " **Invalid. Please try again.**" << endl;
      cout << "________________________________________________" << endl;
    }
    while (qty_5s == 0 && qty_7s == 0)
    {
      cout << "Quantity of five-seater car you want to rent: ";
      cin >> qty_5s;
      cout << endl;
      cout << "Quantity of seven-seater car you want to rent: ";
      cin >> qty_7s;
      cout << endl;

      if ((qty_5s >= 1) && (qty_7s == 0))
      {
        cout << "What grade of five-seater car [A/B/C]: ";
        cin >> grade_5s;
        cout << endl;
        if (toupper(grade_5s) == 'C')
        {
          rate_5s = 80;
        }
        else if (toupper(grade_5s) == 'B')
        {
          rate_5s = 120;
        }
        else if (toupper(grade_5s) == 'A')
        {
          rate_5s = 150;
        }
        else
        {
          rate_5s = 0;
        }
        while (toupper(grade_5s) != 'C' && toupper(grade_5s) != 'B' && toupper(grade_5s) != 'A')
        {
          cout << " **Please enter five-seater car grade again.**" << endl
               << endl;
          cout << "What grade of five-seater car [A/B/C]: ";
          cin >> grade_5s;
          cout << endl;
          if (toupper(grade_5s) == 'C')
          {
            rate_5s = 80;
          }
          else if (toupper(grade_5s) == 'B')
          {
            rate_5s = 120;
          }
          else if (toupper(grade_5s) == 'A')
          {
            rate_5s = 150;
          }
          else
          {
            rate_5s = 0;
          }
        }
      }
      else if ((qty_5s == 0) && (qty_7s >= 1))
      {
        cout << "What grade of seven-seater car [A/B/C]: ";
        cin >> grade_7s;
        cout << endl;
        if (toupper(grade_7s) == 'C')
        {
          rate_7s = 100;
        }
        else if (toupper(grade_7s) == 'B')
        {
          rate_7s = 140;
        }
        else if (toupper(grade_7s) == 'A')
        {
          rate_7s = 180;
        }
        else
        {
          rate_7s = 0;
        }
        while (toupper(grade_7s) != 'C' && toupper(grade_7s) != 'B' && toupper(grade_7s) != 'A')
        {
          cout << " **Please enter seven-seater car grade again.**" << endl
               << endl;
          cout << "What grade of seven-seater car [A/B/C]: ";
          cin >> grade_7s;
          cout << endl;
          if (toupper(grade_7s) == 'C')
          {
            rate_7s = 100;
          }
          else if (toupper(grade_7s) == 'B')
          {
            rate_7s = 140;
          }
          else if (toupper(grade_7s) == 'A')
          {
            rate_7s = 180;
          }
          else
          {
            rate_7s = 0;
          }
        }
      }
      else if ((qty_5s >= 1) && (qty_7s >= 1))
      {
        cout << "What grade of five-seater car [A/B/C]: ";
        cin >> grade_5s;
        cout << endl;
        if (toupper(grade_5s) == 'C')
        {
          rate_5s = 80;
        }
        else if (toupper(grade_5s) == 'B')
        {
          rate_5s = 120;
        }
        else if (toupper(grade_5s) == 'A')
        {
          rate_5s = 150;
        }
        else
        {
          rate_5s = 0;
        }
        while (toupper(grade_5s) != 'C' && toupper(grade_5s) != 'B' && toupper(grade_5s) != 'A')
        {
          cout << " **Please enter five-seater car grade again.**" << endl
               << endl;
          cout << "What grade of five-seater car [A/B/C]: ";
          cin >> grade_5s;
          cout << endl;
          if (toupper(grade_5s) == 'C')
          {
            rate_5s = 80;
          }
          else if (toupper(grade_5s) == 'B')
          {
            rate_5s = 120;
          }
          else if (toupper(grade_5s) == 'A')
          {
            rate_5s = 150;
          }
          else
          {
            rate_5s = 0;
          }
        }

        cout << "What grade of seven-seater car [A/B/C]: ";
        cin >> grade_7s;
        cout << endl;
        if (toupper(grade_7s) == 'C')
        {
          rate_7s = 100;
        }
        else if (toupper(grade_7s) == 'B')
        {
          rate_7s = 140;
        }
        else if (toupper(grade_7s) == 'A')
        {
          rate_7s = 180;
        }
        else
        {
          rate_7s = 0;
        }
        while (toupper(grade_7s) != 'C' && toupper(grade_7s) != 'B' && toupper(grade_7s) != 'A')
        {
          cout << "Please enter seven-seater car grade again." << endl
               << endl;
          cout << "What grade of seven-seater car [A/B/C]: ";
          cin >> grade_7s;
          cout << endl;
          if (toupper(grade_7s) == 'C')
          {
            rate_7s = 100;
          }
          else if (toupper(grade_7s) == 'B')
          {
            rate_7s = 140;
          }
          else if (toupper(grade_7s) == 'A')
          {
            rate_7s = 180;
          }
          else
          {
            rate_7s = 0;
          }
        }
      }
      else
      {
        cout << " **Invalid. Please try again.**" << endl;
      }
    }

    cout << "Duration days of car rental: ";
    cin >> duration;
    while (duration <= 0)
    {
      cout << " **Invalid,Please try again.**  " << endl
           << endl;
      cout << "Duration days of car rental: ";
      cin >> duration;
    }

    cout << endl;
    if ((duration >= 1) && (duration <= 3))
    {
      discount = 0.0;
    }
    else if ((duration >= 4) && (duration <= 7))
    {
      discount = 0.1;
    }
    else
    {
      discount = 0.2;
    }

    rentalfee = ((qty_5s * rate_5s) + (qty_7s * rate_7s)) * duration * (1.0 - discount);

    cout << "\t\t======================================================" << endl;
    cout << "\t\t\t Dear Mr/Mrs " << custname << " ," << endl;
    cout << "\t\t\t    Your rental fee is RM " << rentalfee << " ." << endl;
    cout << "\t\t\t    You had booked: " << endl;
    cout << "\t\t\t          " << qty_5s << " five-seater car " << endl;
    cout << "\t\t\t          " << qty_7s << " seven-seater car " << endl;
    cout << "\t\t\t    Duration days: " << duration << endl;
    cout << "\t\t======================================================";
    cout << endl;

    cout << "........................................" << endl;
    cout << "Continue with next customer? [Y/N]: ";
    cin >> res;
    cout << endl;
    while (tolower(res) != 'y' && tolower(res) != 'n')
    {
      cout << " **Please enter valid response [Y/N].**" << endl;
      cout << endl;
      cout << "...................................." << endl;
      cout << "Continue with next customer? [Y/N]: ";
      cin >> res;
      cout << endl
           << endl;
    }

    system("CLS");

  } while (toupper(res) == 'Y');

  cout << endl
       << endl;

  cout << "\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
  cout << "\t#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-" << endl;
  cout << "\t\t   THANK YOU FOR CHOOSING US   " << endl;
  cout << "\t#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-" << endl;
  cout << "\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
}
