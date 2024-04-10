#include <exception>
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

//Function prototypes
void CopyFileOrDirectory(const std::string& source, const std::string& destination);
void MoveFileOrDirectory(const std::string& source, const std::string& destination);
void DeleteFileOrDirectory(const std::string& filename);
void RenameFileOrDirectory(const std::string& old_name, const std::string& new_name);


int main(int argc, char* argv[]) {
  //Check for command-line arguments
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <command> <arguments>\n";
    return 1;
  }

  //Get command from command-line arguments
  std::string command = argv[1];

  //Process commands
  if (command == "copy") {
    if (argc != 4) {
      std::cerr << "Usage: " << argv[0] << " copy <source> <destination>\n";
      return 1;
    }
    CopyFileOrDirectory(argv[2], argv[3]);
  } else if (command == "move") {
    if (argc != 4) {
      std::cerr << "Usage: " << argv[0] << " move <source> <destination>\n";
      return 1;
    }
    MoveFileOrDirectory(argv[2], argv[3]);
  } else if (command == "delete") {
    if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " delete <filename>\n";
    return 1;
    }
    DeleteFileOrDirectory(argv[2]);
  } else if (command == "rename") {
    if (argc != 4) {
      std::cerr << "Usage: " << argv[0] << " rename <oldname> <newname>\n";
      return 1;
    }
    RenameFileOrDirectory(argv[2], argv[3]);
  } else {
    std::cerr << "Invalid command!\n";
    return 1;
  }

  return 0;
}


//Function to copy file or directory
void CopyFileOrDirectory(const std::string& source, const std::string& destination) {
 try {
   fs::copy(source, destination, std::filesystem::copy_options::recursive | std::filesystem::copy_options::overwrite_existing);
   std::cout << "Copied: " << source << " -> " << destination << std::endl;
 } catch (const std::exception& e) {
   std::cerr << "Error: " << e.what() << std::endl;
 } 
}

//Function to move file or directory
void MoveFileOrDirectory(const std::string& source, const std::string& destination) {
 try {
   fs::rename(source, destination);
   std::cout << "Moved: " << source << " -> " << destination << std::endl;
 } catch (const std::exception& e) {
   std::cerr << "Error: " << e.what() << std::endl;
 }
}

//Function to delete file or directory 
void DeleteFileOrDirectory(const std::string& filename) {
 try {
   fs::remove_all(filename);
   std::cout << "Deleted: " << filename << std::endl;
 } catch (const std::exception& e) {
   std::cerr << "Error: " << e.what() << std::endl;
 }
}

//Function to rename file or directory
void RenameFileOrDirectory(const std::string& old_name, const std::string& new_name) {
 try {
   fs::rename(old_name, new_name);
   std::cout << "Renamed: " << old_name << " -> " << new_name << std::endl;
 } catch (const std::exception& e) {
   std::cerr << "Error: " << e.what() << std::endl;
 }
}



