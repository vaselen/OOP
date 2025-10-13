#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/base_object.hpp>

class vasuikova_Teacher {
protected:
    std::wstring name;
    int age;
    std::wstring danceStyle;

    friend class boost::serialization::access;

public:
    vasuikova_Teacher(): name(L""), age(0), danceStyle(L"") {}
    vasuikova_Teacher(std::wstring& name, int age, std::wstring& danceStyle);

    virtual ~vasuikova_Teacher();

    virtual void readFromConsole();
    virtual void displayToConsole() const;

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& name;
        ar& age;
        ar& danceStyle;
    }
};

BOOST_CLASS_EXPORT_KEY(vasuikova_Teacher)

