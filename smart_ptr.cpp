#include <iostream>
#include <memory>

class Car {
	int _year;
	std::string _brand;
 public: 
	Car (int year, std::string brand) : _year{year}, _brand{brand} {}
	friend std::ostream& operator<<(std::ostream& os, const Car& c)
    {
        return os << "{ Car: y=" << c._year << ", b=" << c._brand << " }";
    }
}; 


class Cycle {
	int _year;
 public: 
	Cycle (int year) : _year{year} {}
	friend std::ostream& operator<<(std::ostream& os, const Cycle& c)
    {
        return os << "{ Cycle: y=" << c._year << " }";
    }
}; 

using  spCar = std::shared_ptr<Car>;
using  spCy = std::shared_ptr<Cycle>;

void ver_con_los_tres(spCy& sp1, spCy& sp2, spCy& sp3 ){
	std::cout << "-------------------------\n"; 
	std::cout << "[ver_con_los_tres] Cant de 1: " << sp1.use_count() << "\n"; 
	std::cout << "[ver_con_los_tres] Cant de 2: " << sp2.use_count() << "\n"; 
	std::cout << "[ver_con_los_tres] Cant de 3: " << sp3.use_count() << "\n"; 
}

int main (/* int argc, char* argv[] */) {
	
	// Unique /////////////////////////////////////////////////////
	std::unique_ptr<Car> up = std::make_unique<Car>(2011, "Uno");
	// std::shared_ptr<Car> copia_de_up = up; //No compila
	// std::unique_ptr<Car> copia_de_up = up; //No compila
	std::unique_ptr<Car> up2 = std::make_unique<Car>(2022, "Dos");
	std::unique_ptr<Car> up3 = std::make_unique<Car>(2033, "Tres");

	// Shared /////////////////////////////////////////////////////
	std::shared_ptr<Cycle> sp1 = std::make_shared<Cycle>(2003);
	std::cout << "Cant: " << sp1.use_count() << "\n"; 
	std::shared_ptr<Cycle> sp2 = sp1;
	std::cout << "Cant: " << sp1.use_count() << "\n"; 
	std::shared_ptr<Cycle> sp3 = sp2;

	ver_con_los_tres(sp1, sp2, sp3); 

	sp2 = nullptr; 
	ver_con_los_tres(sp1, sp2, sp3); 

	std::cout << "-------------------------\n";
	std::cout << "· Car sp1: " << *sp1 << "\n";
	std::cout << "· Car sp3: " << *sp3 << "\n";

	sp3 = std::make_shared<Cycle>(3333);
	ver_con_los_tres(sp1, sp2, sp3); 

	std::cout << "-------------------------\n";
	std::cout << "· Car sp1: " << *sp1 << "\n";
	std::cout << "· Car sp3: " << *sp3 << "\n";

	return 0; 
}
