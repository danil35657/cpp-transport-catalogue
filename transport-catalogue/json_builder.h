#pragma once
#include <vector>
#include "json.h"


namespace json {
    
    using namespace std::literals;
    
    class BaseContext;
    class DictValueContext;
    class DictItemContext;
    class ArrayItemContext;

    class Builder {
    public:
        Builder();

        Node Build() const;

        template<typename ValueType>
        BaseContext Value(const ValueType & value);

        DictValueContext Key(const std::string & key);
        DictItemContext StartDict();
        BaseContext EndDict();
        ArrayItemContext StartArray();
        BaseContext EndArray();

    private:
        bool on_top() const;
        bool in_array() const;
        bool in_dict() const;

        Node root_;
        std::vector<Node*> nodes_stack_;
        std::string last_key_;
        bool have_key_ = false;
    };


    class BaseContext {
    public:
        BaseContext(Builder* builder) : builder_(builder) {}

        Node Build();

        template<typename ValueType>
        BaseContext Value(const ValueType& value);

        DictValueContext Key(const std::string& key);
        DictItemContext StartDict();
        BaseContext EndDict();
        ArrayItemContext StartArray();
        BaseContext EndArray();

    protected:
        Builder* builder_;
    };


    class DictValueContext: public BaseContext {
    public:
        DictValueContext(Builder* builder): BaseContext(builder) {}

        Node Build() = delete;

        template<typename ValueType>
        DictItemContext Value(const ValueType& value);

        DictValueContext Key(const std::string& key) = delete;
        BaseContext EndArray() = delete;
        BaseContext EndDict() = delete;
    };


    class DictItemContext: public BaseContext {
    public:
        DictItemContext(Builder* builder): BaseContext(builder) {}

        Node Build() = delete;

        template<typename ValueType>
        BaseContext Value(const ValueType& value) = delete;
        
        DictItemContext StartDict() = delete;
        ArrayItemContext StartArray() = delete;
        BaseContext EndArray() = delete;
    };


    class ArrayItemContext: public BaseContext {
    public:
        ArrayItemContext(Builder* builder): BaseContext(builder) {}

        Node Build() = delete;

        template<typename ValueType>
        ArrayItemContext Value(const ValueType& value);

        DictValueContext Key(const std::string& key) = delete;
        BaseContext EndDict() = delete;
    };


    template<typename ValueType>
    inline BaseContext Builder::Value(const ValueType& value) {
        if (in_array()) {
            Array& arr = const_cast<Array&>(nodes_stack_.back()->AsArray());
            arr.push_back(value);
        } else if (in_dict()) {
            Dict& dic = const_cast<Dict&>(nodes_stack_.back()->AsMap());
            dic[last_key_] = value;
            last_key_.clear();
        } else if (on_top()) {
            root_ = value;
        } else {
            throw std::logic_error("Logic error"s);
        }
        return BaseContext(this);
    }

    template<typename ValueType>
    inline BaseContext BaseContext::Value(const ValueType& value) {
        return builder_->Value(value);
    }

    template<typename ValueType>
    inline DictItemContext DictValueContext::Value(const ValueType& value) {
        builder_->Value(value);
        return DictItemContext(builder_);
    }

    template<typename ValueType>
    inline ArrayItemContext ArrayItemContext::Value(const ValueType& value) {
        builder_->Value(value);
        return ArrayItemContext(builder_);
    }
}
