#include "json.h"

using namespace std;

namespace json {
    
Node::Node(Value val) : value_(val) {}

Node::Node(std::nullptr_t) : value_(nullptr) {}
    
Node::Node(bool val) : value_(val) {}

Node::Node(int val) : value_(val) {} 

Node::Node(double val) : value_(val) {} 

Node::Node(std::string str) : value_(str) {}

Node::Node(Array arr) : value_(arr) {} 

Node::Node(Dict dic) : value_(dic) {} 


bool Node::IsInt() const {
    return std::holds_alternative<int>(value_) ? true : false;
}

bool Node::IsDouble() const {
    return std::holds_alternative<int>(value_) || std::holds_alternative<double>(value_) ? true : false;
} //Возвращает true, если в Node хранится int либо double.

bool Node::IsPureDouble() const {
    return std::holds_alternative<double>(value_) ? true : false;
} //Возвращает true, если в Node хранится double.

bool Node::IsBool() const {
    return std::holds_alternative<bool>(value_) ? true : false;
}

bool Node::IsString() const {
    return std::holds_alternative<std::string>(value_) ? true : false;
}

bool Node::IsNull() const {
    return std::holds_alternative<std::nullptr_t>(value_) ? true : false;
}

bool Node::IsArray() const {
    return std::holds_alternative<Array>(value_) ? true : false;
}

bool Node::IsMap() const {
    return std::holds_alternative<Dict>(value_) ? true : false;
}

int Node::AsInt() const {
    if (std::holds_alternative<int>(value_)) {
        return std::get<int>(value_);
    }
    throw std::logic_error("incorrect type"s);
}

bool Node::AsBool() const{
    if (std::holds_alternative<bool>(value_)) {
        return std::get<bool>(value_);
    }
    throw std::logic_error("incorrect type"s);
}

double Node::AsDouble() const {
    if (std::holds_alternative<int>(value_)) {
        return double(std::get<int>(value_));
    }
    if (std::holds_alternative<double>(value_)) {
        return std::get<double>(value_);
    }
    throw std::logic_error("incorrect type"s);
}

const std::string& Node::AsString() const {
    if (std::holds_alternative<std::string>(value_)) {
        return std::get<std::string>(value_);
    }
    throw std::logic_error("incorrect type"s);
}

const Array& Node::AsArray() const {
    if (std::holds_alternative<Array>(value_)) {
        return std::get<Array>(value_);
    }
    throw std::logic_error("incorrect type"s);
}

const Dict& Node::AsMap() const {
    if (std::holds_alternative<Dict>(value_)) {
        return std::get<Dict>(value_);
    }
    throw std::logic_error("incorrect type"s);
}

const Node::Value& Node::GetValue() const { return value_; }

bool operator==(Node left, Node right) {
    return left.GetValue() == right.GetValue();
}

bool operator!=(Node left, Node right) {
    return !(left == right);
}

Document::Document(Node root)
    : root_(move(root)) {
}

const Node& Document::GetRoot() const {
    return root_;
}

bool operator==(Document left, Document right) {
    return left.GetRoot() == right.GetRoot();
}

bool operator!=(Document left, Document right) {
    return !(left == right);
}

Node LoadNode(istream& input);

Document Load(istream& input) {
    return Document{LoadNode(input)};
}

Node LoadArray(istream& input) {
    Array result;
    
    if (!input) {
        throw ParsingError("Array parsing error");
    }
    
    char c;
    
    while (input >> c) {
        if (c == ']') {
            break;
        }
        if (c != ',') {
            input.putback(c);
        }
        result.push_back(LoadNode(input));
    }
    
    if (c != ']') {
        throw ParsingError("Array parsing error");
    }

    return Node(move(result));
}

Node LoadNumber(std::istream& input) {
    using namespace std::literals;

    std::string parsed_num;

    // Считывает в parsed_num очередной символ из input
    auto read_char = [&parsed_num, &input] {
        parsed_num += static_cast<char>(input.get());
        if (!input) {
            throw ParsingError("Failed to read number from stream"s);
        }
    };

    // Считывает одну или более цифр в parsed_num из input
    auto read_digits = [&input, read_char] {
        if (!std::isdigit(input.peek())) {
            throw ParsingError("A digit is expected"s);
        }
        while (std::isdigit(input.peek())) {
            read_char();
        }
    };

    if (input.peek() == '-') {
        read_char();
    }
    // Парсим целую часть числа
    if (input.peek() == '0') {
        read_char();
        // После 0 в JSON не могут идти другие цифры
    } else {
        read_digits();
    }

    bool is_int = true;
    // Парсим дробную часть числа
    if (input.peek() == '.') {
        read_char();
        read_digits();
        is_int = false;
    }

    // Парсим экспоненциальную часть числа
    if (int ch = input.peek(); ch == 'e' || ch == 'E') {
        read_char();
        if (ch = input.peek(); ch == '+' || ch == '-') {
            read_char();
        }
        read_digits();
        is_int = false;
    }

    try {
        if (is_int) {
            // Сначала пробуем преобразовать строку в int
            try {
                return Node(std::stoi(parsed_num));
            } catch (...) {
                // В случае неудачи, например, при переполнении,
                // код ниже попробует преобразовать строку в double
            }
        }
        return Node(std::stod(parsed_num));
    } catch (...) {
        throw ParsingError("Failed to convert "s + parsed_num + " to number"s);
    }
}

Node LoadString(std::istream& input) {
    using namespace std::literals;
    
    auto it = std::istreambuf_iterator<char>(input);
    auto end = std::istreambuf_iterator<char>();
    std::string s;
    while (true) {
        if (it == end) {
            // Поток закончился до того, как встретили закрывающую кавычку?
            throw ParsingError("String parsing error");
        }
        const char ch = *it;
        if (ch == '"') {
            // Встретили закрывающую кавычку
            ++it;
            break;
        } else if (ch == '\\') {
            // Встретили начало escape-последовательности
            ++it;
            if (it == end) {
                // Поток завершился сразу после символа обратной косой черты
                throw ParsingError("String parsing error");
            }
            const char escaped_char = *(it);
            // Обрабатываем одну из последовательностей: \\, \n, \t, \r, \"
            switch (escaped_char) {
                case 'n':
                    s.push_back('\n');
                    break;
                case 't':
                    s.push_back('\t');
                    break;
                case 'r':
                    s.push_back('\r');
                    break;
                case '"':
                    s.push_back('"');
                    break;
                case '\\':
                    s.push_back('\\');
                    break;
                default:
                    // Встретили неизвестную escape-последовательность
                    throw ParsingError("Unrecognized escape sequence \\"s + escaped_char);
            }
        } else if (ch == '\n' || ch == '\r') {
            // Строковый литерал внутри- JSON не может прерываться символами \r или \n
            throw ParsingError("Unexpected end of line"s);
        } else {
            // Просто считываем очередной символ и помещаем его в результирующую строку
            s.push_back(ch);
        }
        ++it;
    }

    return Node(s);
}

Node LoadDict(istream& input) {
    
     Dict result;
    
    if (!input) {
        throw ParsingError("Map parsing error");
    }
    
    char c;
    
    while (input >> c) {
        
        if (c == '}') {
            break;
        }
        
        if (c == ',') {
            input >> c;
        }

        string key = LoadString(input).AsString();
        input >> c;
        result.insert({move(key), LoadNode(input)});
    }
    
    if (c != '}') {
        throw ParsingError("Map parsing error");
    }

    return Node(move(result));
}

Node LoadTrue(istream& input) {
    string s = "true"s;
    string in;
    for (size_t i = 0; i < s.size(); ++i) {
        in += input.get();
    }
    if(s != in) {
        throw ParsingError("Bool parsing error");
    }
    return Node(true);
}

Node LoadFalse(istream& input) {
    string s = "false"s;
    string in;
    for (size_t i = 0; i < s.size(); ++i) {
        in += input.get();
    }
    if(s != in) {
        throw ParsingError("Bool parsing error");
    }
    return Node(false);
}

Node LoadNull(istream& input) {
    string s = "null"s;
    string in;
    for (size_t i = 0; i < s.size(); ++i) {
        in += input.get();
    }
    if(s != in) {
        throw ParsingError("Null parsing error");
    }
    return Node();
}

Node LoadNode(istream& input) {

    char c;
    input >> c;
    int num = int(c);

    if (c == '[') {
        return LoadArray(input);
    } else if (c == '{') {
        return LoadDict(input);
    } else if (c == '"') {
        return LoadString(input);
    } else if (c == '-' || (num >= 48 && num <= 57)) {
        input.putback(c);
        return LoadNumber(input);
    } else if (c == 't') {
        input.putback(c);
        return LoadTrue(input);
    } else if (c == 'f') {
        input.putback(c);
        return LoadFalse(input);
    } else if (c == 'n') {
        input.putback(c);
        return LoadNull(input);
    } else {
        throw ParsingError("Parsing error");
    }
}

void PrintNode(const Node& node, std::ostream& out);

template <typename Value>
void PrintValue(const Value& value, std::ostream& out) {
    out << value;
}

void PrintValue(const std::string& s, std::ostream& out) {
    out << '"';
    
    for(const char c : s) {
        switch (c) { 
        case '\r': 
            out << "\\r"sv; 
            break; 
        case '\n':
            out << "\\n"sv; 
            break;
        case '\"':
            out << "\\\""sv; 
            break;
        case '\t':
            out << "\\t"sv; 
            break;
        case '\\':
            out << "\\\\"sv; 
            break;
        default:
            out << c;
        }
    }
    
    out << '"';
}

void PrintValue(const bool x, std::ostream& out) {
    out << std::boolalpha << x;
}

void PrintValue(std::nullptr_t, std::ostream& out) {
    out << "null"sv;
}

void PrintValue(const Array& arr, std::ostream& out) {
    out << '[';
    if (arr.size() > 0) {
        PrintNode(arr[0], out);
        if (arr.size() > 1) {
            for (size_t i = 1; i < arr.size(); ++i) {
                out << ", "sv;
                PrintNode(arr[i], out);
            }
        }
    }
    out << ']';
}

void PrintValue(const Dict& dic, std::ostream& out) {
    out << '{';
    auto it = dic.begin();
    if (it != dic.end()) {
        out << "\""s << it->first << "\": "sv;
        PrintNode(it->second, out);
        ++it;
        while (it != dic.end()) {
            out << ", \""s << it->first << "\": "sv;
            PrintNode(it->second, out);
            ++it;
        }
    }
    out << '}';
}

void PrintNode(const Node& node, std::ostream& out) {
    std::visit(
        [&out](const auto& value){ PrintValue(value, out); },
        node.GetValue());
}

void Print(const Document& doc, std::ostream& output) {
    PrintNode(doc.GetRoot(), output);
}

}  // namespace json