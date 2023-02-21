#include "stdafx.h"
#include "FileManager/FileManager.h"

/// <summary>
/// The FileManager is used to read/write user code to from/to a file
/// </summary>
/// <version>
/// 0.1
/// </version>
/// <author>
/// Traae Bloxham, transpiled and updated by Braydon Spaulding
/// </author>

FileManager* FileManager::getInstance() {
	if (instance == nullptr) {
		FileManager::instance = new FileManager;
	}

	return instance;
}

FileManager::FileManager() : lastErrorMessage("No current error") {}


/// <summary>
/// Check if a file exists at the given path.
/// </summary>
/// <param name="pathString">The path to the file.</param>
/// <returns>True if the file exists, false otherwise.</returns>
bool FileManager::checkFile(std::string pathString) {
	std::ifstream file(pathString);

	if (file.is_open()) {
		if (file.good()) {
			return true;
		}
		file.close();
	}
	return false;
};


/// <summary>
/// Read the contents of a file from the given path and return it as a string. The contents are converted to lowercase.
/// </summary>
/// <param name="path">The path to the file</param>
/// <returns>The contents of the file as a string</returns>
std::string FileManager::readFile(const std::string& path) {
	std::string text;
	std::string line;

	try {
		std::ifstream input_file(path);
		if (input_file.is_open()) {
			while (getline(input_file, line)) {
				text += line;
			}
			input_file.close();
		}
	}
	catch (const std::exception& e) {
		lastErrorMessage = "File Manager: in readFile()\n " + std::string(e.what());
	}

	for (auto& c : text) {
		c = std::tolower(c);
	}

	return text;
};

/// <summary>
/// Write the given content to a file at the given path. If the file already exists, it is overwritten. 
/// </summary>
/// <param name="path">The path to the file to write</param>
/// <param name="content">The content to write to the file</param>
/// <returns>True if the write operation was successful, false otherwise</returns>
bool FileManager::writeFile(const std::string& path, const std::string& content) {
	bool result = false;
	try {
		std::remove(path.c_str());
		std::ofstream output_file(path);
		result = true;


		if (result) {
			output_file << content;
		}

		output_file.close();

	}
	catch (const std::exception& e) {
		lastErrorMessage = "File Manager: in saveFile()\n" + std::string(e.what());
	}

	return result;
};

/// <summary>
/// Get the last error message generated by a FileManager operation.
/// </summary>
/// <returns>The last error message</returns>
std::string FileManager::getLastErrorMessage() {
	return lastErrorMessage;
};