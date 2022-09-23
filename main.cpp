#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

// ф-я для отображение контейнера

template <typename T>
void printContainer(T rangeBegin, T rangeEnd) {
    for(auto it = rangeBegin; it!=rangeEnd; ++it) {
        std::cout << *it << ", ";
    }
    std::cout<<std::endl;
}

//  задание 1
//  Напишите функцию PrintVectorPart, принимающую вектор целых чисел numbers,
//  выполняющую поиск первого отрицательного числа в нём и выводящую в стандартный вывод все числа,
//	расположенные левее найденного, в обратном порядке.
//  Если вектор не содержит отрицательных чисел, выведите все числа в обратном порядке.

void PrintVectorPart(const std::vector<int>& numbers) {
    auto it = find_if(begin(numbers),end(numbers),[](const int& n){
        return n<0;
    });
    while (it != numbers.begin()) {
            --it;
            std::cout << *it << ' ';
        }
}

// задание 2
//    Напишите функцию PrintVectorPart, принимающую вектор целых чисел numbers,
//    выполняющую поиск первого отрицательного числа в нём и выводящую в стандартный вывод все числа,
//	  расположенные левее найденного, в обратном порядке.
//    Если вектор не содержит отрицательных чисел, выведите все числа в обратном порядке.
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

    return 0;
}
