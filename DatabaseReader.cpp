//
// Created by Jakub Górski on 28/03/2022.
//

#include "DatabaseReader.h"
#include "HelperMethods.h"
#include "colours.h"

void DatabaseReader::read_database(const std::string& filename) {

    std::ifstream ReadDatabaseFile(filename);
    std::stringstream buffer;
    buffer << ReadDatabaseFile.rdbuf();
    ReadDatabaseFile.close();

    std::string line;
    while (std::getline(buffer,line)) {
        std::vector<std::string> values;
        db_record temp;
        split_string(line, values, ',');
        temp.id = std::stoi(values[0]);
        temp.name = values[1];
        temp.surname = values[2];
        temp.index_number = std::stoi(values[3]);
        temp.email = values[4];
        temp.role = values[5];
        DB.emplace_back(temp);
        max_id = std::stoi(values[0]);
    }
}

void DatabaseReader::write_db(const std::string& filename) {
    std::ofstream ClearDB(filename, std::ofstream::out | std::ofstream::trunc);
    ClearDB.close();
    std::ofstream WriteDatabaseFile(filename, std::ios_base::app);
    for (const auto& i : DB){
        WriteDatabaseFile << i.id << "," << i.name << "," << i.surname << "," << i.index_number << "," << i.email << "," << i.role << "\n";
    }
    WriteDatabaseFile.close();
}

void DatabaseReader::print_header() {
    std::cout << GREEN << left("ID:", 5)
    << left("Name:",20)
    << left("Surname:",20)
    << left("In. number:",15)
    << left("Role:",25)
    << left("Email:", 50) << RESET << "\n";
}

std::vector<db_record> DatabaseReader::get_all_students() {
    return DB;
}

db_record DatabaseReader::get_student(int id) {
    if (id-1 < DB.size() && id-1 > 0){
        return DB[id-1];
    }
    else {
        throw std::out_of_range("[ERROR] Provided index out of range!");
    }
}

void DatabaseReader::delete_student(int id) {
    if (id < DB.size() && id >= 0){
        auto itr = DB.begin() + id - 1;
        DB.erase(itr);
        int j = 1;
        for (auto& i : DB) {
            i.id = j;
            j++;
        }
        write_db(db_file);
        return;
    }
    else {
        throw std::out_of_range("[ERROR] Provided index out of range!");
    }
}


void DatabaseReader::add_student(std::string name, std::string surname, int index_number, std::string email, std::string role) {
    db_record student;
    student.id = max_id + 1;
    student.name = name;
    student.surname = surname;
    student.index_number = index_number;
    student.role = role;
    student.email = email;
    DB.push_back(student);
    write_db(db_file);
}
