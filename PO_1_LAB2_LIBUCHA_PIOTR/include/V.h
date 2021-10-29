#include <string>
///Klasa reprezentująca wektor
class V
{
public:
	/** Konstruktor tworzący wektor o wymiarze równym size
	* @param size wymiar wektora
	*/
	explicit V(unsigned size);

	/** Konstruktor kopiujący
	* @param other obiekt do skopiowania
	*/
	V(const V& other);

	/** Konstruktor przenoszący
	* @param other obiekt "do recyklingu"
	*/
	V(V&& other);

	/** Metoda zwracająca referencję na wartość wektora w wymiarze o numerze index
	* @param index wymiar
	* @return wartość wektora w wymiarze index;
	*/
	double& at(unsigned index) const;

	/** Metoda wypisująca wektor. Przed wektorem wypisywany jest tekst str.
	* @param str tekst do wypisania przed wektorem
	*/
	void print(std::string str) const;

	/** Metoda zwracająca iloczyn skalarny dwóch wektorów
	* @param v1 pierwszy z wektrów iloczynu
	* @param v1 drógi z wektorów iloczynu
	* @return iloczyn skalarny v1 i v2
	*/
	static double dot(const V& v1, const V& v2);

	///Operator konwertujący V na double. Wartość po konwersji taka jak po wywołaniu metody norm().
	operator double() const;

	/** Metoda zwracająca normę wektora
	* @return norma wektora
	*/
	double norm() const;

	/** Metoda zwracająca sumę dwóch wektorów
	* @param v1 pierwszy z wektrów sumy
	* @param v1 drógi z wektorów sumy
	* @return suma v1 i v2
	*/
	static V sum(const V& v1, const V& v2);

	/** Metoda zwracająca sumę wektora v1 i wektora, którego wartości w każdym wymiarze są równe liczbie number
	* @param v1 pierwszy z wektorów sumy
	* @param number liczba, która ma być wartościami drugiego wektora
	* @return suma v1 i (number, number, ... , number)
	*/
	static V sum(const V& v1, double number);

	~V();
private:
	///Wymiar wektora
	unsigned _size = 0;
	///Wartości wektora
	double* _values = nullptr;
};