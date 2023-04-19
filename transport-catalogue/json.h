#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <variant>

namespace json {

class Node;

using Dict = std::map<std::string, Node>;
using Array = std::vector<Node>;
using Number = std::variant<int, double>;


class ParsingError : public std::runtime_error {
public:
    using runtime_error::runtime_error;
};

class Node {
public:
    using Value = std::variant<std::nullptr_t, Array, Dict, bool, int, double, std::string>;
    
    Node() = default;

    Node(Value value);
    
    Node(std::nullptr_t);
    
    Node(bool val);
    
    Node(int val); 
    
    Node(double val);
    
    Node(std::string str);
    
    Node(Array arr);
    
    Node(Dict dic);
    
    bool IsInt() const;
    
    bool IsDouble() const; 
    
    bool IsPureDouble() const;
    
    bool IsBool() const;
    
    bool IsString() const;
    
    bool IsNull() const;
    
    bool IsArray() const;
    
    bool IsMap() const;
    
    int AsInt() const;
    
    bool AsBool() const;
    
    double AsDouble() const;
    
    const std::string& AsString() const;
    
    const Array& AsArray() const;
    
    const Dict& AsMap() const;

    const Value& GetValue() const;

private:
    Value value_;
};

bool operator==(Node left, Node right);

bool operator!=(Node left, Node right);

class Document {
public:
    explicit Document(Node root);

    const Node& GetRoot() const;

private:
    Node root_;
};

bool operator==(Document left, Document right);

bool operator!=(Document left, Document right);

Document Load(std::istream& input);

void Print(const Document& doc, std::ostream& output);

}