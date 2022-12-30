#include <iostream>
#include <vector>

class user {

  std::string name;
  int pin;

public:

  user(std::string name, int pin) {
    if (name != "" && pin != 0) {
      this -> name = name; this -> pin = pin;
    }
  }
  
  void set_name(std::string n) {
    this -> name = n;
  }

  void set_pin(int p) {
    this -> pin = p;
  }

  int get_pin() {
    return this -> pin;
  }

  std::string get_name() {
    return this -> name;
  }

  std::vector<user> create_user(user u, std::vector<user> users);
  
};

std::vector<user> user::create_user(user u, std::vector<user> users) {
  users.push_back(u);
  return users;
}

void list() {
  std::cout << "What would you like to do?\n\n";

  std::cout << "(A) - Create a new user\n";
  std::cout << "(B) - Delete a user\n";
  std::cout << "(C) - Log all users\n";
}

bool detect_not_null(std::string s, int i) {
  if (s != "" && i != 0)
    return true;
  else
    return false;
}

int main(int argc, char* argv[]) {
  std::vector<user> users = {};
  
  bool run = true;
  while (run) {
    char inp;
    std::cout << "Continue? : ";
    
    std::cin >> inp;
    
    std::string user_name = "";
    int user_pin = 0;

    if (inp == 'y') {
      std::cout << "Welcome to the m e p User System!\n";
      list();

      std::string s_name = "";
      int i_pin = 0;
      
      std::cin >> inp;
      switch (inp) {
      case 'A':
	std::cout << "Creating a new user:::\n";
	std::cout << "What is your name?: ";

	std::cin >> s_name;
	std::cout << "What shall your pin be?: ";

	std::cin >> i_pin;
	
	if (detect_not_null(s_name, i_pin)) {
	    user u(s_name, i_pin);
	    users = u.create_user(u, users);

	    std::cout << "Created new user: " << s_name << "\n";
	}

	else
	  std::cout << "The NAME or PIN you entered in was NULL.\n";
	  
	break;
      case 'B':

	std::cout << "Enter in the users name: ";
	std::cin >> user_name;

	std::cout << "Now enter in the users pin: ";
	std::cin >> user_pin;

	if (detect_not_null(user_name, user_pin)) {
	  int index = 0;
	  
	  for (user u : users) {
	    if (user_name == u.get_name() && user_pin == u.get_pin()) {
	      users.erase(users.begin() + index);
	      std::cout << "Removed user: " << user_name << "\n";
	      
	      break;
	    }
	    
	    index++;
	  }
	} 

	else
	  std::cout << "ERROR: Name or Pin is NULL.\n";
	
 	break;
      case 'C':
	char c = ' ';
	
	std::cout << "With pin or without? (y, n): ";
	std::cin >> c;
	
	std::cout << "Logging every user...\n\n";
	if (c == 'y') {
	  for (size_t i = 0; i < users.size(); i++) {
	    std::cout << i + 1 << ": " << users.at(i).get_name() << " | " << users.at(i).get_pin() << "\n"; 
	  }
	}

	else {
	  for (size_t i = 0; i < users.size(); i++) {
	    std::cout << i + 1 << ": " << users.at(i).get_name() << "\n";
	  }
	}
	
	break;
      }
    }

    else if (inp == 'n') {
      run = false;
    }
    
  }
  
  return 0;
}
