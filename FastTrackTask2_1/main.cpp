//
// Created by Софья on 21.04.2024.
//
#include <iostream>
#include <vector>
#include <memory>
#include <variant>
#include <unordered_map>

// (1 + 2) * 3 / 4 + 5 * (6 - 7)

// 1. Токенизация
// 2. Парсер (построение дерева разбора выражения)

// +, -, *, /, %

struct OpeningBracket {};

struct ClosingBracket {};

struct Number {
    int value;
};

struct UnknownToken {
    std::string value;
};

struct MinToken {};
//1. Дополнить решение токенами: max, sqr - done
struct MaxToken {};

struct AbsToken {};

struct Plus {};

struct Minus {};

struct Multiply {};

struct Modulo {};

struct Divide {};

struct Sqrt{};

//2. Добавить все необходимые классы в определение Token - done
using Token = std::variant<OpeningBracket, ClosingBracket, Number,
                            UnknownToken, MinToken, MaxToken, AbsToken,
                            Plus, Minus,Multiply, Modulo,Divide, Sqrt>;

const std::unordered_map<char, Token> kSymbol2Token{
        {'+', Plus{}}, {'-', Minus{}}, {'*', Multiply{}},
        {'/', Divide{}}, {'%', Modulo{}}, {'(', OpeningBracket{}}, {')', ClosingBracket{}}
};

const std::unordered_map<std::string, Token> kWord2Token{
        {"sqrt", Sqrt{}}, {"min", MinToken{}},
        {"max", MaxToken{}}, {"abs", AbsToken{} }
};

int ToDigit(unsigned char symbol) {
    return symbol - '0';
}

//3. Реализовать ParseName, который читает последовательность
//      букв и возвращает токен соответствующей функции или UnknownToken
Token ParseName(const std::string& input, size_t& pos){
    std::string name;
    auto symbol = static_cast <unsigned char> (input[pos]);
    while (std::isalpha(symbol)) {
        name += symbol;
        if (pos == input.size() - 1) {
            break;
        }
        symbol = static_cast <unsigned char> (input[++pos]);
    }

    if (auto it = kWord2Token.find(name); it != kWord2Token.end()) {
        return  it->second ;
    }

    return UnknownToken{name};
}

Number ParseNumber(const std::string& input, size_t& pos) {
    int value = 0;
    auto symbol = static_cast<unsigned char>(input[pos]);
    while (std::isdigit(symbol)) {
        value = value * 10 + ToDigit(symbol);
        if (pos == input.size() - 1) {
            break;
        }
        symbol = static_cast<unsigned char>(input[++pos]);
    }
    return Number{value};
}

//4. Закончить Tokenize
std::vector<Token> Tokenize(const std::string& input) {
    std::vector<Token> tokens;
    const size_t size = input.size();
    size_t pos = 0;
    while (pos < size) {
        const auto symbol = static_cast<unsigned char>(input[pos]);
        if (std::isspace(symbol)) {
            std::cout << "space found" << std::endl;
            ++pos;
        } else if (std::isdigit(symbol)) {
            std::cout << "digit found" << std::endl;
            tokens.emplace_back(ParseNumber(input, pos));

        } else if (auto it = kSymbol2Token.find(symbol); it != kSymbol2Token.end()) {
            std::cout << "symbol found" << std::endl;
            tokens.emplace_back(it->second);

        } else if (std::isalpha(symbol)){
            std::cout << "words found" << std::endl;
            tokens.emplace_back(ParseName(input, pos));

        }
        else{
            ++pos;
        }

    }
    return tokens;
}

void PrintToken(const Token& token) {
    std::visit([](const auto& t) {
        using T = std::decay_t<decltype(t)>;
        if constexpr (std::is_same_v<T, OpeningBracket>) {
            std::cout << "(";
        } else if constexpr (std::is_same_v<T, ClosingBracket>) {
            std::cout << ")";
        } else if constexpr (std::is_same_v<T, Number>) {
            std::cout << t.value;
        } else if constexpr (std::is_same_v<T, UnknownToken>) {
            std::cout << t.value;
        } else if constexpr (std::is_same_v<T, MinToken>) {
            std::cout << "min";
        } else if constexpr (std::is_same_v<T, MaxToken>) {
            std::cout << "max";
        } else if constexpr (std::is_same_v<T, AbsToken>) {
            std::cout << "abs";
        } else if constexpr (std::is_same_v<T, Plus>) {
            std::cout << "+";
        } else if constexpr (std::is_same_v<T, Minus>) {
            std::cout << "-";
        } else if constexpr (std::is_same_v<T, Multiply>) {
            std::cout << "*";
        } else if constexpr (std::is_same_v<T, Divide>) {
            std::cout << "/";
        } else if constexpr (std::is_same_v<T, Modulo>) {
            std::cout << "%";
        } else if constexpr (std::is_same_v<T, Sqrt>) {
            std::cout << "sqrt";
        }
    }, token);
}

void PrintTokens(const std::vector<Token>& tokens) {
    for (const auto& token : tokens) {
        PrintToken(token);
        std::cout << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::string input = "(1 + 2) * 3 / 4 + 5 * (6 - 7) * sqrt(25) - abs(12-3)";
    std::cout << input << std::endl;
    std::vector<Token> tokens = Tokenize(input);
    std::cout << "tokenizing done" << std::endl;
    PrintTokens(tokens);
    return 0;
}