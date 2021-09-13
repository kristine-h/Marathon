//A C++ program, which allows the user to add/delete/edit a contact in Phonebook and display it. All the info is saved in a .txt file.

#include <iostream>
#include <fstream>
#include <vector>

struct Contacts {

        std::string name;
        std::string lastName;
        std::string number;
        std::string address;
};


std::vector<Contacts> vec;

void addContact(){  //writes info into the .txt file

        std::ofstream outFile;
        outFile.open("phoneBook.txt", std::ios::app);

        if(!outFile.is_open()) {

                std::cout<<"Unable to open the file!\n";
        } else {

                Contacts contact;
                std::cout << "Enter contact's name, last name, number, address\n";
                std::cin >> contact.name >> contact.lastName >> contact.number >> contact.address;
                outFile << contact.name << "\t" << contact.lastName << "\t" << contact.number << "\t" << contact.address << "\n";
          }

        outFile.close();
}

void displayBook(){  //displays the phonebook

        std::ifstream inFile;
        inFile.open("phoneBook.txt");

        if(!inFile.is_open()) {
                std::cout << "Unable to open the file!\n";
        } else {
                std::cout << "PHONE BOOK\n";
                std::string tmp;
                while(std::getline(inFile, tmp)){ //line by line
                        std::cout << tmp << std::endl;
                }
          }
        inFile.close();
}

void editContact(){ //edits the contact info

        std::ifstream inFile;
        inFile.open("phoneBook.txt");

        if(!inFile.is_open()){
                std::cout << "Unable to open the file!";
        } else {

                std::cout << "\nEnter the phone number of the contact you want to modify:\n";
                std::string number;
                std::cin >> number;

                while(!inFile.eof()){
                        Contacts tmp;
                        inFile >> tmp.name >> tmp.lastName >> tmp.number >> tmp.address;

                        if(tmp.number != number){

                        } else {

                                std::cout << "\nWhat do you want to modify?(1-4)\n";
                                std::cout << "1.Name\n";
                                std::cout << "2.Last name\n";
                                std::cout << "3.Number\n";
                                std::cout << "4.Address\n\n";
                                int choice{};
                                std::cin >> choice;
                                std::string newInfo;

                                switch(choice){
                                        case 1: std::cout << "Enter a new name for the contact\n";
                                                std::cin >> newInfo;
                                                tmp.name = newInfo;
                                                break;
                                        case 2: std::cout << "Enter a new last name for the contact\n";
                                                std::cin >> newInfo;
                                                tmp.lastName = newInfo;
                                                break;
                                        case 3: std::cout << "Enter a new phone number for the contact\n";
                                                std::cin >> newInfo;
                                                tmp.number = newInfo;
                                                break;
                                        case 4: std::cout << "Enter a new address for the contact\n";
                                                std::cin >> newInfo;
                                                tmp.address = newInfo;
                                                break;
                                }//end of switch
                           } //end of else
                           
                        vec.push_back(tmp);
                        
                }//end of while

                remove("phoneBook.txt");
                std::fstream newFile;
                newFile.open("phoneBook.txt", std::fstream::in | std::fstream::out | std::fstream::app);

                for(int i=0; i<vec.size(); ++i){
                        newFile << vec[i].name << "\t" << vec[i].lastName << "\t"<< vec[i].number << "\t" << vec[i].address << std::endl;
                }

                newFile.close();
                vec.clear();


        }//end of else

} //end of function

void deleteContact(){ //deletes a contact

        std::ifstream inFile;
        inFile.open("phoneBook.txt");

        if(!inFile.is_open()){
                std::cout << "Unable to open the file!";
        } else {
                std::cout << "Enter the phone number of the contact you want to delete:\n";
                std::string number;
                std::cin >> number;
                while(!inFile.eof()){
                        Contacts tmp;
                        inFile >> tmp.name >> tmp.lastName >> tmp.number >> tmp.address;

                        if(tmp.number != number){
                                vec.push_back(tmp);
                        }

                }

                inFile.close();
                remove("phoneBook.txt");
                std::fstream newFile;
                newFile.open("phoneBook.txt", std::fstream::in | std::fstream::out | std::fstream::app);

                for(int i=0; i<vec.size(); ++i){
                        newFile << vec[i].name << "\t" << vec[i].lastName << "\t"<< vec[i].number << "\t" << vec[i].address<< std::endl;
                }

                newFile.close();
                vec.clear();
        }
}

void action(){ 

        int choice{};

        do{
                std::cout << "\nWhat do you want to do?(0-4)\n";
                std::cout << "0.Exit\n";
                std::cout << "1.Display the Phone Book\n";
                std::cout << "2.Add a new contact\n";
                std::cout << "3.Modify a contact\n";
                std::cout << "4.Delete a contact info\n\n";
                std::cin >> choice;

                 switch(choice){

                         case 1: displayBook();
                                 break;
                         case 2: addContact();
                                 break;
                         case 3: editContact();
                                 break;
                         case 4: deleteContact();
                                 break;
                }

        }
        while(choice);
}

int main(){

        action();
        return 0;
}
    
