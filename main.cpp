//
// Created by Jakub Górski on 28/03/2022.
//

#include <iostream>
#include "DatabaseReader.h"
#include "HelperMethods.h"
#include "colours.h"

void print(std::vector<db_record> db){
    for (const auto& i : db){
        std::cout << left(std::to_string(i.id), 5)
                  << left(i.name, 20)
                  << left(i.surname, 20)
                  << left(std::to_string(i.index_number), 15)
                  << left(i.role, 25)
                  << left(i.email, 50) << "\n";
    }
}

int main () {
    DatabaseReader db;
    std::vector<db_record> students;

    while (true) {
        int option, id;
        std::string name, surname, role_string;
        std::cout << YELLOW << "\nMenu:" << RESET <<
             "\n\t1.Show all students\n\t2.Show selected student\n\t3.Add student\n\t4.Delete student\n\t5.Quit program\n\nSelection: ";
        std::cin >> option;
        db_record temp;
        std::vector<db_record> tempV;
        switch(option){
            case 1:
                std::cout << "\n";
                students = db.get_all_students();
                db.print_header();
                print(students);
                std::cout << "\n";
                break;
            case 2:
                std::cout << YELLOW << "\nWhich student do you want to show?\n\nSelection: " << RESET;
                std::cin >> id;
                temp = db.get_student(id);
                tempV.push_back(temp);
                db.print_header();
                print(tempV);
                std::cout << "\n";
                break;
            case 3:
                std::cout << YELLOW << "\nProvide student data:"
                << YELLOW << "\nName: " << RESET;
                std::cin >> temp.name;
                std::cout << YELLOW << "\nSurname: " << RESET;
                std::cin >> temp.surname;
                std::cout << YELLOW << "\nIndex Number: " << RESET;
                std::cin >> temp.index_number;
                std::cout << YELLOW << "\nE-mail Address: " << RESET;
                std::cin >> temp.email;
                std::cout << YELLOW << "\nRole: " <<
                "\n1. Engineer\n2. Master\n3. Doctorate" << RESET;
                std::cin >> option;
                switch(option) {
                    case 1:
                        temp.role = "Engineer";
                        break;
                    case 2:
                        temp.role = "Master";
                        break;
                    case 3:
                        temp.role = "Doctorate";
                        break;
                    default:
                        temp.role = "";
                        break;
                }
                db.add_student(temp.name, temp.surname, temp.index_number, temp.email, temp.role);
                std::cout << YELLOW << "\nAdded student: " << temp.name << " " << temp.surname << RESET;
                break;
            case 4:
                std::cout << YELLOW << "\nWhich student do you want to delete?\n\nSelection: " << RESET;
                std::cin >> id;
                db.delete_student(id);
                break;
            case 5:
                std::cout << RED << "\nQuiting program..." << RESET;
                return 0;
            default:
                std::cout << RED << "\nWrong command!" << RESET;
                break;
        }
    }
};