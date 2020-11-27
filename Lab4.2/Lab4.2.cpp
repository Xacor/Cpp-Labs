#include <string>
#include <iostream>
#include <fstream>

std::string file_format(const std::string file_path_full) {
    size_t right = file_path_full.length();
    size_t left = file_path_full.rfind(".");
    return  file_path_full.substr(left, right);
}

std::string file_name(const std::string file_path_full) {
    size_t left = file_path_full.rfind('\\');
    size_t right = file_path_full.rfind('.');
    return file_path_full.substr(left+1, right - left - 1);
}

std::string file_path(const std::string file_path_full) {
    size_t right = file_path_full.rfind('\\');
    return file_path_full.substr(0, right);
}

char file_disk(const std::string file_path_full) {
    return file_path_full[0];
}

bool file_rename(std::string* file_path_full) {
    std::string temp = *file_path_full;
    std::string new_name;
    std::cout << "Input new file name:";
    std::getline(std::cin, new_name);

    if (temp.rfind('.') == -1) return false;
    else {
        temp.replace(temp.rfind('\\')+1, temp.rfind('.') - temp.rfind('\\')-1, new_name);
        *file_path_full = temp;
        return true;
    }

}

bool file_copy(const std::string file_path_full) {
    std::string dest_path = file_path_full;
    dest_path.insert(file_path_full.rfind('.'), "_copy", 0, 5);
    
    std::ifstream src(file_path_full, std::ifstream::in);
    if (src.is_open()) {
        std::ofstream dest;
        dest.open(dest_path, std::ofstream::out);
        std::string line;
        
        while (!src.eof()) {
            std::getline(src, line);
            dest << line << std::endl;
        }
        dest.close();
        return true;
    }
    else {
        std::cout << "file not found" << std::endl;
        return false;
    }

}

int main()
{
    std::string file_path_full;                                 //D:\Code\repos\txtfile.txt
    while (1) {
        std::cout << "1. file_format\n"
            << "2. file_name\n"
            << "3. file_path\n"
            << "4. file_disk\n"
            << "5. file_rename\n"
            << "6. file_copy\n"
            << "7. exit\n";
        int cmd;
        std::cin >> cmd;

        switch (cmd) {
        case 1:
            std::cout << "Input file path: ";
            std::getchar();
            std::getline(std::cin, file_path_full);
            std::cout << file_format(file_path_full) << std::endl;
            break;

        case 2:
            std::cout << "Input file path: ";
            std::getchar();
            std::getline(std::cin, file_path_full);
            std::cout << file_name(file_path_full) << std::endl;
            break;
        case 3:
            std::cout << "Input file path: ";
            std::getchar();
            std::getline(std::cin, file_path_full);
            std::cout << file_path(file_path_full) << std::endl;
            break;
        case 4:
            std::cout << "Input file path: ";
            std::getchar();
            std::getline(std::cin, file_path_full);
            std::cout << file_disk(file_path_full) << std::endl;
            break;
        case 5:
            std::cout << "Input file path: ";
            std::getchar();
            std::getline(std::cin, file_path_full);
            file_rename(&file_path_full);
            std::cout << file_path_full << std::endl;
            break;
        case 6:
            std::cout << "Input file path: ";
            std::getchar();
            std::getline(std::cin, file_path_full);
            file_copy(file_path_full);
            break;

        case 7:
            return 0;
        }
    }
}

