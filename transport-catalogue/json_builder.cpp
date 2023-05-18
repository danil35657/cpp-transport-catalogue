#include "json_builder.h"

namespace json {

Builder::Builder() {}

Node Builder::Build() const {
    if (on_top()) {
        return root_;
    } else {
        throw std::logic_error("Logic error");
    }
}

DictValueContext Builder::Key(const std::string& key) {
    if (in_dict()) {
        last_key_ = key;
    } else {
        throw std::logic_error("Logic error");
    }
    return DictValueContext(this);
}

DictItemContext Builder::StartDict() {
    if (in_array()) {
        Array& arr = const_cast<Array&>(nodes_stack_.back()->AsArray());
        arr.push_back(Dict());
        nodes_stack_.push_back(&arr.back());
    } else if (in_dict()) {
        Dict& dic = const_cast<Dict&>(nodes_stack_.back()->AsMap());
        dic[last_key_] = Dict();
        nodes_stack_.push_back(&dic[last_key_]);
    } else if (on_top()) {
        root_ = Dict();
        nodes_stack_.push_back(&root_);
    } else {
        throw std::logic_error("Logic error");
    }
    return DictItemContext(this);
}

BaseContext Builder::EndDict() {
    if (in_dict()) {
        nodes_stack_.pop_back();
    } else {
        throw std::logic_error("Logic error");
    }
    return BaseContext(this);
}

ArrayItemContext Builder::StartArray() {
    if (in_array()) {
        Array& arr = const_cast<Array&>(nodes_stack_.back()->AsArray());
        arr.push_back(Array());
        nodes_stack_.push_back(&arr.back());
    } else if (in_dict()) {
        Dict& dic = const_cast<Dict&>(nodes_stack_.back()->AsMap());
        dic[last_key_] = Array();
        nodes_stack_.push_back(&dic[last_key_]);
    } else if (on_top()) {
        root_ = Array();
        nodes_stack_.push_back(&root_);
    } else {
        throw std::logic_error("Logic error");
    }
    return json::ArrayItemContext(this);
}

BaseContext Builder::EndArray() {
    if (in_array()) {
        nodes_stack_.pop_back();
    } else {
        throw std::logic_error("Logic error");
    }
    return json::BaseContext(this);
}

bool Builder::on_top() const {
    return nodes_stack_.empty();
}

bool Builder::in_array() const {
    if (!nodes_stack_.empty()) {
        if (nodes_stack_.back()->IsArray()) {
            return true;
        }
    }
    return false;
}

bool Builder::in_dict() const {
    if (!nodes_stack_.empty()) {
        if (nodes_stack_.back()->IsMap()) {
            return true;
        }
    }
    return false;
}

Node BaseContext::Build() {
    return builder_->Build();
}

DictValueContext BaseContext::Key(const std::string& key) {
    return builder_->Key(key);
}

DictItemContext BaseContext::StartDict() {
    return builder_->StartDict();
}

BaseContext BaseContext::EndDict() {
    return builder_->EndDict();
}

ArrayItemContext BaseContext::StartArray() {
    return builder_->StartArray();
}

BaseContext BaseContext::EndArray() {
    return builder_->EndArray();
}

}
