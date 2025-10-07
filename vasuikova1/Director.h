#pragma once
#include "Teacher.h"
#include <string>

class vasuikova_Director : public vasuikova_Teacher {
private:
	int work_experience;
	std::wstring phone_number;

	friend class boost::serialization::access;
public:
	vasuikova_Director();
	vasuikova_Director(std::wstring& name, int age, std::wstring& danceStyle, int work_experience, std::wstring& phone_number);

	void readFromConsole() override;
	void displayToConsole() const override;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& boost::serialization::base_object<vasuikova_Teacher>(*this);
		ar& work_experience;
		ar& phone_number;
	}	
};

BOOST_CLASS_EXPORT_KEY(vasuikova_Director)