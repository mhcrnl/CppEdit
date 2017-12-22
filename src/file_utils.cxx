#include <fstream>
#include <iostream>

#include "file_utils.hh"

std::string FileUtils::fileContent(std::string path) {
	std::ifstream reader(path);
	std::string content = "";
	if (reader.is_open()) {
		std::string line = "";
		while (getline(reader,line)) {
			content+=line+"\n";
		}
		reader.close();
	}
	return content;
}

std::string FileUtils::fileName(std::string path) {
	std::string result = "";
	for (int i = 0; i<path.length(); i++) {
		if (path[i]=='/') {
			result = "";
			continue;
		} else {
			result+=path[i];
		}
	}
	return result;
}
