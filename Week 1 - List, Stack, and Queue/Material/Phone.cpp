#include<iostream>
#include <vector>

using namespace std;

class contact
{
string name;
string mob;

public:
    contact(): name(""), mob("")
    {}
    bool show();
    bool show(string search_term);
    bool name_exists(string tname);
    bool add(string new_name, string new_mob);
    bool edit(string);
    bool erase(string new_name);
};

contact person[100];

int main() {
	
cout << "0. Show contacts" << endl << "1. Add Contact" << endl << "2. Edit Contact" << endl << "3. Delete Contact" << endl << "4. Search" << endl << "5. Quit" << endl << endl << "Your selection…"; cin >> choice;
}

//This block of code resides within the most operate
cout << "Showing Contacts" << endl;
printline ('-', 20);

            for(i=0; i<100; i++)
                if(person[i].show())
                    flag = 1;

            if(!flag)
                cout << "No contacts found!" << endl;
//This block of code resides within the category
bool show()
{
if(name != "")
{
cout << name << "\t" << mob << endl;
return 1; //Indicates success
}
else
return 0; //Indicates failure
}

//The following code resides within the main perform.
cout << "Add New Contact\t\t\t\tpress $ to cancel" << endl;
printline('-', 20);
counter = 0;

              //Loop till correct name and mobile variety area unit entered
            do
            {
                flag = 0;
                if(counter)
                    cout << "Try again\t\t\t\tpress $ to cancel" 
                    << endl;

                //counts how many times the do-while loop executes
                counter++; 

                cout << "Name: "; cin >> temp_name;

                //Cancel operation
                if(temp_name=="$")
                {
                    cancel_flag = 1;
                    break;
                }
                cout << "Mobile No.: "; cin >> temp_mob;

                //Cancel operation
                if(temp_mob=="$")
                {
                    cancel_flag = 1;
                    break;
                }

               //Check whether or not name exists
                for(i=0; i<100; i++)
                    if(person[i].name_exists(temp_name))
                    {
                        cout << "The name you entered is already there" 
                        " in the telephone directory, enter a distinct name." 
                        << endl;
                        flag = 1;
                        break;
                    }

            }while(!name_valid(temp_name) || 
                            flag ||
                    !mob_valid(temp_mob));

            if(cancel_flag)
            {
                system("cls");
                break;
            }


            //This code adds the contact to phonebook    
            for(i=0; i<100; i++)
                if(person[i].add(temp_name, temp_mob))
                {
                    cout << "Contact added successfully!" << endl;
                    flag = 1;
                    break;
                }

            if(!flag)
                cout << "Memory full! Delete some contacts first." 
                << endl;
//The following code resides in the class
bool add(string new_name, string new_mob)
{
if(name=="")
{
name = new_name;
mob = new_mob;
return 1; // Success
}
else
return 0; // Failure
    }
    
// the subsequent code resides within the main perform.
cout << "Enter a contact name to edit:" "\t\t\t\tpress $ to cancel\n"; cin >> temp_name;

            //Cancel Operation
            if(temp_name=="$")
            {
                system("cls");
                break;
            }

            for(i=0; i<100; i++)
                if(person[i].edit(temp_name))
                {
                    cout << "Edited Successfully!" << endl;
                    flag = 1;
                    break;
                }

            if(!flag)
                cout << "Contact name not found!" << endl;
// the subsequent code resides within the category
bool contact :: edit(string new_name)
{
string new_mob;
if(new_name==name)
{
cout << "Enter new name: "; cin >> new_name;
cout << "Enter new mobile no: "; cin >> new_mob;

    name = new_name;
    mob = new_mob;
    return 1;
}
else
    return 0;
}

// the subsequent code resides within the main perform.
do
{
if(counter)
cout << "Try again" << endl; counter++; cout << "Enter a contact name to delete:" "\t\t\tpress $ to cancel\n"; cin >> temp_name;
                //Cancel Operation
                if(temp_name=="$")
                {
                    system("cls");
                    break;
                }


                //Final Confirmation
                for(i=0; i<100; i++)
                if(person[i].name_exists(temp_name))
                {
                    flag = 1;
                    cout << "Are you sure you want to delete? (1/0)" 
                    << endl;
                    int yes;
                    cin >> yes;
                    if(!yes)
                    {
                        system("cls");
                        cancel_flag = 1;
                    }
                    break;
                }

                if(!flag)
                    cout << "Contact name not found!" << endl;

                if(cancel_flag)
                    break;

                // This code deletes the contact
                if(flag)
                {
                    for(i=0; i<100; i++)
                        if(person[i].erase(temp_name))
                        {
                            cout << "Deleted successfully!" << endl;
                            break;
                        }
                }

            }while(!flag);
// the subsequent code resides within the category
bool erase(string new_name)
{
if(new_name==name)
{
name = "";
mob = "";
return 1;
}
else
return 0;
}

// the subsequent code resides within the main perform.

do
{
if(counter)
cout << "Try again" << endl; counter++; cout << "Search a name: \t\t\t\tpress $ to cancel\n"; cin >> temp_name;
                //Cancel Operation
                if(temp_name=="$")
                {
                    system("cls");
                    break;
                }

                for(i=0; i<100; i++)
                    if(person[i].show(temp_name))
                    {
                        flag = 1;
                        break;
                    }

                if(!flag)
                    cout << "Contact name not found" << endl;
            }while(!flag);
// the subsequent code resides within the category
bool show(string search_term)
{
if(search_term == name)
{
cout << name << "\t" << mob << endl;
return 1;
}
else
return 0;
}

void printline(char ch, int size)
{
for(int i=0; i<size; i++)
cout << ch;
cout << "\n";
}

bool name_valid(string tname)
{
    if(tname.size()>20)
    {
        cout << "Invalid Name!\nEnter a name within 20 characters!" 
                 << endl;
        return 0;
    }
    else if(tname == "")
    {
        cout << "Invalid Name!\nName cannot be blank!" << endl;
        return 0;
    }
    else
        return 1;
}
 
//mobile variety validation 
bool mob_valid(string tmob)
{
    if(tmob.size()>13 || tmob.size()<10)
    {
        cout << "Invalid mobile no.\nEnter a no." 
                 "between 10 and 13 digits" << endl;
        return 0;
    }
    else if(tmob == "")
    {
        cout << "Invalid mobile no.\nMobile" 
                 "no cannot be blank" << endl;
        return 0;
    }
    else
        return 1;
}
