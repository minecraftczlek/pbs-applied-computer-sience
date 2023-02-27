# 1
Napisz program, którzy zwróci w wyniku odwrócony zapis 'hello.py'. Spodziewany wynik to: '.py hello'
# 2
Napisz program, który przekonwertuje liczbę całkowitą na rzymską
# 3
Napisz program, który zwróci wszystkie możliwe unikalne podzbiory, z zestawu różnych liczb całkowitych.
# 4
Napisz program, który będzie znajdować parę elementów (indeksy dwóch liczb) z danej tablicy, a których suma będzie równa określonej liczbie docelowej (sam dobierz jej wartość).
# 5
Zdefiniuj klasę o nazwie „Songs”, w której zawrzesz jej treść. Wykorzystaj metodę __init__(), która powinna zawierać dwa argumenty: self i lyrics. Wewnątrz klasy utwórz metodę sing_me, która będzie zwracać każdy wers piosenki w jednej linii. Zdefiniuj następującą zmienną:
# 6
Przeanalizować w jakiej kolejności następowało sortowanie?  
2z1, 3z2, 3z2, 3z4, 4z1, 4z2, 5z1, 5z2  
Jest to połączenie techniki sortowania przez wstawianie i sortowanie przez scalanie  
Zaimplementować __eq__() i __ne__(), tak aby porównać zarówno imiona, jak i wiek
Zdefiniować __lt__() tak, aby najpierw posortować listę po imieniu, a następnie jeżeli imię będzie takie same to po wieku
# dom1
- utwórz klasę o nazwie „Triangle”. Jego metoda powinna zawierać argumenty: self, angle1, 
angle2, angle3 
- upewnij się, że prawidłowo zdefiniowałeś je w ciele metody 
- utwórz zmienną o nazwie „number_of_sides” i ustaw jej wartość 3 
- utwórz metodę „check_angles”, która będzie sprawdzać wartości kątów. Jeśli suma kątów będzie 
równa 180 to zwróć True, w przeciwnym wypadku False 
- Utwórz zmienną „my_triangle” i ustaw eq dla klasy „Trójkąt”. Przekaż jej wartości twoich 
kątów, które sumują się do wartości 180 stopni 
- zwróć „my_triangle.number_of_sides()” i „my_triangle.check_angles()”
# dom2
- utwórz klasę o nazwie drink. Klasa ta reprezentuje drink lub jego składową. Klasa powinna 
zawierać pola: name, price (cena), percent (stężenie alkocholu), capacity 
- stwórz obiekty tej klasy, jako składowe pierwszego drinka:  
wódka, 40%, 8zł, 50ml  
rum, 60%, 9zł, 50ml  
cola, 0%, 2zł, 100ml  
lód, 0%, 0zł, 30ml  
- zaimplementuj operator +, tak aby suma dwóch drinków utworzyła nowy drink, z zastrzeżeniem: 
    - nazwa ma być złożeniem nazw składników z " z " pomiędzy 
    - cena i objętość to suma ceny i objętości składowych 
    - stężenie wyznaczone proporcjonalnie 
- dodaj do siebie składniki, tak, aby uzyskać obiekt drinka 
- zaimplementuj operator * tak, aby składnik pomnożony przez liczbę zwracał drink o 
odpowiednio pomnożonej objętości i cenie 
- zaimplementuj metodę str, aby można było czytelnie wyświetlać drink wraz z ceną objętością i 
stężeniem 
- zaproponuj własny zestaw składników i utworzyć z nich 2 kolejne drinki 
- zaimplementuj operator porównywania, tak, aby można było drinki posortować według stosunku 
stężenia do ceny (wybrać korzystny wariant na imprezę) 
- wszystkie utworzone drinki zapisz w liście i posortuj