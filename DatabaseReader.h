//
// Created by Jakub Górski on 28/03/2022.
//

#ifndef DATABASE_FOR_OOP_COURSE_JAKUBGORSKY_DATABASEREADER_H
#define DATABASE_FOR_OOP_COURSE_JAKUBGORSKY_DATABASEREADER_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct db_record {
    int id;
    std::string name;
    std::string surname;
    int index_number;
    std::string email;
    std::string role;
};

class DatabaseReader {
private:
    const std::string db_file = "database.csv";
    std::vector<db_record> DB;
    int max_id{};
    void read_database(const std::string& filename);
    void write_db(const std::string& filename);
public:
    DatabaseReader(){
        read_database(db_file);
    }
    void print_header();
    std::vector<db_record> get_all_students();
    db_record get_student(int id);
    void delete_student(int id);
    void add_student(std::string name, std::string surname, int index_number, std::string email, std::string role);
};


#endif //DATABASE_FOR_OOP_COURSE_JAKUBGORSKY_DATABASEREADER_H
