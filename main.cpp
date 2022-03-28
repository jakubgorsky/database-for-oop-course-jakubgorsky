//
// Created by Jakub Górski on 28/03/2022.
//

#include <iostream>
#include "DatabaseReader.h"
#include "HelperMethods.h"

int main () {
    DatabaseReader db;
    std::vector<db_record> students;

    students = db.get_all_students();
    db.print_header();
    for (const auto& i : students){
        std::cout << left(std::to_string(i.id), 5)
        << left(i.name, 20)
        << left(i.surname, 20)
        << left(std::to_string(i.index_number), 15)
        << left(i.email, 50) << "\n";
    }

    db.add_student("Leonar", "Morg", 574131, "574131@student.pwr.edu.pl");

    students = db.get_all_students();
    db.print_header();
    for (const auto& i : students){
        std::cout << left(std::to_string(i.id), 5)
                  << left(i.name, 20)
                  << left(i.surname, 20)
                  << left(std::to_string(i.index_number), 15)
                  << left(i.email, 50) << "\n";
    }

    db.delete_student(5);

    students = db.get_all_students();
    db.print_header();
    for (const auto& i : students){
        std::cout << left(std::to_string(i.id), 5)
                  << left(i.name, 20)
                  << left(i.surname, 20)
                  << left(std::to_string(i.index_number), 15)
                  << left(i.email, 50) << "\n";
    }

    return 0;
};