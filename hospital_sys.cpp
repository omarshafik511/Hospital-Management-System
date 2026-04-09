
#include <iostream>
using namespace std;
const int number_speclization = 21;
const int spots_avalible_in_speclization = 6;
string names [number_speclization][spots_avalible_in_speclization];
int status [number_speclization][spots_avalible_in_speclization];
int queue_len[number_speclization] = {0};//to know how many people in each speclization

int choices()
{
    int choice;
    cout << "Choose a number\n";
    cout << "***********************\n";
    cout << "1) Add new patient\n";
    cout << "2) Print all patients\n";
    cout << "3) Get next patient\n";
    cout << "4) Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}
void add_patient()
{
    string name;
    int specialization;
    int stat;
    bool valid = false;
    while (!valid) {
        cout << "Enter specialization (1-20): ";
        cin >> specialization;
        cout << "Enter patient name: ";
        cin >> name;
        cout << "Enter status (0 for regular, 1 for urgent): ";
        cin >> stat;

        if ((specialization > 0 && specialization < 21) && (stat == 0 || stat == 1)) 
        {
            valid = true;
        } 
        else 
        {
            cout << ">>> Error: Invalid details. Please try again.\n";
        }
        }
        if (queue_len[specialization] >= 5) 
        {
            cout << "Sorry, specialization " << specialization << " is full.\n";
            return;
        }
        else
        {
            if(stat == 0)
            {
                int pos = queue_len[specialization];
                names[specialization][pos] = name;
                status[specialization][pos] = stat;
                queue_len[specialization]++;
            }
            else
            {
                for (int i = queue_len[specialization] - 1; i >= 0; i--)//last person will shift to the next spot 
                {
                    names[specialization][i + 1] = names[specialization][i];
                    status[specialization][i + 1] = status[specialization][i];
                }
                names[specialization][0] = name;
                status[specialization][0] = stat;
                queue_len[specialization]++;
            }
        }
}

void print_all_patients()
{
    for (int i = 1; i <= 20; i++)//incrment in each specialization
    {
        if(queue_len[i] > 0)//check if there  is any patient
        {
            cout << "There are " << queue_len[i] << " patients in specialization " << i << "\n";
            for(int j = 0; j < queue_len[i]; j++)
            {
                cout << names[i][j] << " " << (status[i][j] ? "urgent" : "regular") << "\n";
            }
            cout << "\n";
        }
    }
}
void get_next_patient()
{
    int specialization_check;
    cout << "Enter specialization:\n";
    cin >> specialization_check;
    if (specialization_check < 1 || specialization_check > 20 || queue_len[specialization_check] == 0) 
    {
        cout << "Enter a correct number\n";
        return;
    }
    cout << names[specialization_check][0] << " " << "please go with the Dr\n";
    for(int i = 0; i < queue_len[specialization_check]-1;i++) 
    {
        names[specialization_check][i] = names[specialization_check][i + 1];
        status[specialization_check][i] = status[specialization_check][i + 1];
    }
    queue_len[specialization_check]--;
}
int main() {
    cout << "Welcome to our hospital system app\n";
    cout << "____________________________________\n";
    while (true) 
    {
        int user_choice = choices();

        if (user_choice == 1) add_patient();
        else if (user_choice == 2) print_all_patients();
        else if (user_choice == 3) get_next_patient();
        else if (user_choice == 4) break;
        else cout << "Invalid choice.\n";
    }
    return 0;
}