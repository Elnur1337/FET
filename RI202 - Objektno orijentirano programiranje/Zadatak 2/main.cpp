#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <regex>

using namespace std;

/*
Transaction types:
1 - Deposit
2 - Withdrawal
3 - Payment
4 - Refund
*/

struct transactionInfo
{
    string date;
    float value;
    short transactionType;
};

//Functions
void fillVector(vector<transactionInfo>&, float&);
short showMainMenu();
void showTransactionTypesNumber(vector<transactionInfo>&);
int generateIntFromDate(const string&);
string getTransactionTypeName(const int&);
void bigSmallTransaction(vector<transactionInfo>&);

int main()
{
    cout << "Ucitavanje podataka, molimo sacekajte malo...\n";

    vector<transactionInfo> dataVector;
    float trenutnoStanje = 0;
    fillVector(dataVector, trenutnoStanje);

    short option = 0;
    do {
        option = showMainMenu();
        switch (option) {
            case 1:
                showTransactionTypesNumber(dataVector);
                break;
            case 2:
                bigSmallTransaction(dataVector);
                break;
            case 3:
                cout << "Trenutno stanje na racunu iznosi: " << trenutnoStanje << "\n\n";
                break;
            default:
                cout << "Unijeli ste nepostojecu opciju, molimo odaberite ponovo!\n";
                break;
        }
    } while (option != 4);
    return 0;
}

void fillVector(vector<transactionInfo>& vec, float& trenutnoStanje) {
    ifstream data("simulirani_financijski_podaci.txt");
    string row;
    while(getline(data, row)) {
        transactionInfo temp;

        //Date
        short pos = row.find(',');
        temp.date = row.substr(0, pos);
        row = row.substr(pos + 2, row.length());

        //Value
        pos = row.find(',');
        temp.value = abs(stof(row.substr(0, pos)));
        row = row.substr(pos + 2, row.length());

        //Transaction type
        if (row == "Deposit") {
            temp.transactionType = 1;
            trenutnoStanje += temp.value;
        } else if (row == "Withdrawal") {
            temp.transactionType = 2;
            trenutnoStanje -= temp.value;
        } else if (row == "Payment") {
            temp.transactionType = 3;
            trenutnoStanje += temp.value;
        } else {
            temp.transactionType = 4;
            trenutnoStanje -= temp.value;
        }

        vec.push_back(temp);
    }
    data.close();
    return;
}

short showMainMenu() {
    short option;
    cout << "Odaberite opciju:\n1. Brojanje transakcija po vrsti\n2. Najveca i najmanja transakcija unutar datog vremenskog perioda\n3. Stanje na racunu\n4. Izlaz\n-----------------------------------------\n";
    bool isInputValid = false;
    do {
        string input;
        cout << "Unesite broj opcije: ";
        cin >> input;
        try {
            option = stoi(input);
            isInputValid = true;
        } catch (const std::invalid_argument& err) {
            cout << "Niste unijeli broj!\n";
        } catch (const std::out_of_range& err) {
            cout << "Niste unijeli broj!\n";
        }
    } while (!isInputValid);
    return option;
}

void showTransactionTypesNumber(vector<transactionInfo>&vec) {
    string godina, mjesec;
    int depositNumber = 0, withdrawalNumber = 0, paymentNumber = 0, refundNumber = 0;

    bool isInputValid = false;
    do {
        cout << "Unesite godinu: ";
        cin >> godina;
        try {
            const int input = stoi(godina);
            if (input < 1000 || input > 9999) {
                throw input;
            }
            isInputValid = true;
        } catch (const std::invalid_argument& err) {
            cout << "Niste unijeli broj!\n";
        } catch (const std::out_of_range& err) {
            cout << "Niste unijeli broj!\n";
        } catch (int num) {
            cout << "Niste unijeli validnu godinu!\n";
        }
    } while (!isInputValid);

    isInputValid = false;
    do {
        cout << "Unesite mjesec u formatu dva broja(Ako zelite brojanje po cijeloj godini unesite 00): ";
        cin >> mjesec;
        try {
            const int input = stoi(mjesec);
            if (input < 0 || input > 12) {
                throw input;
            }
            isInputValid = true;
        } catch (const std::invalid_argument& err) {
            cout << "Niste unijeli broj!\n";
        } catch (const std::out_of_range& err) {
            cout << "Niste unijeli broj!\n";
        } catch (int num) {
            cout << "Niste unijeli validan broj!\n";
        }
    } while (!isInputValid);

    if (mjesec == "00") {
        for (const transactionInfo transaction : vec) {
            if (transaction.date.substr(0, 4) == godina) {
                switch(transaction.transactionType) {
                    case 1:
                        ++depositNumber;
                        break;
                    case 2:
                        ++withdrawalNumber;
                        break;
                    case 3:
                        ++paymentNumber;
                        break;
                    default:
                        ++refundNumber;
                        break;
                }
            }
        }
    } else {
        for (const transactionInfo transaction : vec) {
            if ((transaction.date.substr(0, 4) == godina) && (transaction.date.substr(5, 2) == mjesec)) {
                switch(transaction.transactionType) {
                    case 1:
                        ++depositNumber;
                        break;
                    case 2:
                        ++withdrawalNumber;
                        break;
                    case 3:
                        ++paymentNumber;
                        break;
                    default:
                        ++refundNumber;
                        break;
                }
            }
        }
    }

    cout << "Broj depozita: " << depositNumber << endl;
    cout << "Broj povlacenja novca: " << withdrawalNumber << endl;
    cout << "Broj uplata: " << paymentNumber << endl;
    cout << "Broj povrata novca: " << refundNumber << "\n\n";
    return;
}

int generateIntFromDate(const string& datum) {
    return 10000 * stoi(datum.substr(0, 4)) + 100 * stoi(datum.substr(5, 2)) + stoi(datum.substr(8, 2));
}

string getTransactionTypeName(const int& transactionTypeNumber) {
    switch (transactionTypeNumber) {
        case 1:
            return "Deposit";
            break;
        case 2:
            return "Withdrawal";
            break;
        case 3:
            return "Payment";
            break;
        default:
            return "Refund";
            break;
    }
}

void bigSmallTransaction(vector<transactionInfo>&vec) {
    string datum1, datum2;
    regex datumRegex("^\\d{4}-\\d{2}-\\d{2}$");
    transactionInfo small, big;
    small.value = 9999;
    big.value = 0;

    bool isInputValid = false;
    do {
        cout << "Unesite prvi datum(Format: GGGG-MM-DD): ";
        cin >> datum1;
        if (regex_match(datum1, datumRegex)) {
            isInputValid = true;
        } else {
            cout << "Niste unijeli ispravan datum!\n";
        }
    } while (!isInputValid);

    isInputValid = false;
    do {
        cout << "Unesite drugi datum(Format: GGGG-MM-DD): ";
        cin >> datum2;
        if (regex_match(datum2, datumRegex)) {
            isInputValid = true;
        } else {
            cout << "Niste unijeli ispravan datum!\n";
        }
    } while (!isInputValid);

    int datum1Num = generateIntFromDate(datum1);
    int datum2Num = generateIntFromDate(datum2);

    for (const transactionInfo transaction : vec) {
        if ((generateIntFromDate(transaction.date) > datum1Num) && (generateIntFromDate(transaction.date) < datum2Num)) {
            if (transaction.value < small.value) {
                small = transaction;
            }
            if (transaction.value > big.value) {
                big = transaction;
            }
        }
    }
    cout << "Najveca transakcija:\nDate: " << big.date << "\nValue: " << big.value << "\nTransaction type: " << getTransactionTypeName(big.transactionType) << "\n\n" << endl;
    cout << "Najmanja transakcija:\nDate: " << small.date << "\nValue: " << small.value << "\nTransaction type: " << getTransactionTypeName(small.transactionType) << "\n\n" << endl;
    return;
}
