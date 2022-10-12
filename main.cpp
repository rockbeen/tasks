#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <list>
// ф-я для отображение контейнера

template <typename T>
void printContainer(T rangeBegin, T rangeEnd) {
    for(auto it = rangeBegin; it!=rangeEnd; ++it) {
        std::cout << *it << ", ";
    }
    std::cout<<std::endl;
}


void PrintVectorPart(const std::vector<int>& numbers) {
    auto it = find_if(begin(numbers),end(numbers),[](const int& n){
        return n<0;
    });
    while (it != numbers.begin()) {
            --it;
            std::cout << *it << ' ';
        }
}


template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border) {
    auto it = find_if(begin(elements),end(elements),[border](const T& n){
        return n > border;
    });
    return {it,end(elements)};

}

//задание 3
//Напишите функцию SplitIntoWords, разбивающую строку на слова по пробелам.

std::vector<std::string> SplitIntoWords(const std::string& String) {
    auto itBeginWord = begin(String);
    std::vector<std::string> words;
    while(itBeginWord != String.end()){
        auto itWord = find_if(itBeginWord,end(String),[](const char& letter){
            return (letter == ' ');
        });
        // если начало и конец совпадают, то это не слово
        if (itWord != itBeginWord) {
            words.push_back({ itBeginWord, itWord });
        }
        if (itWord != String.end()) {
            itBeginWord = itWord;
            ++itBeginWord;
        }
        else itBeginWord = itWord;

    }
    return words;
}

//задание 4
template <typename T>
void RemoveDuplicates(std::vector<T>& elements) {
    std::sort(elements.begin(), elements.end());

    auto it = std::unique(elements.begin(), elements.end());
    elements.erase(it, elements.end());
}

//задание 5

void Permutations(int n) {
    std::vector<int> vecNumbers;
    vecNumbers.reserve(n);
    do{
        vecNumbers.push_back(n);
        --n;
    } while(n > 0);

    do
    {
        printContainer(std::begin(vecNumbers), std::end(vecNumbers));
    } while (std::prev_permutation(std::begin(vecNumbers), std::end(vecNumbers)));

}

int main()
{
//проверка работоспособности заданий:

//    //  задание 1
//    PrintVectorPart({6, 1, 8, -5, 4});
//    std::cout << std::endl;
//    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
//    std::cout << std::endl;
//    PrintVectorPart({6, 1, 8, 5, 4});
//    std::cout << std::endl;

//     //   задание 2
//    for (int x : FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5)) {
//      std::cout << x << " ";
//    }
//    std::cout << std::endl;
//    std::string to_find = "Python";
//    std:: cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;
//    return 0;

//    //  задание 3 (Напишите функцию SplitIntoWords, разбивающую строку на слова по пробелам.)
//    std::string s = "C Cpp Java Python";

//    std::vector<std::string> words = SplitIntoWords(s);
//    printContainer(words.begin(),words.end());

      //задание 4 (Напишите шаблонную функцию RemoveDuplicates, принимающую по ссылке вектор elements объектов типа T и удаляющую из него все дубликаты элементов. Порядок оставшихся элементов может быть любым.
      //           Гарантируется, что объекты типа T можно сравнивать с помощью операторов ==, !=, < и >.)
//    std::vector<int> v1 = { 6, 4, 7, 6, 4, 4, 0, 1 };
//    RemoveDuplicates(v1);
//    for (int x : v1) {
//        std::cout << x << " ";
//    }
//    std::cout << std::endl;

//    std::vector<std::string> v2 = { "C", "C++", "C++", "C", "C++" };
//    RemoveDuplicates(v2);
//    for (const std::string& s : v2) {
//        std::cout << s << " ";
//    }
//    std::cout << std::endl;


    //задание 5 (Дано целое положительное число N, не превышающее 9. Выведите все перестановки чисел от 1 до N в обратном лексикографическом порядке)

//    Permutations(3);
//    Permutations(4);


    return 0;
}
