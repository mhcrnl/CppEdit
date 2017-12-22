#pragma once

#include <string>

class FileUtils {
public:
	static std::string fileContent(std::string path);
	static std::string fileName(std::string path);
};
